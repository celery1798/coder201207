#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct node
{
	int data;
	struct node *next;
}JOSEPHU;

JOSEPHU *jose_create(int n)
{
	JOSEPHU *l,*p,*q;
	int i = 1;

	l = malloc(sizeof(*l));
	if(l == NULL)
		return NULL;
	l->data = i;
	l->next = l;

	p = l;

	for(i++; i <= n ; i++)
	{
		q = malloc(sizeof(*q));
		if(q == NULL)
			return NULL;
		q->data = i;
		q->next = l;
	
		p->next = q;
		p = q;	
	}
	return l;
}

void jose_show(JOSEPHU *l)
{
	JOSEPHU *p = l;

	while(p->next != l)
	{
		printf("%d ",p->data);
//		fflush(NULL);
//		sleep(1);
		p = p->next;
	}
	printf("%d\n",p->data);
}

void jose_kill(JOSEPHU **l,int n)
{// 1 2 3 4 5 6 7 8
	int i = 1;
	JOSEPHU *p = *l,*q;

	while(p->next != p)
	{
		while(i < n)
		{
			q = p;
			p = p->next;
			i++;
		}

		q->next = p->next;
		printf("%d ",p->data);
		free(p);

		i = 1;
		p = q->next;
	}
	printf("\n");

	*l = p;
}

int main()
{
	int num = 8;
	int count = 3;
	JOSEPHU *ptr;

	ptr = jose_create(num);
	/*if error*/

	jose_show(ptr);

	jose_kill(&ptr,count);  //&ptr	//3615284
	jose_show(ptr);			//7
}













