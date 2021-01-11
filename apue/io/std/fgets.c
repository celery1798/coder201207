#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define BUFSIZE	5

int main()
{
	FILE *fp;
	char buf[BUFSIZE];

	fp = fopen("myfile.txt","r");
	if(fp == NULL)
	{
		perror("fopen()");	
		exit(1);
	}

	fgets(buf,BUFSIZE,fp);

	puts(buf);

	fclose(fp);

	exit(0);
}



