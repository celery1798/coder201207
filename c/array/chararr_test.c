#include <stdio.h>
#include <stdlib.h>

int main()
{
	char str[128];
	int i,flag = 0,count = 0;
	int ch;
	gets(str);
	
	for(i = 0 ; str[i] != '\0'; i++)
//	for(i = 0 ; (ch = getchar()) != '\n'; i++)
	{
		if(str[i] == ' ')
		{
			flag = 0;
		}
		else	// str[i] is a char
		{
			if(flag == 0)
			{
				count++;
				flag = 1;
			}
		}
	}

	printf("COUNT:%d\n",count);
	

	exit(0);
}





