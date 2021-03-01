#include <iostream> 
using namespace std;

/*
构造函数:
作用:初始化某类的对象  
在一个对象被实例化生成时默认隐式调用
如果我们不写,系统会生成一个默认的构造函数
一旦我们自行实行,系统默认的那个就不会再生成
构造函数可以存在多个
特点:与类同名,无返回值,可传参,也无参

*/


class Clock
{
public:
	Clock();
	Clock(int,int,int);
	void SetTime(int ,int ,int );
	void ShowTime();
private:
	int hour;
	int minute;
	int second;
};

Clock::Clock()
{
	cout << "Clock()" << endl;
	hour = minute = second = 0;
}

Clock::Clock(int h,int m,int s)
{
	cout << "Clock(3*int)" << endl;
	hour = h;
	minute = m;
	second = s;
}
void Clock::SetTime(int h,int m,int s)
{
	hour = h;
	minute = m;
	second = s;
}
void Clock::ShowTime()
{
	cout << hour << ":" << minute << ":" << second << endl;
}

int main()
{
	
	Clock c1;
	Clock c2(8,8,8);

//	c1.SetTime(6,6,6);
	c1.ShowTime();
	c2.ShowTime();


	return 0;
}







