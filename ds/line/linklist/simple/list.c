#include <stdio.h>
#include <stdlib.h>

#include "list.h"

LIST *list_create()
{
	LIST *l;
	l = malloc(sizeof(*l));
	if(l == NULL)
		return NULL;
	l->next = NULL;
	return l;
}

int list_insert(LIST *l, int pos, int newdata)
{
	LIST *p = l,*q;
	int i = 0 ;

	while(p && i < pos)
	{
		p = p->next;
		i++;
	}
	
	if(p == NULL)
		return -2;

	q = malloc(sizeof(*q));
	if(q == NULL)
		return -1;
	q->data = newdata;
//	q->next = NULL;
	q->next = p->next;
	p->next = q;

	return 0;
}

void list_display(LIST *l)
{
	LIST *p = l->next;;

	while(p)
	{
		printf("%d ",p->data);
		p = p->next;
	}
	printf("\n");
}

int list_delete(LIST *l,int pos, int *newdata)
{
	LIST *p = l,*q;
	int i = 0;

	while(p && i < pos)
	{
		p = p->next;
		i++;	
	}

	if(p)
	{
		q = p->next;
		
		p->next = q->next;
		if(newdata != NULL)
			*newdata = q->data;
		free(q);
		q = NULL;
	}
	else
		return -1;

}

int list_insert_value(LIST *l,int newdata)
{// @  10  20   30   40   50    newdata = 55
	LIST *p = l,*q;
	
	while(p->next && p->next->data < newdata)
		p = p->next;

	q = malloc(sizeof(*q));
	if(q == NULL)
		return -1;
	q->data = newdata;
	q->next = p->next;
	p->next = q;

	return 0;	
}
int list_delete_value(LIST *l,int newdata)
{// @  10  20   30   40   50    newdata = 15

	LIST *p = l,*q;

	while(p->next && p->next->data != newdata)
	        p = p->next;
	
	if(p->next == NULL)
		return -1;

	q = p->next;	
	p->next = q->next;
	free(q);
	q = NULL;
	return 0;
}

int list_locate(LIST *l,int finddata)
{
	LIST *p = l;

	while(p && p->data != finddata)
		p = p->next;

	if(p)
		return 0;
	return -1;
}


void list_clear(LIST *l)
{// @  4 5  
	LIST *p = l,*q;

	while(p->next)
	{
		q = p->next;
		p->next = q->next;
//		printf("Clear:%d\n",q->data);
		free(q);
		q = NULL;
	}
}

void list_destroy(LIST *l)
{
	list_clear(l);

	free(l);
}







