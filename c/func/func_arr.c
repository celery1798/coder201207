#include <stdio.h>
#include <stdlib.h>

//void show(int p[],int n)
void show(int *p,int n)
{
	int i;

	printf("sizeof(p) = %ld\n",sizeof(p));
	for(i = 0 ; i < n ; i++)
		printf("%d ",p[i]);
	printf("\n");
}

int main()
{
	int arr[] = {5,6,7,8,9};

	printf("sizeof(arr) = %ld\n",sizeof(arr));

	show(arr,sizeof(arr)/sizeof(*arr));

	exit(0);
}

	
