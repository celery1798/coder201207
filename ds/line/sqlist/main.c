#include <stdio.h>
#include <stdlib.h>

#include "sqlist.h"


int main()
{
	SQLIST *sq;
	data_t a[] = {4,5,6,7,8,9};
	int i;

	sq = sqlist_init();
	if(sq == NULL)
	{
		printf("sqlist_init() error!\n");
		exit(1);	
	}
		
	for(i = 0 ; i < sizeof(a)/sizeof(*a); i++)	
		sqlist_insert_pos(sq,0,&a[i]);
	
	sqlist_show(sq);

	int value;
	sqlist_delete_pos(sq,2,&value);
	printf(value);

/*
	int value = 100;
	int ret;
	ret = sqlist_insert_pos(sq,2,&value);
	printf("RET : %d\n",ret);
	sqlist_show(sq);
?
//	sqlist_destroy(sq);

	exit(0);
}

