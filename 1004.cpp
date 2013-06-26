#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
	float money_month = 0.0;
	float money_total = 0.0;
	for(int i=1;i<=12;i++)
	{
		cin >> money_month;
		money_total += money_month;
	}
	cout<<fixed<<setprecision(2)<<"$"<<money_total/12.0<<endl;
	return 0;
}
