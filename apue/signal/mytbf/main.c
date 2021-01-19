#include <stdio.h>
#include <stdlib.h>

#include "mytbf.h"

#define BUFSIZE		1024	
#define BURST		100
#define CPS			10

int main(int argc,char *argv[])
{
	int sfd,dfd = 1,len,ret,pos;
	char buf[BUFSIZE];
	mytbf_t *tbf;

	if(argc < 2)
	{
		printf("Usage:%s <srcfile>\n",argv[0]);
		exit(1);	
	}

	tbf = mytbf_init(CPS,BURST);
	if()
	{
	
	}

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
		size = mytbf_fetchtoken(tbf,BUFSIZE);


		while((len = read(sfd,buf,size)) < 0)
		{
			if(errno == EINTR)
				continue;
			perror("read()");
			break;
		}
		if(len == 0)
			break;

		// len > 0

		if(size - len > 0)
			mytbf_returntoken(tbf,size-len);

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

	mytbf_destroy(tbf);

	exit(0);
}



