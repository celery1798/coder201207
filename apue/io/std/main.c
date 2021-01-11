#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

//int main(int argc,char *argv[])
int main(int argc,char **argv)
{
	int i;

	printf("%d\n",argc);

//	for(i = 0 ; i < argc; i++)
	for(i = 0 ; argv[i] != NULL; i++)
		printf("%s\n",argv[i]);



	exit(0);
}



