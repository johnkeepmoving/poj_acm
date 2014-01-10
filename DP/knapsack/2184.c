#include<stdio.h>
#define MAX 100005
#define get_MAX(a, b) ( a>b? a:b )
int dp[2*MAX];
int s[101];
int f[101];

int main()
{
    int N;
    scanf("%d", &N);
    int i,j;
    for(i=1; i<=N; i++)
        scanf("%d %d", &s[i], &f[i]);
    for(i=1; i<=N; i++)
        if( s[i] > 0 )
            for(j=2*M-1; j>=s[i]; j--)
                dp[j] = get_MAX(dp[j-s[i]]+f[i], dp[j]);
        else
            for(j=)
    return 0;
}
