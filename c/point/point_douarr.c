#include <stdio.h>
#include <stdlib.h>

/*

a[i][j] => *(*(a+i)+j) => *(*(p+i)+j) => p[i][j]

&a[i][j] => *(a+i)+j => a[i]+j => *(p+i)+j => p[i]+j => &p[i][j] 

*/

int main()
{

	int a[2][3] = {3,4,5,6,7,8}; 
	int i,j;
	int (*p)[3] ;		//int[3]  * p 数组指针
	//int *p [3]; 指针数组 

/*
	int *p ;
	
//waring 	p = a;
	p = *(a+0)+0;	//a[0];	*a;	*(a+0);	&a[0][0];
*/

	p = a;


	printf("a = %p\n",a);
	printf("a+1 = %p\n",a+1);
	printf("sizeof(a) = %ld\n\n",sizeof(a));

	printf("p = %p\n",p);
	printf("p+1 = %p\n",p+1);
	printf("sizeof(p) = %ld\n\n",sizeof(p));


	for(i = 0; i < 2; i++)
	{
		for(j = 0 ; j < 3 ; j++)
		//	printf("%p --> %d\n",&a[i][j],a[i][j]);
		//	printf("%p --> %d\n", *(a+i)+j  ,*(*(a+i)+j));
		//	printf("%p --> %d\n", *(p+i)+j  ,*(*(p+i)+j));
		//	printf("%p --> %d\n", &p[i][j],p[i][j]);
			printf("%p --> %d\n", p[i]+j,p[i][j]);
		printf("\n");

	}




	exit(0); 	//return 0;
}

