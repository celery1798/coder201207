#include <stdio.h>
#include <stdlib.h>

int  say_hi()
{
	return printf("Hello World!\n");
}

int main()
{
	int ret;

	printf("%d\n", say_hi());

	exit(0);
}

