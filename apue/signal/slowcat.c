#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>

#define BUFSIZE	10

static volatile int loop = 1;

void alrm_handler(int s)
{
	alarm(1);
	loop = 0;
}

int main(int argc,char *argv[])
{
	int sfd,dfd = 1,len,ret,pos;
	char buf[BUFSIZE];

	if(argc < 2)
	{
		printf("Usage:%s <srcfile>\n",argv[0]);
		exit(1);	
	}

	signal(SIGALRM,alrm_handler);
	alarm(1);

	do
	{
		sfd = open(argv[1],O_RDONLY);
		if(sfd < 0)
		{
			if(errno != EINTR)
			{
				perror("open()");
				exit(1);
			}
		}
	}while(sfd < 0);

	while(1)
	{
		while(loop)
			pause();
		loop = 1;

		len = read(sfd,buf,BUFSIZE);
		if(len < 0)
		{
			if(errno == EINTR)
				continue;
			perror("read()");
			break;
		}
		if(len == 0)
			break;

		// len > 0

		pos = 0;
		while(len > 0)
		{
			ret = write(dfd,buf+pos,len);
			if(ret < 0)
			{
				if(errno == EINTR)
					continue;
				perror("write()");
				exit(1);
			}
			pos += ret;
			len -= ret;
		}
	}

	close(sfd);

	exit(0);
}



