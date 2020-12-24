#include <stdio.h>
#include <stdlib.h>

int add(int a,int b)
{
	return a+b;
}
int sub(int a,int b)
{
	return a-b;
}

int op(int a,int b,int(*p)(int,int))
{
	return p(a,b);
}

int main()
{
/*
	int a = 3,b = 5;

	printf("%d\n",op(a,b,add));
*/

	int a = 3,b = 5,i;
//	int (*p)(int,int);
//	int (*q)(int,int);
	int (*arr[2])(int,int) = {add,sub};

//	p = add;
//	q = sub;

//	printf("%d\n",p(a,b));
//	printf("%d\n",q(a,b));

	for(i = 0 ; i < 2; i++)
		printf("%d\n",arr[i](a,b));


	exit(0);
}

