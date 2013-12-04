#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
using namespace std;

#define MOD 19999
vector<int> vec[MOD];
int snow[100005][6];

int isSame(int r1, int r2)// the index of snow row
{
    int text[12];
    memcpy(text, snow[r2], sizeof(int)*6);
    memcpy(text+6, snow[r2], sizeof(int)*6);
    int i,j=0;
    for(i=0; i<12; i++) //clockwise
    {
        if( snow[r1][j] == text[i])
            j++;
        else
            j = 0;
        if( j == 6 )
            return 1;
    }
    for(i=11; i>=0; i--) //clockwise
    {
        if( snow[r1][j] == text[i])
            j++;
        else
            j = 0;
        if( j == 6 )
            return 1;
    }
    return 0;
}

int main()
{
    int num, sum;
    if( scanf("%d", &num) == -1 )
        return -1;
    
    bool find = false;
    for(int i=0; i<num; i++)
    {
        sum = 0;
        for(int j=0; j<6; j++)
        {
            scanf("%d", &snow[i][j]);
            sum += snow[i][j];
        }
        sum = sum % MOD;
        for(int k=0; k<vec[sum].size(); k++)
        {
            if( isSame(vec[sum][k], i) )
            {
                find = true;
                break;
            }
        }
        if( find )
            break;
        else
            vec[sum].push_back(i);
    }
    if( find )
        printf("Twin snowflakes found.\n");
    else
        printf("No two snowflakes are alike.\n");
    return 0;
}
