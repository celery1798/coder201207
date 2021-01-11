#include <stdio.h>
#include <stdlib.h>

void show(int *p,int n)
{
	int i;
	for(i = 0 ; i < n ; i++)
		printf("%d ",p[i]);
	printf("\n");
}

int main()
{
	int i = 1,sum = 0;
	int arr[] = {5,6,7,8,9};

	do
	{
		sum += i;
		i++;
	}while(i <= 100);

	printf("sum = %d\n",sum);
	printf("END do-while()\n");

	show(arr,sizeof(arr)/sizeof(*arr));

	for(i = 1,sum=0 ; i <= 100; i++)
		sum += i;

	printf("sum = %d\n",sum);
	printf("END while()\n");
	
	show(arr,sizeof(arr)/sizeof(*arr));

	printf("END ALL\n");
	exit(0); 	//return 0;
}

