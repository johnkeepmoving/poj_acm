#include<iostream>
using namespace std;
double PI = 3.141592654;
int main()
{
	int num;
	cin >> num;
	for( int i=1;i<=num;i++)
	{
		double area, x, y;
		cin >>x>>y;
		area = PI * (x*x + y*y);
		int restyear =(int)( area/100.0 + 1.0);
		cout<<"Property "<< i<<": This property will begin eroding in year "<< restyear << "."<<endl;
	}
	cout<<"END OF OUTPUT."<<endl;
	return 0;
}
