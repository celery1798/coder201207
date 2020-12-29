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

	if(sqlist_isempty(ptr))
		return ;

	for(i = 0 ; i <= ptr->last  ; i++)
		printf("%d ",ptr->data[i]);
	printf("\n");
}

int sqlist_isempty(SQLIST *ptr)
{
	if(ptr->last == -1)
		return 1;
	return 0;
}

void sqlist_setempty(SQLIST *ptr)
{
	ptr->last = -1;
}

int sqlist_length(SQLIST *ptr)
{
	return ptr->last;
}

int sqlist_delete_pos(SQLIST *ptr,int pos,data_t *newdata)
{
	int i; 

	if(sqlist_isempty(ptr))
		return -1;

	if(pos < 0 || pos > ptr->last)
		return -2;

	if(newdata != NULL)
		*newdata = ptr->data[pos];

	i = pos+1;		
	while(i <= ptr->last)
	{
		ptr->data[i-1] = ptr->data[i];
		i++;
	}
	ptr->last --;

	return 0;
}

int sqlist_insert_order(SQLIST *ptr,data_t *newdata)
{
	int pos,i;

	if(sqlist_isfull(ptr))
		return -1;

	for(i = 0 ; i <= ptr->last; i++)
	{
		if(ptr->data[i] > *newdata)	
		{
			pos = i;
			break;
		}
	}	
	if(i == ptr->last+1)
		pos = i;

	return sqlist_insert_pos(ptr,pos,newdata);		
}

int sqlist_delete_value(SQLIST *ptr,data_t *newdata)
{
	int ret;

	ret = sqlist_find(ptr,newdata);
	if(ret >= 0)
		return sqlist_delete_pos(ptr,ret,NULL);
	return ret;

}

int sqlist_find(SQLIST *ptr,data_t *newdata)
{
	int i;

	if(sqlist_isempty(ptr))
		return -1;

	for(i = 0 ; i <= ptr->last; i++)
		if(ptr->data[i] == *newdata)
			return i;
	return -2;
}


void sqlist_destroy(SQLIST *ptr)
{
	free(ptr);
//	ptr = NULL;
}

//ptr1->1,3,5  ,ptr2-> 1,2,3;   ptr1->1 3 5 2
int sqlist_union(SQLIST *ptr1,SQLIST *ptr2)
{
	int i;

	if(sqlist_isempty(ptr2))
		return 0;

	for(i = 0 ; i <= ptr2->last	; i++)
		if(sqlist_find(ptr1, &ptr2->data[i]) == -2)
			sqlist_insert_pos(ptr1,ptr1->last+1,&ptr2->data[i]);
	
	return 0;
}



















