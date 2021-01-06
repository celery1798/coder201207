#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

int main()
{
	STACK *st;
	int i;
	int arr[] = {4,5,6,7};

	st = stack_create();
	/*IF ERROR*/

	for(i = 0 ; i < 4; i++)
		stack_push(st,arr[i]);

//	stack_show(st);
	while(stack_pop(st,&i) == 0)
		printf("POP: %d\n",i);

	stack_destroy(st);
	
	exit(0);
}

