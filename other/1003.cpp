#include<iostream>
using namespace std;

int getNum(float len)
{
	if ( len == 0.0 )
		return -1;
	float total_len=0.0;
	int n=2;
	while( total_len < len )
	{
		total_len += 1.0/n;
		n++;
	}
	return (n-2);
}


int main()
{
	float len;
	while( cin >> len )
	{
		int num = getNum( len);
		if ( num != -1)
			cout << num << " card(s)"<<endl;
		else
			cout <<"	" << endl;
	}
	return 0;
}
