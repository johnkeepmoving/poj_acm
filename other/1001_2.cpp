// algorithm_first.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<iomanip>
using namespace std;
int point;
void wipe_tail_0(char number[])
{
	int tail = strlen( number ) -1;
	while( number[tail] == '0' )
	{
		number[tail] = 0;
		tail--;
	}
}
void multi(char a[], char b[])//a= a*b
{
	int count[300] ={ 0 };
	int sum;
	int i,j,k;
	for( i=strlen(b)-1; i>=0; i--)
	for( j=strlen(a)-1, k=i+j+1; j>=0; j--, k--)
	{
		sum = (b[i] -'0')*(a[j] - '0')+ count[k];
		count[k] = sum%10 ; 
		count[k-1] += sum/10;
	}
	k = 0;
	while(count[k] == 0 ) k++;
	int len = strlen(a) + strlen(b) -1;
	for( k, i=0;k <= len; k++,i++)
	{	
		a[i] = '0'+ count[k];
	}
	a[i] = 0;
}
void get_value_and_point( char number[])
{
	int i;
	for(i=0;i<strlen(number);i++) if(number[i] == '.') break;
	if( i != strlen(number) ) //has point
	{
		i =strlen(number) - 1;
		point = 0;
		while( (number[i] != '.' ) && ( i > 0 ) )
		{
			point++;
			i--;
		}
		i = 0;
		if( number[i] == '0' ) //0.0123
		{
			for( i=2;i<strlen(number);i++)
				if( number[i] != '0' )
				{
					strcpy( number, &number[i]);
					break;
				}
		}//10.234
		else
		{
			for( i=strlen(number)-point-1;i<strlen(number)-1;i++)
			{
				number[i] = number[i+1];
			}
			number[i] = 0;
		}
	}
}
void show(char a[])
{
	int i;
	if( point >= strlen(a)) cout<<'.'<<setfill('0')<<setw(point)<<a<<endl;
	else
	{
		for( i=0;i<strlen(a);i++)
		{
			if( i == strlen(a)-point ) {cout<<'.'<<&a[i];break;}
			else
				cout<<a[i];
		}
		cout<<endl;
	}
}
int main()
{
	char number[7];//number have 6
	int power;
	while(cin>>number>>power)
	{
		if( power == 0 )
		{
			cout<<1<<endl;
		}	
		char result[150] = { 0 };
		point = 0;
		wipe_tail_0( number );
		get_value_and_point( number );

		strcpy( result, number);
		int i;
		for(i=2; i<= power;i++)
			multi( result, number);
		point *= power;
		show( result);
	}
}