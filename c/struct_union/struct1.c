#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct	student 
{
	int id;
	char name[12];
	float math;
};


int main()
{
	struct student s1;
/*
	s1.id = 10010;
	strcpy(s1.name,"Alan");
	s1.math = 89;
*/
	scanf("%d%s%f",&s1.id, s1.name ,&s1.math);

	printf("%d %s %f\n",s1.id, s1.name, s1.math);


	exit(0);
}

