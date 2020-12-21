#include <stdio.h>
#include <stdlib.h>

#define N	8

int main()
{

	int arr[] = {5,6,7,8,9}; 	//{4,6};   //{5,6,7};
	int i;

	for(i = 0 ; i < sizeof(arr)/sizeof(arr[0]); i++)
		printf("%p --> %d\n",arr+i,*(arr+i));
		//printf("%p --> %d\n",&arr[i],arr[i]);
	printf("\n");
	
	exit(0); 	//return 0;
}

