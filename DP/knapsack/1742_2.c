#include <stdio.h>
#include <string.h>
#define MAX_N 105
#define MAX_NUMBER_BILLS 100005
#define MAX(a, b) ( a>b?a:b )
int n, m;
int sum;
int val[MAX_NUMBER_BILLS];
int dp[100005];

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
            sum = 0;
            if( t_val[i] > m ) continue; 
            if( t_num[i] * t_val[i] > m )
               for(j=t_val[i]; j<=m; j++)
                  dp[j] = MAX(dp[j], dp[j-t_val[i]]);  
            else
            {
                int alfa = 1;
                while ( (t_num[i] - alfa) >= 0 )
                {
                    t_num[i] -= alfa;
                    val[++sum] = alfa * t_val[i];
                    alfa *= 2;
                }
                if( t_num[i] )
                    val[++sum] = t_num[i] * t_val[i];
                for(j=1; j<=sum; j++)
                    for(k=m; k>=val[j]; k--)
                        dp[k] = MAX(dp[k], dp[k-val[j]]);
            }
        }
        for(i=m; i>=1; i--)
        {
            if( dp[i] == 1 )
                count++;
        }
        printf("%d\n", count);
    }
    return 0;
}
