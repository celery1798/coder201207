#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <fcntl.h>

#define BUFSIZE	1024



int main(int argc,char *argv[])
{
	int fd,i;
	char *str;
	struct stat statres;
	int count = 0;

	if(argc < 2)
	{
		printf("Usage:%s <srcfile>\n",argv[0]);
		exit(1);	
	}

	fd = open(argv[1],O_RDONLY);
	if(fd < 0)
	{
		perror("open()");
		exit(1);
	}

	if(fstat(fd,&statres) < 0)
	{
		perror("fstat()");
		exit(1);
	}
	

	str = mmap(NULL,statres.st_size,PROT_READ,MAP_SHARED,fd,0);
	if(str == MAP_FAILED)
	{
		perror("mmap()");
		exit(1);
	}

	close(fd);


	for(i = 0 ; i < statres.st_size ; i++)
		if(str[i] == 'a')
			count++;
	printf("%d\n",count);

	munmap(str,statres.st_size);

	exit(0);
}














