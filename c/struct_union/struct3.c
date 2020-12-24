#include <stdio.h>
#include <stdlib.h>


struct node
{
	int a;
	char ch;
	float f;
	char ch1;
};


int main()
{
	struct node x = {123,45.67,'X'};

	printf("%ld\n\n",sizeof(x));

	printf("%d %f %c\n",x.a, x.f, x.ch);


	exit(0);
}

