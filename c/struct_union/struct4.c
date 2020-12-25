#include <stdio.h>
#include <stdlib.h>


struct node
{
	int a;
	float f;
	char ch;
}y = {12,1.23,'Y'},*q,bb[5];

func(    )
{

}

int main()
{
	struct node x = {123,45.67,'X'};
	struct node *p = &x;
	struct node arr[3] = {{123,45.67,'X'} ,{123,45.67,'X'} , {123,45.67,'X'}};
	struct node *arrp = arr;
	struct node b[2][3] ;	//= {{{},{},{}},{{},{},{}}};
	struct node (*pp)[3] = b;

	func(x.ch,   *p,    arr[0],     arr+1,     bb[1].f,   &y,  b[0][2], 	*(b+1)+1, 	pp[0][1].ch, 	pp+1);
--------------------------------------------------------
func(char, struct node, struct node, struct node*, float,struct node *, struct node, struct node*, char, struct (*)[3])

	exit(0);
}

