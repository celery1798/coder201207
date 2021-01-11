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


	fputc('X',fp);
	/*if error*/

	ch = fgetc(fp);
	if(ch != EOF)
		putchar(ch);

	fclose(fp);

	exit(0);
}



