#include <stdio.h>
#include <stdlib.h>

#include "queue.h"

QUEUE *queue_create()
{
	QUEUE *qu;

	qu = malloc(sizeof(*qu));
	if(qu == NULL)
		return NULL;
	qu->front = qu->tail = 0;
	return qu;
}

int queue_isempty(QUEUE *qu)
{
	return qu->front == qu->tail;
}

int queue_isfull(QUEUE *qu)
{
	return ((qu->tail + 1)%QUEUEMAX == qu->front);
}

int queue_en(QUEUE *qu ,int newdata)
{
	if(queue_isfull(qu))
		return -1;

	qu->tail =(qu->tail + 1)%QUEUEMAX;
	qu->data[qu->tail] = newdata;

	return 0;
}
int queue_de(QUEUE *qu,int *newdata)
{
	if(queue_isempty(qu))
		return -1;
	
	qu->front = (qu->front + 1 ) %QUEUEMAX;
	*newdata = qu->data[qu->front];
	return 0;
}

void queue_show(QUEUE *qu)
{
	int i;
	if(queue_isempty(qu))
		return ;

	i = (qu->front+1)%QUEUEMAX;

	while(i != qu->tail)
	{
		printf("%d ",qu->data[i]);
		i = (i+1)%QUEUEMAX;	
	}
	printf("%d\n",qu->data[i]);
	return ;
}
void queue_destroy(QUEUE *qu)
{
	free(qu);
}

