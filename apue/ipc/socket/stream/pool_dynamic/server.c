#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <net/if.h>
#include <time.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <sys/mman.h>

#include "proto.h"

#define BUFSIZE		1024
#define IPSTRSIZE	1024

#define MAXCLIENT			20
#define MINSPARESERVERS		5
#define MAXSPARESERVERS		10


#define SIG_NOTIFY		SIGUSR2

enum
{
	STATE_IDLE=0,
	STATE_BUSY
};

struct server_st
{
	pid_t pid;
	int state;
};


static struct server_st *serverpool;
static int idle_count = 0,busy_count = 0;
static int sd;


void usr2_handler(int s)
{
	return ;
}


void server_job(int sd)
{
	char buf[BUFSIZE];
	int len;

	len = sprintf(buf,FMT_STAMP,(long long)time(NULL));

	sleep(5);

	if(send(sd,buf,len,0) < 0)
	{
		perror("send()");
		exit(1);
	}
}

void server_loop(int pos)
{
	int newsd;
	char ipstr[IPSTRSIZE];
	struct sockaddr_in raddr;
	socklen_t raddr_len;
	pid_t ppid;

	ppid = getppid();

	raddr_len = sizeof(raddr);
	while(1)
	{
		serverpool[pos].state = STATE_IDLE;
		kill(ppid,SIG_NOTIFY);

		newsd = accept(sd,(void *)&raddr,&raddr_len);
		if(newsd < 0)
		{
			perror("accept");
			exit(1);
		}

		serverpool[pos].state = STATE_BUSY;
		kill(ppid,SIG_NOTIFY);

		inet_ntop(AF_INET,&raddr.sin_addr,ipstr,IPSTRSIZE);
//		printf("----MESSAGE FROM:%s:%d----\n",ipstr,ntohs(raddr.sin_port));
		server_job(newsd);
		close(newsd);
	}
	close(sd);
}

int add_1_server(void)
{
	int pos;
	pid_t pid;

	if(idle_count + busy_count >= MAXCLIENT)
		return -1;

	for(pos = 0 ; pos < MAXCLIENT; pos++)
		if(serverpool[pos].pid == -1)
			break;

	serverpool[pos].state = STATE_IDLE;
	idle_count++;

	pid = fork();
	if(pid < 0)
	{
		perror("fork()");
		exit(1);
	}
	if(pid == 0)	// child
	{
		server_loop(pos);
		exit(0);	
	}
	else			//parent
	{
		serverpool[pos].pid = pid;
	}
	return 0;
}

int del_1_server()
{
	int i;

	if(idle_count <= 0)
		return -1;

	for(i = 0 ; i < MAXCLIENT; i++)
	{
		if(serverpool[i].pid != -1 && serverpool[i].state == STATE_IDLE)
		{
			kill(serverpool[i].pid, SIGTERM);
			serverpool[i].pid = -1;
			idle_count --;
			break;
		}
	}
	return 0;
}

void scan_pool()
{
	int idle = 0,busy = 0;
	int i;

	for(i = 0 ; i < MAXCLIENT; i++)
	{
		if(serverpool[i].pid == -1)
			continue;
		
		if(kill(serverpool[i].pid, 0))
		{
			serverpool[i].pid = -1;
			continue;
		}

		if(serverpool[i].state == STATE_IDLE)
			idle++;
		else
		{
			if(serverpool[i].state == STATE_BUSY)
				busy++;
			else
			{
				fprintf(stderr,"Unknown state.\n");
				abort();
			}
		}
	}
	
	idle_count = idle;
	busy_count = busy;

}

int main()
{
	int i;
	struct sockaddr_in laddr;
	pid_t pid;
	sigset_t set,oset;
	struct sigaction sa;


	//免去收尸困扰
	sa.sa_handler = SIG_IGN;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_NOCLDWAIT;
	sigaction(SIGCHLD,&sa,NULL);
	
	sa.sa_handler = usr2_handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sigaction(SIG_NOTIFY,&sa,NULL);
	/*if error*/

	sigemptyset(&set);
	sigaddset(&set,SIG_NOTIFY);
	sigprocmask(SIG_BLOCK,&set,&oset);


	serverpool = mmap(NULL,sizeof(struct server_st)*MAXCLIENT, PROT_READ|PROT_WRITE,MAP_SHARED|MAP_ANONYMOUS,-1,0);
	if(serverpool == MAP_FAILED)
	{
		perror("mmap()");
		exit(1);
	}

	for(i = 0 ; i < MAXCLIENT; i++)
		serverpool[i].pid = -1;


	sd = socket(AF_INET,SOCK_STREAM,0/*IPPROTO_TCP,IPPROTO_SCTP*/);
	if(sd < 0)
	{
		perror("socket()");
		exit(1);
	}

	int val = 1;
	if(setsockopt(sd,SOL_SOCKET,SO_REUSEADDR,&val,sizeof(val)) < 0)
	{
		perror("setsockopt()");
		exit(1);
	}

	laddr.sin_family = AF_INET;
	laddr.sin_port = htons(atoi(SERVERPORT));
	inet_pton(AF_INET,"0.0.0.0",&laddr.sin_addr);
	if(bind(sd,(void *)&laddr,sizeof(laddr)) < 0)
	{
		perror("bind()");
		exit(1);
	}

	if(listen(sd,200) < 0)
	{
		perror("listen");
		exit(1);
	}


	for(i = 0; i < MINSPARESERVERS; i++)
	{
		add_1_server();
	}


	while(1)
	{
		sigsuspend(&oset);

		scan_pool();

		if(idle_count > MAXSPARESERVERS)
		{
			for(i = 0 ; i < (idle_count-MAXSPARESERVERS); i++)
				del_1_server();

		}
		else
		{
			if(idle_count < MINSPARESERVERS)
			{
				for(i = 0 ; i < MINSPARESERVERS-idle_count; i++)
					add_1_server();
			}

		}


		for(i = 0 ; i < MAXCLIENT; i++)
		{
			if(serverpool[i].pid == -1)
				putchar(' ');
			else
			{
				if(serverpool[i].state == STATE_IDLE)
					putchar('.');
				else
					putchar('x');
			}

		}
		putchar('\n');
	}

	sigprocmask(SIG_SETMASK,&oset,NULL);

	exit(0);
}





