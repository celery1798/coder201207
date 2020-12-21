#include <stdio.h>
#include <stdlib.h>


int main()
{
	char str[3][20] = {"hello","alan","ABCDE"};
	int i;

	for(i = 0 ; i < 3; i++)
		puts(str[i]);


/*
	char str[] = {'h','e','l','l','o'};
	char str1[] = "hello";		//{"hello"};

	printf("sizeof(str) = %ld\n",sizeof(str));
	printf("sizeof(str1) = %ld\n",sizeof(str1));
	
	for(i = 0 ; i < sizeof(str); i++)
		printf("%c ",str[i]);
	printf("\n");

	puts(str1);

*/
	
	exit(0); 	//return 0;
}

