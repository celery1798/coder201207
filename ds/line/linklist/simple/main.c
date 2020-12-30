#include <stdio.h>
#include <stdlib.h>

#include "list.h"

int main()
{
	LIST *handler;
	int a[] = {14,5,26,7,9},i;


	handler = list_create();
	if(handler == NULL)
	{
		printf("list_create() failed.\n");
		exit(1);
	}
	
	for(i = 0 ; i < sizeof(a)/sizeof(*a); i++)
//		list_insert(handler,0,a[i]);
		list_insert_value(handler,a[i]);
	list_display(handler);

//	list_delete(handler,5,NULL);
	list_reverse(handler);
	list_display(handler);

	
	list_destroy(handler);

	exit(0);
}


