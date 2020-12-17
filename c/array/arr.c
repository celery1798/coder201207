#include <stdio.h>
#include <stdlib.h>

#define N	8

int main()
{

	int  a[3] = {2,3,4};	
	
	a[30] = 55;
	
	printf("%d\n",a[30]);








/*
	int arr[3];
	int arr1[N];
	double a[10];
	char d[N];
*/
/*
	int arr[] = {5,6,7,8,9}; 	//{4,6};   //{5,6,7};
	int i;

//	FFFFFFFFFFFFFFF	arr = {1,2,3};

	printf("arr = %p\n\n",arr);

	printf("sizeof(arr[0]) = %ld\n",sizeof(arr[0]));
	printf("sizeof(arr) = %ld\n\n",sizeof(arr));

//	for(i = 0 ; i < sizeof(arr)/sizeof(arr[0]); i++)
//		scanf("%d",&arr[i]);

	arr[2] = 10000;

	for(i = 0 ; i < sizeof(arr)/sizeof(arr[0]); i++)
		printf("%p --> %d\n",&arr[i],arr[i]);
	printf("\n");
*/
	
	exit(0); 	//return 0;
}

