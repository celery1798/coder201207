#include <stdio.h>
#include <stdlib.h>


long long int fac(int n)
{
	if(n < 0)
		return -1;
	if(n == 0 || n == 1)
		return 1;
	return n * fac(n-1);
}

int main()
{
	int num;

	printf("Please enter:");
	scanf("%d",&num);

	printf("%lld\n",fac(num));

	exit(0);
}

