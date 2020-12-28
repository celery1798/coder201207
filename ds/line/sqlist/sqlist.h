#ifndef __SQLIST_H__
#define __SQLIST_H__

#define MAXSIZE		128	

typedef int  data_t;

typedef struct 
{
	data_t data[MAXSIZE];
	int last;
}SQLIST;


SQLIST *sqlist_init();

int sqlist_isfull(SQLIST *);
int sqlist_isempty(SQLIST *);

void sqlist_setempty(SQLIST *);

int sqlist_length(SQLIST *);

int sqlist_insert_pos(SQLIST *,int pos,data_t *newdata);
int sqlist_delete_pos(SQLIST *,int pos,data_t *newdata);

int sqlist_insert_order(SQLIST *,data_t *newdata);
int sqlist_delete_value(SQLIST *,data_t *newdata);

int sqlist_find(SQLIST *,data_t *newdata);

void sqlist_show(SQLIST *);

void sqlist_destroy(SQLIST *);

//ptr1->1,3,5  ,ptr2-> 1,2,3;   ptr1->1 3 5 2
int sqlist_union(SQLIST *ptr1,SQLIST *ptr2); 


#endif

