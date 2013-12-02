#include <stdio.h>
#include <string.h>
#define MAX_N 22
#define MAX_SUM 2000001
#define MAX(a, b) ( (a>b?a:b) )

int N, B;
int heights[MAX_N];
int dp[MAX_SUM];
int sum;
void get_ans()
{
    int i, j;
    dp[0] = 1;
    for(i=1; i<=N; i++)
        for(j=sum; j>=heights[i]; j--)
            dp[j] = MAX(dp[j], dp[ j-heights[i] ]);
}

int main()
{
    sum = 0;
    memset(dp, 0, sizeof(dp)); 
    scanf("%d %d", &N, &B);
    int i;
    for(i=1; i<=N; i++)
    {
        scanf("%d", &heights[i]);
        sum += heights[i];
    }
    get_ans();
    for(i=B; i<=sum; i++)
    {
        if( dp[i] == 1 ) 
        {
            printf("%d\n", (i-B));
            break;
        }
    }
    return 0;
}
