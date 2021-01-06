#include "llist.h"
#include "stack.h"

STACK *stack_create(int size)
{
	return llist_create(size);
}

int stack_push(STACK *st, const void *data)
{
	return llist_insert(st,data,LLIST_FORWARD);
}

static int alway_match(const void *data,const void *key)
{
	return 0;
}

int stack_pop(STACK *st,void *data)
{
	return llist_fetch(st,(void *)0,alway_match,data);
}

void stack_destroy(STACK *st)
{
	llist_destroy(st);
}



