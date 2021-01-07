#ifndef __QUEUE_H__
#define __QUEUE_H__

#include "llist.h"

typedef LLIST QUEUE;

QUEUE *queue_create(int size);

int queue_en(QUEUE *, const void *data);

int queue_de(QUEUE *,void *data);

void queue_destroy(QUEUE *);

#endif

