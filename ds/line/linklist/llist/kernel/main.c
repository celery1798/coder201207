#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list.h"

#define NAMESIZE    32
struct score
{
	int id;
	char name[NAMESIZE];
	int math;
	struct list_head node;
};

void print_s(void *data)
{
	struct score *d = data;
	printf("%d %s %d\n",d->id,d->name,d->math);
}

int main()
{
	struct score *tmp;
	struct list_head  *cur;
	int i;

	LIST_HEAD(head);

	for(i = 0 ;i < 6; i++)
	{
		tmp = malloc(sizeof(*tmp));
		/*if error*/

		tmp->id = i;
		snprintf(tmp->name,NAMESIZE,"Stu%d",i);
		tmp->math = 100-i;

		list_add_tail(&tmp->node ,&head);
	}


	list_for_each(cur, &head)
	{
		tmp = list_entry(cur, struct score, node);
		print_s(tmp);
	}

	exit(0);
}








