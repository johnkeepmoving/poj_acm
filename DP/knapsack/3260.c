#include <stdio.h>
#include <string.h>
#define MAX_N 105
#define MAX_T 10125
#define MAX_V 125
#define MIN(a, b) (a<b?a:b)

int N, T;
int max_val = 0;
int up_bound;
int V[MAX_N];
int C[MAX_N]; 

int num[MAX_T];
int dp[MAX_T];
int change[MAX_V];

void get_change()
{
    change[0] = 0;
    int i, j;
    for(i=1; i<=N; i++)
        for(j=V[i]; j<=max_val; j++)
            if( change[j-V[i]] != -1 )
            {
                if( change[j] == -1 ) 
                    change[j] = change[j-V[i]]+1;
                else
                    change[j] = MIN(change[j], change[j-V[i]]+1);
            }
}
int main()
{

    while( scanf("%d %d", &N, &T) != -1 )
    {
        printf("/*********************/\nbegin a new case! N is %d, T is %d\n", N, T);
        //worst case is contains every coin
        memset(dp, -1, sizeof(dp));
        memset(change, -1, sizeof(change));
        
        int i, j;
        for(i=1; i<=N; i++)
        {
            scanf("%d", &V[i]);
            if( V[i] > max_val )
                max_val = V[i];
        }
        up_bound = T + max_val;
        for(i=1; i<=N; i++)
            scanf("%d", &C[i]);
        
        get_change(); 
        //first do multiPack!
        //haven't finished!
        //There is problem when cal dp
        dp[0] = 0;
        for(i=1; i<=N; i++)
        {
            memset(num, 0, sizeof(num));
            for(j=V[i]; j<=up_bound; j++)
            {
               if(num[j-V[i]] < C[i]  && dp[j-V[i]] != -1)
               {
                   num[j] = num[j-V[i]] + 1;
                   if(dp[j] == -1) 
                       dp[j] = dp[j-V[i]]+1;
                   else
                       dp[j] = MIN(dp[j], dp[j-V[i]]+1);
               } 
            }
        }
        for(i=1; i<=max_val; i++)
           printf("change %d is %d\n", i, change[i]); 
        for(i=1; i<=up_bound; i++)
            printf("dp %d is %d\n", i, dp[i]);
        int ans = -1;
        for(i=T; i<=up_bound; i++)
        {
            if(dp[i] != -1 && change[i-T] != -1 )
            {
                if ( ans == -1 )
                    ans = dp[i]+change[i-T];
                else
                    ans = MIN(ans, dp[i]+change[i-T]);
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
