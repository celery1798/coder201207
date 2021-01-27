#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <poll.h>

#define BUFSIZE	1024

#define TTY1	"/dev/tty11"
#define TTY2	"/dev/tty12"

enum
{
	STATE_R=1,
	STATE_W,
STATE_AUTO,
	STATE_Ex,
	STATE_T
};


struct fsm_st
{
	int state;
	int sfd,dfd;
	char buf[BUFSIZE];
	int len;
	int pos;
	char *errstr;
};

void driver(struct fsm_st *fsm)
{
	int ret;
	
	switch(fsm->state)
	{
		case STATE_R:
			fsm->len = read(fsm->sfd,fsm->buf,BUFSIZE);
			if(fsm->len == 0)
				fsm->state = STATE_T;
			else
			{
				if(fsm->len < 0)
				{
					if(errno == EAGAIN)
						fsm->state = STATE_R;
					else
					{	
						fsm->errstr = "read()";
						fsm->state = STATE_Ex;
					}
				}
				else  // fsm->len > 0
				{
					fsm->pos = 0;		
					fsm->state = STATE_W;
				}
			}
			break;
	
		case STATE_W:
			ret = write(fsm->dfd,fsm->buf+fsm->pos,fsm->len);
			if(ret < 0)
			{
				if(errno == EAGAIN)
					fsm->state = STATE_W;
				else
				{
					fsm->errstr = "write()";
					fsm->state = STATE_Ex;
				}
			}
			else
			{
				fsm->pos += ret;
				fsm->len -= ret;
				if(fsm->len == 0)
					fsm->state = STATE_R;
				else
					fsm->state = STATE_W;
			}
			break;
	
		case STATE_Ex:
			perror(fsm->errstr);
			fsm->state = STATE_T;
			break;
	
		case STATE_T:	
			//exit   _exit
			break;
	
		default:
			abort();
			break;
	
	}
}

int max(int a,int b)
{
	if(a > b)
		return a;
	return b;
}

void relay(int fd1,int fd2)
{
	struct fsm_st fsm12,fsm21;
	struct pollfd pfd[2];

	fsm12.state = STATE_R;
	fsm12.sfd = fd1;
	fsm12.dfd = fd2;

	fsm21.state = STATE_R;
	fsm21.sfd = fd2;
	fsm21.dfd = fd1;

	pfd[0].fd = fd1;
	pfd[1].fd = fd2;

	while(fsm12.state != STATE_T || fsm21.state != STATE_T)
	{
		//布置监视任务
		pfd[0].events = 0;
		if(fsm12.state == STATE_R)
			pfd[0].events |= POLLIN;
		if(fsm21.state == STATE_W)
			pfd[0].events |= POLLOUT;

		pfd[1].events = 0;
		if(fsm12.state == STATE_W)
			pfd[1].events |= POLLOUT;
		if(fsm21.state == STATE_R)
			pfd[1].events |= POLLIN;

		//监视 
		if(fsm12.state < STATE_AUTO || fsm21.state < STATE_AUTO)
		{
			while(poll(pfd,2,-1) < 0)
			{
				if(errno == EINTR)
					continue;
				perror("");
				exit(1);
			}
		}

		//查看监视结果
		if(pfd[0].revents & POLLIN || pfd[1].revents & POLLOUT || fsm12.state > STATE_AUTO)
			driver(&fsm12);
		if(pfd[1].revents & POLLIN || pfd[0].revents & POLLOUT || fsm21.state > STATE_AUTO)
			driver(&fsm21);
	}

}

int main(int argc,char *argv[])
{
	int fd1,fd2,len,ret,pos;
	char buf[BUFSIZE];

	fd1 = open(TTY1,O_RDWR|O_NONBLOCK);
	if(fd1 < 0)
	{
		perror("open()");
		exit(1);
	}
	write(fd1,"TTY1\n",5);

	fd2 = open(TTY2,O_RDWR|O_NONBLOCK);
	if(fd2 < 0)
	{
		perror("open()");
		exit(1);
	}
	write(fd2,"TTY2\n",5);

	relay(fd1,fd2);

	close(fd1);
	close(fd2);

	exit(0);
}



