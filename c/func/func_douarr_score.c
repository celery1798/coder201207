#include <stdio.h>
#include <stdlib.h>

#define M	3
#define N	4

float score_ave(int *p,int n)
{
	float sum = 0;
	int i;

	for(i = 0 ; i < n ; i++)
		sum += p[i];
	return sum/n;
}

int *score_find(int (*p)[N],int m,int n)
{
	int id,i;

	printf("Please enter the ID[0-2]:");
	scanf("%d",&id);
	
	if(id < 0 || id > m-1)
		return NULL;


	return *(p+id);
}

int main()
{
	int a[M][N] = {{78,90,84,91},{94,89,88,45},{78,56,99,100}};
	int *p,i;

	printf("AVE:%f\n",score_ave(*a,M*N));

	p = score_find(a,M,N);
	if(p == NULL)
	{
		printf("Can not find !\n");
	}
	else
	{
		for(i = 0 ; i < N; i++)
			printf("%d ",*(p+i));
		printf("\n");
	}
	
	exit(0);
}







