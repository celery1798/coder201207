#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
strcpy  strncpy
strcat strncat
strcmp strncmp
strlen
*/

int main()
{
	char str[32] = "worldaABC",str1[] = "worldb";
	char str2[] = "\t\072\x78\nWALL";

//	printf("%d\n",strncmp(str,str1,5));

//	printf("%ld\n",sizeof(str));
	printf("%ld\n",strlen(str2));


/*
	char str[32] = "0123456789";

	puts(str);
//	puts(str+5);

	strcpy(str+5,str);
	puts(str);
*/
/*
	char str[10] = "abc",str1[30] = "world";
	strcpy(str,str1);
	puts(str);
	puts(str1);
*/
	
	exit(0); 	//return 0;
}

