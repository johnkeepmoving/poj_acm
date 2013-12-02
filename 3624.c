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
    return 0;
}
