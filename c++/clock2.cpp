#include <iostream> 
using namespace std;


/*
析构函数:
作用:释放与恢复
在一个对象的生命周期即将终止的时候被隐式调用
如果没有自行实现,系统会为我们写一个默认的
一旦自行实行,系统中那个默认的就不会再生成
特点:与类同名,前面加~,无返回值,不允许传参

*/


class Clock
{
public:
	Clock(int h=0,int m=0,int s=0);
	~Clock();
	void SetTime(int ,int ,int );
	void ShowTime();
private:
	int hour;
	int minute;
	int second;
};

Clock::Clock(int h,int m,int s)
{
	cout << "Clock(3*int=0)" << endl;
	hour = h;
	minute = m;
	second = s;
}
Clock::~Clock()
{
	cout << "~Clock() hour = " << hour << endl; 
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
	Clock c3(10);

//	c1.SetTime(6,6,6);
	c1.ShowTime();

	{
		Clock c0(123);	
	}

	c2.ShowTime();
//	c3.ShowTime();


	return 0;
}







