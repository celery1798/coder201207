#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

void compute(STACK *st_num,int old_op)
{
	int n,n1,n2;
	stack_pop(st_num,&n2);
	stack_pop(st_num,&n1);

	switch(old_op)
	{
		case '+':
			n = n1+n2;
			break;
		case '-':
			n = n1-n2;
			break;
		case '*':
			n = n1*n2;
			break;
		case '/':
			n = n1/n2;
			break;
		default:
			exit(1);
	}
	stack_push(st_num,n);
}

void deal_bracket(STACK *st_num,STACK *st_op)
{
	int old_op;

	while(1)
	{
		stack_pop(st_op,&old_op);
		if(old_op != '(')
			compute(st_num,old_op);
		else
			break;
	}
}	

int get_pri(int op)
{
	switch(op)
	{
		case '(':
			return 0;
		case '+':
		case '-':
			return 1;
		case '*':
		case '/':
			return 2;
	}
}

void deal_op(STACK *st_num,STACK *st_op,int  op)
{// +-*/(
	int old_op;

	if(op == '(' || stack_isempty(st_op))
	{
		stack_push(st_op,op);
		return ;
	}

	stack_top(st_op,&old_op);
	if(get_pri(op) > get_pri(old_op))
	{
		stack_push(st_op,op);
		return ;	
	}
	
	//op <= old_op   op+    *-

	while(get_pri(op) <= get_pri(old_op))
	{
		stack_pop(st_op,&old_op);
		compute(st_num,old_op);
		if(stack_isempty(st_op))
			break;
		stack_top(st_op,&old_op);
	}
	stack_push(st_op,op);
}

int main()
{
	STACK *st_num,*st_op;
	char str[] = "5-(12-6)*2+3";
	int i,old_op;
	int value = 0,flag = 0;

	st_num = stack_create();
	/*if error*/
	st_op = stack_create();
	/*if error*/


	for(i = 0 ; str[i] != '\0'; i++)
	{
		if(str[i] >= '0' && str[i] <= '9')
		{		
			value = value * 10 + str[i] - '0';
			flag = 1;
		}
		else 	// str[i] -> +-*/()
		{
			if(flag)
			{
				stack_push(st_num,value);
				flag = 0;
				value = 0;
			}
			
			if(str[i] == ')')
				deal_bracket(st_num,st_op);
			else
				deal_op(st_num,st_op,str[i]);
		
		}
	
	}
	if(flag)
	{
		stack_push(st_num,value);	
	}


   	while(!stack_isempty(st_op)) 
	{
		stack_pop(st_op,&old_op);
		compute(st_num,old_op);	
	}

	stack_pop(st_num,&value);

	printf("%s = %d\n",str,value);

	stack_destroy(st_num);
	stack_destroy(st_op);

	exit(0);
}

