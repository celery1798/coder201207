#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int conf;
	int exp;
	struct node *next;
}POLY;

POLY *poly_create(int (*a)[2],int n)
{
	POLY *l,*p,*q;
	int i;
		
	l = malloc(sizeof(*l));
	if(l == NULL)
		return NULL;
	l->next = NULL;

	p = l;

	for(i = 0 ; i < n; i++)
	{
		q = malloc(sizeof(*q));
		if(q == NULL)
			return NULL;

		q->conf = a[i][0];
		q->exp = a[i][1];
		q->next = NULL;
	
		p->next = q;
		p = q;
	}

	return l;
}

void poly_show(POLY *l)
{
	POLY *p = l->next;

	for(; p ;p = p->next)
		printf("(%d,%d) ",p->conf,p->exp);
	printf("\n");
}

void poly_add(POLY *l1,POLY *l2)
{
	POLY *p,*q,*r;

	r = l1;
	p = l1->next;
	q = l2->next;

	while(p && q)
	{
		if(p->exp < q->exp)
		{
			r->next = p;
			r = p;
			p = p->next;	
		}
		else
		{
			if(p->exp > q->exp)
			{
				r->next = q;
				r = q;
				q = q->next;		
			}
			else	// p->exp == q->exp
			{
				p->conf += q->conf;
				if(p->conf)
				{
					r->next = p;
					r = p;
				}
				p = p->next;
				q = q->next;
			}
		}
	}

	if(p)
		r->next = p;
	else
		r->next = q;
}

int main()
{
	POLY *p1,*p2;
	int a[][2] = {{5,0},{2,1},{8,8},{-3,16}};
	int b[][2] = {{6,1},{12,6},{-8,8}};

	p1 = poly_create(a,4);
	/*if error*/
	p2 = poly_create(b,3);

	poly_show(p1);
	poly_show(p2);

	poly_add(p1,p2);
	poly_show(p1);

}




