#include <iostream> 
using namespace std;


/*
new  delete 
会隐式的调用构造及析构方法 
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
	Clock *p = new Clock;
	
	delete p;

	return 0;
}


