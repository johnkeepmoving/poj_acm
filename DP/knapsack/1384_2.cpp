#include<iostream>
#include<cstdio>
using namespace std;
#define MIN(a,b) (a<b?a:b)

int nCases;
int nPack, nVolume1, nVolume2, nVolume;
int weight[510], value[510];
int record[10001];
const int INF = 1000000001;
int main()
{
    int i, j;
    scanf("%d", &nCases);
    while (nCases--) {
	    scanf("%d %d", &nVolume1, &nVolume2);
	    nVolume = nVolume2 - nVolume1;
        for(i=1; i<=nVolume; i++)
            record[i] = INF;

        scanf("%d", &nPack);
        for(i=1; i<=nPack; i++)
            scanf("%d %d", &value[i], &weight[i]);
        
        for(i=1; i<=nPack; i++)
            for(j=weight[i]; j<=nVolume; j++)
                record[j] = MIN(record[j], record[j-weight[i]] + value[i]);
        if (record[nVolume] == INF)
            printf("This is impossible.\n");
        else
            printf
            ("The minimum amount of money in the piggy-bank is %d.\n",
             record[nVolume]);
    }
    return 0;
}
