#include <iostream> 
using namespace std;
//父类 子类      基类 派生类    多层派生   多重派生
/*
				public			protected		private
public:			public			protected		-
protected:		protected		protected		-
private:		private			private			-


*/

class A
{
	public:
		A()	{	cout << "A()" << endl;}
		~A()	{	cout << "~A()" << endl;}
		void GetShowAA(){	ShowAA();	}
		void ShowA(){	cout << "A::" << a << endl;}
	protected:
		void ShowAA(){   cout << "A::" << a << endl;}
	private:
		int a;
};

class B: public A
{
	public:
		B(){	cout << "B()" << endl;	}
		~B(){	cout << "~B()" << endl;	}

		
};



int main()
{
	B x;

	x.a();

	return 0;
}



