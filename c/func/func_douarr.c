#include <stdio.h>
#include <stdlib.h>

//void show(int p[][3],int m,int n)
void show(int (*p)[3],int m,int n)
{
	int i,j;

	printf("sizeof(p) = %ld\n",sizeof(p));
	for(i = 0; i < m; i++)
	{
		for(j = 0 ; j < n ; j++)
			printf("%d ",p[i][j]);
		printf("\n");
	}
}

int main()
{
	int a[2][3] = {3,4,5,6,7,8}; 
	
	printf("sizeof(a) = %ld\n",sizeof(a));
	show(a,2,3);

	exit(0);
}	


