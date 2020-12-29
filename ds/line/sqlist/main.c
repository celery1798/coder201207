#include <stdio.h>
#include <stdlib.h>

#include "sqlist.h"


int main()
{
	SQLIST *sq,*sq1;
	data_t a[] = {14,5,26,7,38,9};
	data_t b[] = {14,25,26,47,38,99};
	int i;

	sq = sqlist_init();
	if(sq == NULL)
	{
		printf("sqlist_init() error!\n");
		exit(1);	
	}

	for(i = 0 ; i < sizeof(a)/sizeof(*a); i++)	
	{
		//	sqlist_insert_pos(sq,0,&a[i]);
		sqlist_insert_order(sq,&a[i]);
	}
	sqlist_show(sq);

	sq1 = sqlist_init();
	if(sq1 == NULL)
	{
		printf("sqlist_init() error!\n");
		exit(1);
	}

	for(i = 0 ; i < sizeof(b)/sizeof(*b); i++)
	{
		//  sqlist_insert_pos(sq,0,&a[i]);
		sqlist_insert_order(sq1,&b[i]);
	}
	sqlist_show(sq1);


	sqlist_union(sq,sq1);
	sqlist_show(sq);


	sqlist_destroy(sq1);





/*
	sqlist_delete_pos(sq,1,&value);
	printf("VALUE = %d\n",value);
	sqlist_show(sq);
*/



/*
	int value = 100;
	int ret;
	ret = sqlist_insert_pos(sq,2,&value);
	printf("RET : %d\n",ret);
	sqlist_show(sq);
*/
	sqlist_destroy(sq);
	
	exit(0);
}

