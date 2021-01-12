#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

off_t flen(const char *fname)
{
	struct stat statres;

	if(stat(fname,&statres) < 0)
	{
		perror("statres()");
		exit(1);
	}
	
	return statres.st_size;	
}

int main(int argc,char *argv[])
{
	if(argc < 2)
	{
		printf("Usage:%s <filenmae>\n",argv[0]);
		exit(0);
	}

	printf("%ld\n",flen(argv[1]));
	

	exit(0);
}



