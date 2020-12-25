#include <stdio.h>
#include <stdlib.h>


int main()
{
	int *p = NULL;

	p = malloc(sizeof(*p));
	if(p == NULL)
	{
		printf("malloc() failed.\n");
		exit(1);
	}

	*p = 100;

	printf("%p --> %d\n",p,*p);

	free(p);
	p = NULL;

	exit(0);
}

