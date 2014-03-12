#include <iostream>
#include <map>
#include <cstring>
#include <cstdio>
using namespace std;

int target;
char numberChar[7];
int number[6];
int numLen;

map<int,int> ansCount;
int maxAns;//the best solution

int maxSlice[6];//the best soulution's every slice
int maxLen;//the best solution's slice num

int currSlice[6];
int currLen;
void dfs(int pre, int location, int sum)
{
    if (location >= numLen)
    {
        if (sum > target)
            return;
        if ( ansCount.count(sum)>0 ) 
            ansCount[sum]++;
        else
            ansCount[sum] = 1; 
        if (sum>maxAns)
        {
            //update the maxSlice, maxAns, maxLen
            for(int i=0; i<currLen; i++)
                maxSlice[i] = currSlice[i];
            maxLen = currLen;
            maxAns = sum;
        }
    }else
    {
        //cut
        int newSlice= pre*10 + number[location];
        currSlice[currLen++] = newSlice;
        dfs(0, location+1, sum+newSlice);
        currSlice[currLen--] = 0; 
        
        //not cut
        if (location<numLen-1)
        {
            int newPre= pre*10 + number[location];
            dfs(newPre, location+1, sum);
        }
    }
}

int main(int argc, const char *argv[])
{
    while( scanf("%d %s", &target, numberChar) )
    {
        if (target == 0 && numberChar[0] == '0' )
            break;
        
        numLen = strlen(numberChar);
        for(int i=0; i<numLen; i++)
            number[i] = numberChar[i] - '0';
        int num = 0;
        for(int i=0; i<numLen; i++)
            num = num*10 + number[i]; 
        if (num <= target)
        {
            printf("%d %d\n", num, num);
            continue;
        }

        ansCount.clear();
        maxAns = 0;
        memset(maxSlice, 0, sizeof(maxSlice));
        maxLen = 0;
        memset(currSlice, 0, sizeof(currSlice));
        currLen = 0;
        dfs(0, 0, 0);
        
        if ( ansCount[maxAns] == 1 )
        {
            printf("%d", maxAns);
            for(int i=0; i<maxLen; i++)
                printf(" %d", maxSlice[i]);
            printf("\n");
        } else if (ansCount[maxAns]> 1)
            printf("rejected\n");
        else
            printf("error\n");
    }
    return 0;
}
