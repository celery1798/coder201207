#include <stdio.h>
#include <stdlib.h>

#define M	2
#define N	3

int main()
{
//	int a[2][3];
//	int a[2][3] = {3,4,5,6,7,8}; //{{3,4,5},{6,7,8}};
//	int a[2][3] = {3,4,5};	//{{3},{4,5}};
	int a[][3] = {3,4,5,6,7,8}; //{{3,4,5},{6,7,8}};
//	int a[M][N];
	int i,j;

	printf("a = %p\n",a);
	printf("a+1 = %p\n\n",a+1);
	printf("sizeof(a) = %ld\n",sizeof(a));
	printf("sizeof(a[0][0]) = %ld\n\n",sizeof(a[0][0]));

/*
	for(i = 0; i < 2; i++)
	{
		for(j = 0 ; j < 3 ; j++)
			scanf("%d",&a[i][j]);
	}
*/
	for(i = 0; i < 2; i++)
	{
		for(j = 0 ; j < 3 ; j++)
			printf("%p --> %d\n", *(a+i)+j  ,*(*(a+i)+j));
			//printf("%p --> %d\n",&a[i][j],a[i][j]);
		printf("\n");
	
	}

	
	exit(0); 	//return 0;
}

