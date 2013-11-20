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
    return 0;
}
