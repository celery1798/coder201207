#ifndef _STACK_H_
#define _STACK_H_

#define STACKMAX	4

typedef struct
{
	int data[STACKMAX];
	int top;
}STACK;

STACK *stack_create();

int stack_isempty(STACK *);
int stack_isfull(STACK *);

int stack_push(STACK *, int newdata);
int stack_pop(STACK *, int *newdata);
int stack_top(STACK *, int *newdata);//查看栈顶元素 

void stack_show(STACK *);

void stack_destroy(STACK *);


#endif


