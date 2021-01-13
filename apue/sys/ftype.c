#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int ftype(const char *fname)
{
	struct stat statres;

	if(lstat(fname,&statres) < 0)
	{
		perror("statres()");
		exit(1);
	}
	
	if(S_ISREG(statres.st_mode))
		return '-';
	if(S_ISDIR(statres.st_mode))
		return 'd';
	else
		return '?';
}

int main(int argc,char *argv[])
{
	if(argc < 2)
	{
		printf("Usage:%s <filenmae>\n",argv[0]);
		exit(0);
	}

	printf("%c\n",ftype(argv[1]));
	

	exit(0);
}



