#include <iostream> 
#include <cstring> 
using namespace std;

int main()
{

	char *p = new char[128];

	if(p == NULL)
	{
		cout << "new error" << endl;
		return -1;
	}


	strcpy(p,"Alan");

	cout << p << endl;
	
	delete []p;

	return 0;
}



