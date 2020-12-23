#include <stdio.h>
#include <stdlib.h>

/*
	1-> 1
	2-> 1
*/

int fib(int n)
{
	if(n <= 0)
		return -1;
	if(n == 1 || n == 2)
		return 1;
	return fib(n-1) + fib(n-2);	
}


int main()
{
	int num;

	printf("Please enter:");
	scanf("%d",&num);

	printf("%d\n",fib(num));

	exit(0);
}

