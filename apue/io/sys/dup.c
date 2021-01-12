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

	fd = open("/tmp/out",O_WRONLY|O_TRUNC|O_CREAT,0600);
	if(fd < 0)
	{
		perror("open()");
		exit(1);
	}

//	close(1);
//	dup(fd);

	dup2(fd,1);

	if(fd != 1)
		close(fd);

//--------------------------------------------
	puts("Hello!");

	exit(0);
}



