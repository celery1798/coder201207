#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define NAMESIZE	32

struct score
{
	int id;
	char name[NAMESIZE];
	int math;
};

typedef struct node
{
	struct score data;
	struct node *next;
}LIST;


//只做首部插入
int list_insert(LIST **l,struct score *data)
{

	LIST *new;

	new = malloc(sizeof(*new));
	if(new == NULL)
		return -1;

	new->data = *data;
	new->next = *l;
	*l = new;
	
	return 0;
}

void list_show(LIST *l)
{
	LIST *p = l;

	for(; p ;p = p->next)
	{
		printf("%d %s %d\n",p->data.id,p->data.name,p->data.math);
	}
}



int main()
{
	LIST *ptr = NULL;
	struct score tmp;
	int i;

	for(i = 0 ;i < 6; i++)
	{
		tmp.id = i;
		snprintf(tmp.name,NAMESIZE,"Stu%d",i);
		tmp.math = 100-i;

		list_insert(&ptr,&tmp);
	}
	list_show(ptr);

	exit(0);
}





