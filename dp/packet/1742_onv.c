#include <stdio.h>
#include <string.h>
#define MAX_N 105
#define MAX(a, b) ( a>b?a:b )
int n, m;
int sum;
int dp[100005];
int num[100005];
int main()
{
    int i, j, k, count;
    while ( scanf("%d %d", &n, &m) != -1 && n != 0 && m != 0)
    {
        count = 0;
        memset(dp, 0, sizeof(dp));
        int t_val[MAX_N]; 
        int t_num[MAX_N]; 
        for(i=1; i<=n; i++)
            scanf("%d", &t_val[i]);
        for(i=1; i<=n; i++)
            scanf("%d", &t_num[i]);
        dp[0] = 1;
        for(i=1; i<=n; i++)
        {
            memset(num, 0, sizeof(num)); 
            for(j=t_val[i]; j<=m; j++)
            {
                if( !dp[j] && dp[j-t_val[i]] && num[j-t_val[i]] < t_num[i] )
                {
                    dp[j] = 1;
                    count++;
                    num[j] = num[j-t_val[i]] + 1;
                }
            }
        }
        printf("%d\n", count);
    }
    return 0;
}
