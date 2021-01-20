#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <syslog.h>
#include <string.h>
#include <errno.h>
#include <signal.h>

static FILE *fp;

int mydaemon_init()
{
	pid_t pid;
	int fd;

	pid = fork();
	if(pid < 0)
	{
		syslog(LOG_ERR,"fork():%s",strerror(errno));
		return -1;
	}

	if(pid > 0)
		exit(0);

	//child
	
	//close(0);
	//close(1);
	//close(2);

	//0->/tmp/in   1->/tmp/out    2->/tmp/err

	fd = open("/dev/null",O_RDWR);
	if(fd < 0)
	{
		syslog(LOG_WARNING,"open():%s",strerror(errno));
	}
	else
	{
		dup2(fd,0);
		dup2(fd,1);
		dup2(fd,2);
		if(fd > 2)
			close(fd);
	}

	setsid();

	chdir("/");
	umask(0);
	return 0;
}

void mydaemon_exit(int s)
{
	fclose(fp);
	closelog();
	exit(0);
}

int main()
{
	int i;
	struct sigaction sa;

//	signal(SIGINT,mydaemon_exit);
	/*if error*/
//	signal(SIGQUIT,mydaemon_exit);
	/*if error*/
//	signal(SIGTERM,mydaemon_exit);
	/*if error*/

	sa.sa_handler = mydaemon_exit;
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask,SIGQUIT);
	sigaddset(&sa.sa_mask,SIGINT);
	sigaddset(&sa.sa_mask,SIGTERM);
	sa.sa_flags = 0;

	if(sigaction(SIGINT,&sa,NULL) < 0)
	{
		perror("sigaction()");
		exit(1);
	}

	sigaction(SIGQUIT,&sa,NULL);
	/*if error*/

	sigaction(SIGTERM,&sa,NULL);
	/*if error*/





	openlog("mydaemon",LOG_PID,LOG_DAEMON);

	if(mydaemon_init())
	{
		syslog(LOG_ERR,"mydaemon_init() error.");
		exit(1);
	}
	else
		syslog(LOG_NOTICE,"mydaemon_init() succeed");

	/*do sth*/	

	fp = fopen("/tmp/mydaemon.log","w");
	if(fp == NULL)
	{
		syslog(LOG_ERR,"fopen():%s",strerror(errno));
		exit(1);
	}

	syslog(LOG_INFO,"%s was opened.","/tmp/mydaemon.log");

	for(i = 0 ; ; i++)
	{
		fprintf(fp,"%d\n",i);
		fflush(fp);

		syslog(LOG_DEBUG,"%d was printed.",i);

		sleep(1);
	}



	exit(0);
}



