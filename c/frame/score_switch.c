#include <stdio.h>
#include <stdlib.h>

#define MIN		0
#define MAX		100

int main()
{
	int score;

	printf("Please enter:");
	scanf("%d",&score);

	if(score < MIN || score > MAX)
	{
		printf("INPUT ERROR!\n");
		return 1;
	}

	switch(score/10)
	{
		case 10:
		case 9:
			printf("A\n");
			break;
		case 8:
			printf("B\n");
			break;
		case 7:
			printf("C\n");
			break;
		case 6:
			printf("D\n");
			break;
		default:
			printf("E\n");
			break;
	}




	exit(0); 	//return 0;
}

