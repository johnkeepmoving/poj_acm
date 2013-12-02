#include<stdio.h>
#include<string.h>
#define MIN 50
#define MAX 10000

//C number of positions
//G number of weights
int C, G;
int val[MIN][MIN];
int dp[MIN][MAX*2];
int pos[MIN];

int hash(int x)
{
    if( x < 0 )
        return ( MAX - x);
    else
        return x;
}

int solve()
{
    int i, j, k;
    for(k=1; k<=C; k++)
        dp[1][hash(val[1][k])] = 1;
    for(i=2; i<=G; i++)
        for(j=8000; j>=-8000; j--)
            for(k=1; k<=C; k++)
                dp[i][hash(j)] += dp[i-1][hash(j-val[i][k])];
    return dp[G][0];
}

int main()
{
    scanf("%d%d", &C, &G);
    int i, j, k;
    for(i=1; i<=C; i++)
        scanf("%d", &pos[i]);
    for(i=1; i<=G; i++)
    {
        scanf("%d", &k);
        for(j=1; j<=C; j++)
            val[i][j] = k*pos[j];
    }
    
    int ans = solve();
    printf("%d\n", ans);
    return 0;
}
