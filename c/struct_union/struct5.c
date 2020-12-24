#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct	student 
{
	int id;
	char name[12];
	float math;
};

void show(struct student s1)
{
	printf("SHOW()::%ld\n",sizeof(s1));
	printf("%d %s %f\n",s1.id, s1.name, s1.math);
}
void show_(struct student *p)
{
	printf("SHOW_()::%ld\n",sizeof(p));
	printf("%d %s %f\n",p->id, p->name, p->math);
}

int main()
{
	struct student s1 = {10010,"Alan",98};

	printf("%ld\n",sizeof(s1));

	show(s1);
	show_(&s1);

	exit(0);
}

