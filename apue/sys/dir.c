#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>


int main(int argc,char *argv[])
{
	DIR *dp;
	struct dirent *cur;

	if(argc < 2)
	{
		printf("Usage:%s <filenmae>\n",argv[0]);
		exit(0);
	}

	dp = opendir(argv[1]);
	if(dp == NULL)
	{
		perror("opendir()");
		exit(1);
	}

	while((cur = readdir(dp)) != NULL)
		puts(cur->d_name);

	closedir(dp);

	exit(0);
}



