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









