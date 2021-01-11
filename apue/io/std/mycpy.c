#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

int main(int argc,char *argv[])
{
	FILE *fps,*fpd;	
	int ch;

	if(argc < 3)
	{
		printf("Usage:%s <srcfile> <destfile>\n",argv[0]);
		exit(1);	
	}

	fps = fopen(argv[1],"r");
	if(fps == NULL)
	{
		perror("fopen()");	
		exit(1);
	}

	fpd = fopen(argv[2],"w");
	if(fpd == NULL)
	{
		perror("fopen()");  
		exit(1);
	}

	while((ch = fgetc(fps)) != EOF)
		fputc(ch,fpd);

	fclose(fps);
	fclose(fpd);

	exit(0);
}



