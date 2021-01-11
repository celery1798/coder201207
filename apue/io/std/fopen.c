#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

int main()
{
	FILE *fp;	

	fp = fopen("myfile.txt","w");
	if(fp == NULL)
	{
	//	printf("fopen() error!\n");
	//	printf("error = %d\n",errno);
		perror("fopen()");	
//		printf("fopen():%s\n",strerror(errno));
		exit(1);
	}

	printf("OK\n");

	fclose(fp);

	exit(0);
}



