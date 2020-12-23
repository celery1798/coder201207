#include <stdio.h>
#include <stdlib.h>

int min(int a,int b,int c)
{
	int t;
	t = a < b ? a : b;
	return t < c ? t : c;
}

int max(int a,int b,int c)
{
	int t;
	t = a > b ? a : b;
	return t > c ? t : c ;
}

int dis(int a,int b,int c)
{
	return max(a,b,c) - min(a,b,c);
}

int main()
{
	int a,b,c;

	printf("Please enter:");
	scanf("%d%d%d",&a,&b,&c);

	printf("DIS:%d\n",dis(a,b,c));

	exit(0);
}

