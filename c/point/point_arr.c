#include <stdio.h>
#include <stdlib.h>


/*
arr[i] => *(arr+i) => *(p+i) => p[i]

&arr[i] => arr+i => p+i => &p[i]

2 + 3  = 3+2
*(p+i) = *(i+p) => i[p]

*/

int main()
{
//	p++  p+1
	int arr[5],i;
	int *p = arr;

	for(i = 0 ; i < sizeof(arr)/sizeof(arr[0]); i++,p++)
		scanf("%d",p);

	p = arr;
	for(i = 0 ; i < sizeof(arr)/sizeof(arr[0]); i++,p++)
		printf("%d ",*p);
	printf("\n");	





/*	
	int arr[] = {225,64,67,28,9};
	int *p = &arr[0] , *q = &arr[3];


	printf("%ld\n",q - p);
	printf("%d\n",*q - *p);

*/



/*
	int arr[] = {5,6,7,8,9};
	int *p = arr;	// &arr[0];
	int i;

	printf("sizeof(arr) = %ld\n",sizeof(arr));
	printf("sizeof(p) = %ld\n",sizeof(p));
	
	for(i = 0 ; i < sizeof(arr)/sizeof(arr[0]); i++)
		//printf("%p --> %d\n",arr+i,*(arr+i));
		printf("%p --> %d\n",&p[i],p[i]);
		//printf("%p --> %d\n",p+i,*(p+i));
		//printf("%p --> %d\n",&arr[i],arr[i]);
	printf("\n");
*/
	
	exit(0); 	//return 0;
}

