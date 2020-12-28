#include <stdio.h>
#include <stdlib.h>

#include "sqlist.h"


/*
sqlist_init: init a sqlist 
return: NULL failed.not null successed.
*/

SQLIST *sqlist_init()
{
	SQLIST *ptr;
	ptr = malloc(sizeof(*ptr));	
	if(ptr == NULL)
		return NULL;
		
	ptr->last = -1;
	return ptr;
}

int sqlist_isfull(SQLIST *ptr)
{
	if(ptr->last == MAXSIZE-1)
		return 1;
	return 0;
}

int sqlist_insert_pos(SQLIST *ptr, int pos, data_t *newdata)
{
	int i;

	if(sqlist_isfull(ptr))
		return -1;
	if(pos < 0 || pos > ptr->last + 1)
		return -2;

	i = ptr->last;	
	
	while(i >= pos)
	{
		ptr->data[i+1] = ptr->data[i];
		i--;
	}

	ptr->data[pos] = *newdata;
	ptr->last++;

	return 0;
}



void sqlist_show(SQLIST *ptr)
{
	int i;

	if(ptr->last != -1)
	{
		for(i = 0 ; i <= ptr->last  ; i++)
			printf("%d ",ptr->data[i]);
		printf("\n");
	}
		
}






















