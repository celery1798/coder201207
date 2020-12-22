#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i = 1,j;
	int *p = &i;
	int *t = NULL;
	void *m;

	*p = 100;
	printf("p = %p, *p = %d\n",p,*p);
	printf("&i = %p, i = %d\n",&i,i);

	
	*t = 12;
	printf("t = %p, *t = %d\n",t,*t);
	
	exit(0); 	//return 0;
}

