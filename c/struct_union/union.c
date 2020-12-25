#include <stdio.h>
#include <stdlib.h>


union node
{
	int a;
	float f;
	char ch;
};


int main()
{
	union node  x;

	x.f = 123.456;

	printf("sizeof(x) = %ld\n",sizeof(x));
	printf("%c\n",x.ch);


	exit(0);
}

