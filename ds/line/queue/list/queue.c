#include "llist.h"
#include "queue.h"

QUEUE *queue_create(int size)
{
	return llist_create(size);
}

int queue_en(QUEUE *qu, const void *data)
{
	return llist_insert(qu,data,LLIST_BACKWARD);
}

static int alway_match(const void *data,const void *key)
{
	return 0;
}

int queue_de(QUEUE *qu,void *data)
{
	return llist_fetch(qu,(void *)0,alway_match,data);
}

void queue_destroy(QUEUE *qu)
{
	llist_destroy(qu);
}



