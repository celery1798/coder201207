#include <iostream> 
using namespace std;


/*
拷贝构造函数:
作用:初始化某类的对象  
在一个对象被实例化生成时由同类型的其他对象进行初始化时默认隐式调用
如果我们不写,系统会生成一个默认的拷贝构造函数
一旦我们自行实行,系统默认的那个就不会再生成
特点:与类同名,无返回值,参数为同类型的引用

*/


class Clock
{
public:
	Clock(int h=0,int m=0,int s=0);
	Clock(const Clock &);
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
Clock::Clock(const Clock &other)
{
	cout << "Clock(&)" << endl;
	hour = other.hour;
	minute = other.minute;
	second = other.second;
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
	Clock c3(10);
	Clock c4 = c3;


	return 0;
}

/*
int i = 1;
int j;
j  = i

int  i = 1;
int j = i;



*/





