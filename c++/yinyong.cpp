#include <iostream> 
using namespace std;

int main()
{
	int i = 1;
	int &j = i;


	j = 100;

	cout << i << "   " << &i  << endl;
	cout << j << "   " << &j  << endl;


	return 0;
}

/*
C:
struct student_st  ->  40

func1(struct student_st s2);
func2(struct student_st *p);
int main()
{
	struct student_st s1;
	func1(s1);
	func2(&s1);

}


C++:
struct student_st  ->  40
func1(struct student_st s2);
func2(struct student_st *p);
func3(struct student_st &s2);
int main()
{
struct student_st s1;
func1(s1);
func2(&s1);
func3(s1);
}



*/




