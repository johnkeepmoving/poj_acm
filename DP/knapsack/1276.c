#include <stdio.h>
#include <string.h>
#define MAX_CASH_NUMBER 100005
#define MAX_NUMBER_BILLS 10005
#define MAX(a, b) ( a>b?a:b )
int N, CASH;
int sum_bills;
int val[MAX_NUMBER_BILLS];
int dp[MAX_CASH_NUMBER];

void get_ans()
{
    int i, j;
    dp[0] = 1;
    for(i=1; i<=sum_bills; i++)
        for(j=CASH; j>=val[i]; j--)
            dp[j] = MAX(dp[j], dp[ j-val[i] ]);
}

int main()
{
    int i, j, k;
    while ( scanf("%d %d", &CASH, &N) != -1 )
    {
        if( N == 0)
        {
            printf("%d\n", 0);
            continue;
        }
        
        memset(dp, 0, sizeof(dp));
        sum_bills = 0;
        int t_num, t_val;
        for(i=1; i<=N; i++)
        {
            scanf("%d %d", &t_num, &t_val);
            if( t_num > 0 )
            {
                int alfa = 1;
                while( (t_num - alfa) >= 0 )
                {
                    t_num -= alfa;
                    val[++sum_bills] = alfa * t_val;
                    alfa *= 2;
                }
                if ( t_num )
                    val[++sum_bills] = t_num * t_val;
            }
        }
        if( CASH == 0 )
        {
            printf("%d\n", 0);
            continue;
        }
        get_ans();
        for(i=CASH; i>=0; i--)
        {
            if( dp[i] == 1 )
            {
                printf("%d\n", i);
                break;
            }
        }
    }
    return 0;
}
