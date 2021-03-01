#include <iostream> 
using namespace std;


//public  protected  private

class Clock
{
public:
	void SetTime(int h,int m,int s)
	{
		hour = h;
		minute = m;
		second = s;
	}
	void ShowTime();
private:
	int hour;
	int minute;
	int second;
};

void Clock::ShowTime()
{
	cout << hour << ":" << minute << ":" << second << endl;
}

int main()
{
	
	Clock c1;

	c1.SetTime(6,6,6);
	c1.ShowTime();


	return 0;
}

/*
struct clock_st
{
	int hour,minute,second;

	void (*settime)(int h,int m,int s);
	void (*showtime)();

};

struct clock_st c1;

c1.hour;
c1.settime = mysettime;

*/






