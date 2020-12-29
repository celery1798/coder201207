#include <stdio.h>
#include <stdlib.h>

#include "list.h"

int main()
{
	LIST *handler;
	int a[] = {4,5,6,7},i;


	handler = list_create();
	if(handler == NULL)
	{
		printf("list_create() failed.\n");
		exit(1);
	}
	
	for(i = 0 ; i < sizeof(a)/sizeof(*a); i++)
		list_insert(handler,0,a[i]);

	list_display(handler);

//	list_insert(handler,5,100);
//	list_display(handler);

	exit(0);
}


