#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

STACK *stack_create()
{
	STACK *st;

	st = malloc(sizeof(*st));
	if(st == NULL)
		return NULL;
	st->top = -1;
	return st;
}

int stack_isempty(STACK *st)
{
	if(st->top == -1)
		return 1;
	return 0;
}

int stack_isfull(STACK *st)
{
	if(st->top == STACKMAX-1)
		return 1;
	return 0;
}
int stack_getlength(STACK *st)
{
	return st->top;
}

int stack_push(STACK *st, int newdata)
{
	if(stack_isfull(st))
		return -1;

	st->data[++st->top] = newdata;
	return 0;
}

int stack_pop(STACK *st, int *newdata)
{
	if(stack_isempty(st))
		return -1;
	*newdata = st->data[st->top--];
	return 0;		
}

int stack_top(STACK *st, int *newdata)//查看栈顶元素 
{
	if(stack_isempty(st))
		return -1;
	*newdata = st->data[st->top];
	return 0;
}

void stack_show(STACK *st)
{
	int i;
	if(stack_isempty(st))
		return ;
	for(i = 0 ; i <= st->top; i++)
		printf("%d ",st->data[i]);
	printf("\n");
}

void stack_destroy(STACK *st)
{
	free(st);
}
