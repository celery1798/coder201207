#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc,char *argv[])
{
	int fd;

	if(argc < 2)
	{
		printf("Usage:%s <filenmae>\n",argv[0]);
		exit(0);
	}

	fd = open(argv[1],O_WRONLY|O_CREAT|O_TRUNC,0600);	
	if(fd < 0)
	{
		perror("open()");
		exit(1);	
	}
	
	lseek(fd,5LL*1024LL*1024LL*1024LL-1LL,SEEK_SET);
	write(fd,"",1);

	close(fd);

	exit(0);
}


