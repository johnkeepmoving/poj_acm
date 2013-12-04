#include <stdio.h>
#include <string.h>
#define MAX_N 105
#define MAX_M 100005
#define max(a, b) (a>b?a:b)

int num[MAX_N];
int val[MAX_N];
int dp[MAX_M];

int n, m;

void ZeroOnePack(int cost, int weight)
{
    int v;
    for(v=m; v>=cost; v--)
        dp[v] = max(dp[v], dp[v-cost]+weight);
}

void CompletePack(int cost, int weight)
{
    int v;
    for(v=cost; v<=m; v++)
        dp[v] = max(dp[v], dp[v-cost]+weight);
}

void MultiplePacket(int cost, int weight, int num)
{
    if( cost * weight >= m )
    {
        CompletePack(cost, weight);
        return;
    }
    int k = 1;
    while( k<=num )
    {
        ZeroOnePack(cost*k, weight*k);
        num = num - k;
        k = k * 2;
    }
    if( num>0 ) ZeroOnePack(cost*num, weight*num);
}

void get_ans()
{
    int i, j, k;
    dp[0] = 1; 
    for(i=1; i<=n; i++)
        MultiplePacket(val[i], 0, num[i]);
}

int main()
{
    int i, j, count;
    while( scanf("%d%d", &n, &m) && (n*m != 0) )
    {
        count = 0;
        memset(dp, 0, sizeof(dp));
        for(i=1; i<=n; i++)
            scanf("%d", &val[i]);
        for(i=1; i<=n; i++)
            scanf("%d", &num[i]);
        get_ans();
        for(i=1; i<=m; i++)
            if( dp[i] == 1 ) count++;
        printf("%d\n", count);
    }
    return 0;
}
