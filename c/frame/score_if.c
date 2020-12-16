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

	// [0 ,100]
	if(score >= 90)		//[90,100]
		printf("A\n");
	else	//	[0,90)
	{
		if(score >= 80)	// [80,90)
			printf("B\n");
		else
		{
			if(score >= 70)
				printf("C\n");
			else
			{
				if(score >= 60)
					printf("D\n");
				else
					printf("E\n");
			}
		}
	
	}


/*
	if(score >= 90 && score <= MAX)
		putchar('A');
	if(score >= 80 && score < 90)
		putchar('B');
	if(score >= 70 && score < 80)
		putchar('C');
	if(score >= 60 && score < 70)
		putchar('D');
	if(score >= MIN && score < 60)
		putchar('E');
	putchar('\n');
*/

	exit(0); 	//return 0;
}

