#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

ssize_t mygetline(char **lineptr, size_t *n, FILE *stream)
{


}


int main(int argc,char *argv[])
{
	FILE *fp;	
	char *line = NULL;
	size_t linesize = 0;

	if(argc < 2)
	{
		printf("Usage:%s <srcfile> \n",argv[0]);
		exit(1);	
	}

	fp = fopen(argv[1],"r");
	if(fp == NULL)
	{
		perror("fopen()");	
		exit(1);
	}

	while(1)
	{
		if(mygetline(&line, &linesize, fp) < 0)
			break;
		printf("linesize = %ld\n",linesize);	
		printf("%ld\n",strlen(line));	
	}

	fclose(fp);

	exit(0);
}



