#include <iostream> 
#include <cstring> 
using namespace std;

class Person
{
	public:
		Person(int i=0,char *n=NULL,float m=0);
		Person(const Person &);
		~Person();
		void ShowInfo();
		void ChangeName(char *newname);
	private:
		int id;
		char *name;
		float math;
};

Person::Person(int i,char *n,float m)
{
	id = i;
	math = m;
	name = new char[strlen(n)+1];
	/*if error*/
	strcpy(name,n);
}

Person::Person(const Person &other)
{
	id = other.id;
	math = other.math;
	name = new char[strlen(other.name)+1];
	strcpy(name,other.name);
}

Person::~Person()
{
	delete []name;
}

void Person::ShowInfo()
{
	cout << id << " " << name << " " << math << endl;
}

void Person::ChangeName(char *newname)
{
	delete []name;

	name = new char[strlen(newname)+1];
	strcpy(name,newname);
	
}

int main()
{
	char name[] = "Alan";
	char name1[] = "Celery";

	Person p1(10010,name,99);

	p1.ShowInfo();

	p1.ChangeName(name1);

	p1.ShowInfo();


	return 0;
}



