#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define NAMEMAX		128

struct	student 
{
	int id;
	char *name;
	float math;
};

void menu()
{
	printf("\n---MENU---\n1 SET\n2 CHANGE NAME\n3 SHOW\nPlease enter(q for quit):");
}

void set(struct student *p)
{
	printf("Please enter:");	
	scanf("%d%s%f",&p->id, p->name ,&p->math);
}

void changename(struct student *p)
{
	printf("Please enter the NEWNAME:");
	scanf("%s",p->name);
}

void show(struct student *p)
{
	printf("%d %s %f\n",p->id, p->name, p->math);
}

int main()
{
	struct student s1 = {0,"",0};
	int nu;

	while(1)
	{
		menu();
		if(scanf("%d",&nu) != 1)
			break;

		switch(nu)
		{
			case 1:
				set(&s1);
				break;
			case 2:
				changename(&s1);
				break;
			case 3:
				show(&s1);
				break;
			default:
				break;
		}
		sleep(1);
	}
	exit(0);
}

