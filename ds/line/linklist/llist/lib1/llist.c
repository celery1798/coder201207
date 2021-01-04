#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "llist.h"

LLIST *llist_create(int size)
{
	LLIST *ptr;

	ptr = malloc(sizeof(*ptr));
	if(ptr == NULL)
		return NULL;

	ptr->size = size;
	ptr->head.data = NULL;
	ptr->head.prev = ptr->head.next = &ptr->head;

	return ptr;
}

int llist_insert(LLIST *ptr, const void *data, int mode)
{

	struct llist_node_st *newnode;

	newnode = malloc(sizeof(*newnode));
	if(newnode == NULL)
		return -1;
	newnode->data = malloc(ptr->size);
	if(newnode->data == NULL)
	{
		free(newnode);
		return -2;
	}
	memcpy(newnode->data, data, ptr->size);

	if(mode == LLIST_FORWARD)
	{
		newnode->prev = &ptr->head;
		newnode->next = ptr->head.next;
	}
	else
	{
		if(mode == LLIST_BACKWARD)
		{
			newnode->next = &ptr->head;
			newnode->prev = ptr->head.prev;
		}
		else
			return -3;
	}
	newnode->prev->next = newnode;
	newnode->next->prev = newnode;	
	
	return 0;	
}

void llist_travel(LLIST *ptr,llist_op *op)//print_s
{
	
	struct llist_node_st *cur;

	for(cur = ptr->head.next ;  cur != &ptr->head  ; cur = cur->next)
		op(cur->data);


}






















