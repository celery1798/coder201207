#include <stdio.h>
#include <stdlib.h>


void swap(int **p, int **q)
{
	int t;

	t = **p;
	**p = **q;
	**q = t;
}

int main()
{
	int a = 3,b = 5;
	int *p = &a,*q = &b;
	int **m = &p, **n = &q;

	printf("a = %d, b = %d\n",a,b);
	
//	swap(&a,&b);
//	swap(p,q);
//	swap(&p,&q);
	swap(m,n);

	printf("a = %d, b = %d\n",a,b);

	
	exit(0);
}

