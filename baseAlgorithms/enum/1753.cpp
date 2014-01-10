#include<iostream>
using namespace std;
#define n 6
//false means balck pieces, true means white pieces
bool chess[n][n] = { false };//


int main()
{
	char pieces;
	for( int i=1; i<5; i++)
		for( int j=1; j<5; j++)
		{
			cin >> pieces;
			if ( pieces == 'w')
				chess[i][j] = true;
		}

	return 0;
}
