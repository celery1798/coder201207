#include <stdio.h>
#include <stdlib.h>


/*
switch(expr)	
{
	case const-expr:
		statements;
		break;
	case const-expr:
		statements;
		break;
	case const-expr:
		statements;
		break;
	case const-expr:
		statements;
		break;
	.....
	default:
		statement;
		break;
}

*/


int main()
{
/*
	int i;
	
	scanf("%d",&i);

	switch(i)
	{
		case 1:
		case 2:
		case 3:
			printf("Good Morning.\n");
			break;
		case 4:
			printf("Good Afternoon.\n");
			break;
		case 8:
			printf("Good Evening.\n");
			break;
		default:
			printf("ERROR.\n");
	}
*/

	char ch;

	ch = getchar();

	switch(ch)
	{
		case 'a':
		case 'A':
			printf("Ant:A small insect that lives in group.\n");
			break;
		case 'b':
		case 'B':
			printf("Bee:A flying insect with a black and yellow body.\n");
			break;
		case 'c':
		case 'C':
			printf("Cobra:A highly dangerous snake native to Africa.\n");
			break;
		case 'D':
		case 'd':
			printf("Donkey:A animal with short legs and long ears.\n");
			break;
		case 'e':
		case 'E':
			printf("Elephant:A very large animal with a long nose.\n");
			break;
		default:
			printf("ERROR\n");
	
	}









	exit(0); 	//return 0;
}




