#include <stdio.h>
#include <string.h>
#define MAX_W 12885
#define MAX_N 3405
#define max(a, b) ( (a>b)?(a):(b) ) 

int dp[MAX_W];
int weight[MAX_N];
int desir[MAX_N];
int N, M;

int get_ans()
{
    int i,j;
    for(i=1; i<=N; i++)
        for(j=M; j>=weight[i]; j--)
            dp[j] = max(dp[j], dp[ j - weight[i] ] + desir[i]);
    return dp[M];
}

int main()
{
    scanf("%d %d", &N, &M);
    memset(dp, 0, sizeof(dp));
    int i;
    for(i=1; i<=N; i++)
        scanf("%d %d", &weight[i], &desir[i]);
    int res = get_ans();
    printf("%d\n", res);
/*
#include<stdio.h>

#define MAX(a, b) ( a>b? a:b )

int v[3500];
int w[3500];
int dp[13000];
int sum_iton[3500];
int main()
{
    int N, M;
    scanf("%d %d", &N, &M);
    memset(dp, 0, sizeof(dp));
    
    int i, j;
    for(i=1; i<=N; i++)
        scanf("%d %d", &w[i], &v[i]);
    sum_iton[N+1] = 0;
    for(i=N; i>=1; i--)
    {
        sum_iton[i] = sum_iton[i+1] + w[i];
    }
    for(i=1; i<=N; i++)
    {
        int bound = MAX( M - sum_iton[i], w[i]);
        for(j=M; j>=bound; j--)
            dp[j] = MAX(dp[j-w[i]]+v[i], dp[j]);
    }
    printf("%d\n", dp[M]);
*/    
    return 0;
}
