#include <stdio.h>
#include <stdlib.h>

int main()
{
	int year;

	printf("Please enter:");
	scanf("%d",&year);

	if(year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
		printf("%d is a leap year.\n",year);

	
	exit(0); 	//return 0;
}

