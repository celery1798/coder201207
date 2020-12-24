#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct birthday
{
	int year;
	int month;
	int day;
};

struct teacher
{
	int a;
	float f;
	struct birthday birth;
};
struct	student 
{
	int id;
	char name[12];
	struct birthday birth;
	float math;
};


int main()
{
	struct student s1 = {10010,"Alan",{2000,10,10},98};

	printf("%d %s[%d-%d-%d] %f\n",s1.id, s1.name, s1.birth.year, s1.birth.month, s1.birth.day , s1.math);


	exit(0);
}

