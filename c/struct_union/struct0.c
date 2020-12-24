#include <stdio.h>
#include <stdlib.h>


struct node
{
	int a;
	float f;
	char ch;
}y = {12,1.23,'Y'},*q,b[5];


int main()
{
	struct node x = {123,45.67,'X'};
	struct node *p = &x;
	struct node arr[3] = {{123,45.67,'X'} ,{123,45.67,'X'} , {123,45.67,'X'}};
	struct node *arrp = arr;
	struct node b[2][3] ;	//= {{{},{},{}},{{},{},{}}};
	struct node (*pp)[3] = b;

	printf("%d %f %c\n",x.a, x.f, x.ch);
	printf("%d %f %c\n",p->a, p->f, p->ch);


	exit(0);
}

