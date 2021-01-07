#include <stdio.h>
#include <stdlib.h>

#include "queue.h"

int main()
{
	int i;
	QUEUE *qu;
	int arr[] = {3,4,6,7};

	qu = queue_create();
	/*if error*/
		
	for(i = 0 ; i < 4; i++)
		queue_en(qu,arr[i]);
	queue_show(qu);

	while(!queue_de(qu,&i))
		printf("DE:%d\n",i);
	
	queue_destroy(qu);

	exit(0);
}


