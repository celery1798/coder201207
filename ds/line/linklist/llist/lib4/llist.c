#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "llist.h"

int llist_insert(LLIST *, const void *data, int mode);
void *llist_find(LLIST *,const void *key,llist_cmp *cmp);
int llist_delete(LLIST *,const void *key,llist_cmp *cmp );
int llist_fetch(LLIST *,const void *key,llist_cmp *cmp, void *data );
void llist_travel(LLIST *,llist_op *op);

LLIST *llist_create(int size)
{
	LLIST *ptr;

	ptr = malloc(sizeof(*ptr));
	if(ptr == NULL)
		return NULL;

	ptr->size = size;
	ptr->head.prev = ptr->head.next = &ptr->head;
	ptr->insert = llist_insert;
	ptr->delete = llist_delete;
	ptr->fetch = llist_fetch;
	ptr->find = llist_find;
	ptr->travel = llist_travel;

	return ptr;
}

int llist_insert(LLIST *ptr, const void *data, int mode)
{

	struct llist_node_st *newnode;

	newnode = malloc(sizeof(*newnode)+ptr->size);
	if(newnode == NULL)
		return -1;
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

static struct llist_node_st *find_(LLIST *ptr,const void *key,llist_cmp *cmp)
{
	struct llist_node_st *cur;

    for(cur = ptr->head.next ;  cur != &ptr->head  ; cur = cur->next)
		if(cmp(cur->data,key) == 0)
			break;
	
	return cur;
}


void *llist_find(LLIST *ptr,const void *key,llist_cmp *cmp)
{
	struct llist_node_st *node;
	node = find_(ptr,key,cmp);
	if(node == &ptr->head)
		return NULL;
	return node->data;
}


int llist_delete(LLIST *ptr,const void *key,llist_cmp *cmp )
{
	struct llist_node_st *node;

	node = find_(ptr,key,cmp);
	if(node == &ptr->head)
		return -1;

	node->next->prev = node->prev;
	node->prev->next = node->next;

	free(node);
	return 0;
}

int llist_fetch(LLIST *ptr,const void *key,llist_cmp *cmp ,void *data)
{
	struct llist_node_st *node;

	node = find_(ptr,key,cmp);
	if(node == &ptr->head)
		return -1;

	node->next->prev = node->prev;
	node->prev->next = node->next;

	memcpy(data,node->data,ptr->size);
	free(node);
	return 0;
}


void llist_travel(LLIST *ptr,llist_op *op)//print_s
{
	struct llist_node_st *cur;

	for(cur = ptr->head.next ;  cur != &ptr->head  ; cur = cur->next)
		op(cur->data);
}

void llist_destroy(LLIST *ptr)
{
	struct llist_node_st *cur,*next;

	for(cur = ptr->head.next ;  cur != &ptr->head  ; cur = next)
	{
		next = cur->next;
		free(cur);
	}
	free(ptr);
}





















