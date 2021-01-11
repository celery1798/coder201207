#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>


int main()
{
	FILE *fp;	
	int ch;

	fp = fopen("myfile.txt","r+");
	if(fp == NULL)
	{
		perror("fopen()");	
		exit(1);
	}

	fseek(fp,3,SEEK_SET);

	fputc('X',fp);
	/*if error*/

	fclose(fp);

	exit(0);
}



