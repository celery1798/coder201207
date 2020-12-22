#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{

	char str[] = "hello";
	char *p = "12345";

//T	strcpy(str,p);
//F	strcpy(p,str);


	puts(str);
	puts(p);


/*
	char str[] = "hello world";
	char *p = "hello world";


	printf("sizeof(str) = %ld\n",sizeof(str));
	printf("sizeof(p) = %ld\n",sizeof(p));


	puts(str);
	puts(p);
*/	
	exit(0); 	//return 0;
}

