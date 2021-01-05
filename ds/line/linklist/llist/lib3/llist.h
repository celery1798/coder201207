#ifndef __LLIST_H__
#define __LLIST_H__

#include "llist.c"

typedef void LLIST;

#define LLIST_FORWARD	1
#define LLIST_BACKWARD	2

typedef void llist_op(void *);
typedef int llist_cmp(const void *,const void *);

LLIST *llist_create(int size);

int llist_insert(LLIST *, const void *data, int mode);

void *llist_find(LLIST *,const void *key,llist_cmp *cmp);

int llist_delete(LLIST *,const void *key,llist_cmp *cmp );

int llist_fetch(LLIST *,const void *key,llist_cmp *cmp, void *data );

void llist_travel(LLIST *,llist_op *op);

void llist_destroy(LLIST *);



#endif



