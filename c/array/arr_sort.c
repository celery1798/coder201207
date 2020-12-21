#include <stdio.h>
#include <stdlib.h>

void choose_sort()
{
	int a[] = {34,12,3,76,5,8,9,12,18};
	int i,j,k,t,ii;

	for(i = 0 ; i < 9; i++)
		printf("%d ",a[i]);
	printf("\n");

	for(i = 0; i < 8; i++)
	{
		k = i;
		for(j = i+1; j < 9; j++)	
		{
			if(a[k] > a[j])
				k = j;
		}
		if(i != k)
		{
			t = a[i];
			a[i] = a[k];
			a[k] = t;
		}
	}	

	for(ii = 0 ; ii < 9; ii++)
		printf("%d ",a[ii]);
	printf("\n");

}

void bubble_sort()
{
	int a[] = {34,12,3,76,5,8,9,12,18};
	int i,j,k,t,ii;

	for(i = 0 ; i < 9; i++)
		printf("%d ",a[i]);
	printf("\n");

	for(i = 0 ; i < 8; i++)
	{
		for(j = 0; j < 8-i ;j++)
			if(a[j] > a[j+1])
			{
				t = a[j];
				a[j] = a[j+1];
				a[j+1] = t;
			}
	}
	

	for(i= 0 ; i < 9; i++)
		printf("%d ",a[i]);
	printf("\n");


}


int main()
{

//	choose_sort();
	bubble_sort();



	
	exit(0); 	//return 0;
}

