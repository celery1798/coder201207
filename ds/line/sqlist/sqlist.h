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

sqlist_insert();
sqlist_find();
sqlist_show();

void sqlist_destroy(SQLIST *);

#endif

