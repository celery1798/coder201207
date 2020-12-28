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

int  set(struct student *p)
{
	char name[NAMEMAX];
	printf("Please enter:");	
	scanf("%d%s%f",&p->id, name ,&p->math);
	if(strlen(name) > NAMEMAX)
		return -1;
	
	p->name = malloc(strlen(name)+1);
	if(p->name == NULL)
		return -2;

	strcpy(p->name,name);	
	return 0;
}

int changename(struct student *p)
{
	char name[NAMEMAX];
	printf("Please enter the NEWNAME:");
	scanf("%s",name);
	if(strlen(name) > NAMEMAX)
       return -1;
	free(p->name);
	p->name = malloc(strlen(name)+1);
	if(p->name == NULL)
		return -2;
	strcpy(p->name,name);
	    return 0;
}

void show(struct student *p)
{
	printf("%d %s %f\n",p->id, p->name, p->math);
}

void init(struct student *p)
{
	p->id = p->math = 0;
	p->name = NULL;
}

void destroy(struct student *p)
{
	free(p->name);
}

int main()
{
	struct student s1 ;
	int nu;
	
	init(&s1);

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
	destroy(&s1);

	exit(0);
}

