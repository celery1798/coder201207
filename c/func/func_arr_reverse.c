#include <stdio.h>
#include <stdlib.h>


int reverse_arr(int *f,int n)
{
	int *f1 = f+(n-1);
	int t;

	while(f < f1)
	{
		t = *f;
		*f = *f1;
		*f1 = t;
		f++;
		f1--;
	}
/*
	int i,j,t;

	i = 0;
	j = n-1;

	while(i < j)
	{
		t = f[i];
		f[i] = f[j];
		f[j] = t;
		i++;
		j--;
	}
*/
}

int main()
{
	int f[] = {1,13,6,2,65,12,9,87,3};
	int i,j;

	j = sizeof(f)/sizeof(*f);

	for(i = 0; i < j; i++)
		printf("%d ",f[i]);
	printf("\n");

	reverse_arr(f,j);

	for(i = 0; i < j; i++)
		printf("%d ",f[i]);
	printf("\n");

	exit(0);
}








