#include <stdio.h>
#include <stdlib.h>

#define NUM		1001

int main()
{
	int primer[NUM] = {0};
	int i,j;

	for(i = 2; i < NUM; i++)
	{
		if(primer[i] == 0)
		{
			for(j = i+i; j < NUM ; j+=i)
				primer[j] = 1;
		}
	}
	
	for(i = 2; i < NUM; i++)
	{
		if(primer[i] == 0)
			printf("%d ",i);
	}
	printf("\n");



	
	exit(0); 	//return 0;
}

