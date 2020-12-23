#include <stdio.h>
#include <stdlib.h>

/*
	const 常量化

	int const i = 1;
	const int i = 1;

	int *const p;

	const int *p;
	int const *p;

	const int * const p;
*/

//#define PI	3.14
//float pi = 3.14;


int main()
{
	int i = 1,j = 3;
	const int * const p = &i;

//F	p = &j;
//F	*p = 100;

	printf("*p = %d\n",*p);



/*
	int i = 1,j = 3;
	const int *p;

	p = &j;
//F	*p = 100;

	printf("*p = %d\n",*p);
*/




/*
	int i = 1,j = 3;
	int *const p = &i;

//F	p = &j;
	*p = 100;

	printf("*p = %d\n",*p);
*/


/*
	const float pi = 3.14;

	pi = 30;	//F

	printf("pi = %f\n",pi);

*/

	exit(0); 	//return 0;
}






