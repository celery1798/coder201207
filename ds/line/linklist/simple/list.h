#ifndef __LIST_H__
#define __LIST_H__

typedef struct node
{
	int data;
	struct node *next;
}LIST;

LIST *list_create();

int list_insert(LIST *, int pos, int newdata);
int list_delete(LIST *,int pos, int *newdata);

int list_insert_value(LIST *,int newdata);
int list_delete_value(LIST *,int newdata);

int list_locate(LIST *,int finddata);

void list_display(LIST *);

void list_clear(LIST *);
void list_destroy(LIST *);

#endif



