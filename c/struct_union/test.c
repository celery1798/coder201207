#include <stdio.h>
#include <stdlib.h>


char *mystrcpy(char *dest, const char *src)
{
	char *save = dest;

	if(dest != NULL && src != NULL)
	{
		while((*dest++ = *src++) != '\0')
			;
	}
	return save;
}

//mystrncpy()


int main()
{

	char str1[32],str2[] = "hello"; 

	mystrcpy(str1,str2);
	//strncpy(str1,str2,3);
	puts(str1);

	exit(0);
}
