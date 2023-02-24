#include <iostream>


using namespace std;

class rectangle
{
private :
	int length;
	int breath;
public:
	int area()
	{
		return length*breath;
	}
	int set_parameter(int x,int y)
	{
		length=x;
		breath=y;
	}
	int perimeter()
	{
		return (length+breath)*2;
	}
};


int main()
{
	rectangle r1;
	r1.set_parameter(5,8);
	rectangle *ptr =& r1;
	cout<<ptr->area();

}