#include <stdio.h>
#include <stdlib.h>

int print_value(int,int);

int main()
{
	int a = 0,b = 5;
	int ret;

	ret = print_value(a,b);
	if(ret != 0)
		printf("ERROR!\n");
	else
		printf("OK!");

	exit(0);
}
int print_value(int a, int x)
{
	if(a == 0 || x == 0)
		return -1;
	printf("%d %d\n",a,x);
	return 0;
}

