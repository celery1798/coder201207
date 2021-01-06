#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "stack.h"

#define NAMESIZE    32

struct score
{
	int id;
	char name[NAMESIZE];
	int math;
};

void print_s(void *data)
{
	struct score *d = data;
	printf("%d %s %d\n",d->id,d->name,d->math);
}

int main()
{
	STACK *handler;
	struct score tmp;
	int i;

	handler = stack_create(sizeof(struct score));
	if(handler == NULL)
	{
		printf("stack_create() error.\n");
		exit(1);
	}

	for(i = 0 ;i < 6; i++)
	{
		tmp.id = i;
		snprintf(tmp.name,NAMESIZE,"Stu%d",i);
		tmp.math = 100-i;

		stack_push(handler,&tmp);
	}
	while(stack_pop(handler,&tmp) == 0)
		print_s(&tmp);

	stack_destroy(handler);

	exit(0);

}








