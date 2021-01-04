#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "llist.h"

#define NAMESIZE    32

struct score
{
	int id;
	char name[NAMESIZE];
	int math;
};

int id_cmp(const void *data,const void *key)
{
	const struct score *d = data;
	const int *id = key;
	return d->id - *id;
}
int name_cmp(const void *data,const void *key)
{
	const struct score *d = data;
	const char *name = key;
	return strcmp(d->name ,name);
}


void print_s(void *data)
{
	struct score *d = data;
	printf("%d %s %d\n",d->id,d->name,d->math);
}

int main()
{
	LLIST *handler;
	struct score tmp;
	int i;

	handler = llist_create(sizeof(struct score));
	if(handler == NULL)
	{
		printf("llist_create() error.\n");
		exit(1);
	}

	for(i = 0 ;i < 6; i++)
	{
		tmp.id = i;
		snprintf(tmp.name,NAMESIZE,"Stu%d",i);
		tmp.math = 100-i;

		llist_insert(handler,&tmp,LLIST_BACKWARD);
	}

	llist_travel(handler, print_s);
	printf("\n");

	int id = 1;
	char *name = "stu2";
	int math = 100;
	void *retp;

	llist_delete(handler,&id,id_cmp);
	llist_travel(handler, print_s);


/*
//	retp = llist_find(handler,&id,id_cmp);
	retp = llist_find(handler,name,name_cmp);
	if(retp == NULL)
		printf("Can not find!\n");
	else
		print_s(retp);
*/
//	llist_destroy(handler);
	exit(0);
}








