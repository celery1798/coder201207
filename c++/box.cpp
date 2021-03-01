#include <iostream> 
using namespace std;


//public  protected  private

class Box
{
public:
	void GetValue();
	int ShowVolume();
private:
	int	length,width,height;
};

void Box::GetValue()
{
	cin >> length >> width >> height;
}
int Box::ShowVolume()
{
	return length * width * height;
}

int main()
{
	
	Box b0;

	b0.GetValue();

	cout << "VOLUME : " << b0.ShowVolume() << endl;


	return 0;
}






