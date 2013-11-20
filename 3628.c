#include<stdio.h>
char dp[20000000]; // 0 or 1
int w[21];

int main()
{
    int N, B;
    int sum = 0;
    scanf("%d %d", &N, &B);
    int i, j;
    for(i=1; i<=N; i++)
    {
        scanf("%d", &w[i]);
        sum += w[i];
    }
    dp[0] = 1;
    for(i=1; i<=N; i++)
        for(j=sum; j>=w[i]; j--)
            if( dp[j-w[i]] ) dp[j] = 1;
    for(i=B; i<=sum; i++)
        if( dp[i] ) 
        {
            printf("%d\n", i-B);
            break;
        }
    return 0;
}
