#include <iostream>
#include <thread>
using namespace std;

unsigned long long start=0;
unsigned long long  end=0;

int count_odd()
{
	unsigned long long count=0;
	for (int i = 1; i < 1e9; i+=2)
	{
		start+=i;
	}
}
int count_even()
{
	unsigned long long count=0;
	for (int i =2; i < 1e9; i+=2)
	{
		end+=i;
	}
}




int main()
{
 	thread t1(count_even);
 	thread t2(count_odd);
 	t1.join();
 	t2.join();
 	cout<<"even sum is :-"<<start<<endl;
 	cout<<"odd sum is :-"<<end<<endl;

}