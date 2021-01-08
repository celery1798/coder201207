#include <stdio.h>
#include <stdlib.h>

#include "queue.h"
#include "stack.h"

#define MAXMIN	4
#define MAXFIVEMIN	11
#define MAXHOUR	11
#define MAXBALL	27

int check_(QUEUE *qu)
{
	int i ;

	i = (qu->front+1)%QUEUEMAX;

	while(i != qu->tail)
	{
		if(qu->data[i] > qu->data[(i+1)%QUEUEMAX])
			return 0;
		i = (i+1)%QUEUEMAX;
	}
	return 1;
}


int main()
{
	STACK *st_min,*st_fivemin,*st_hour;
	QUEUE *qu;
	int i,time = 0,tmp,value;
	

	st_min = stack_create();
	/*if error*/
	st_fivemin = stack_create();
	/*if error*/
	st_hour = stack_create();
	/*if error*/

	qu = queue_create();
	/*if error*/
	
	for(i = 0 ; i < MAXBALL; i++)
		queue_en(qu,i+1);
	queue_show(qu);

	while(1)
	{
		queue_de(qu,&tmp);
		time++;

		if(stack_getlength(st_min) != MAXMIN-1)
			stack_push(st_min,tmp);
		else
		{
			//st_min is full
			while(!stack_isempty(st_min))
			{
				stack_pop(st_min,&value);
				queue_en(qu,value);
			}
			if(stack_getlength(st_fivemin) != MAXFIVEMIN-1)
				stack_push(st_fivemin,tmp);
			else
			{
				//st_fivemin is full
				while(!stack_isempty(st_fivemin))
				{
					stack_pop(st_fivemin,&value);
					queue_en(qu,value);
				}
				if(stack_getlength(st_hour) != MAXHOUR-1)
					stack_push(st_hour,tmp);
				else
				{
					while(!stack_isempty(st_hour))
					{
						stack_pop(st_hour,&value);
						queue_en(qu,value);
					}
					queue_en(qu,tmp);
					
					if(check_(qu))
						break;	
					
				}

			}
		
		
		}
	
	}

	printf("TIME: %d\n",time);

	queue_show(qu);

	stack_destroy(st_min);
	stack_destroy(st_fivemin);
	stack_destroy(st_hour);
	queue_destroy(qu);

	exit(0);
}


