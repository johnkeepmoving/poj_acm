//lcis
#include <cstdio>
#include <cstring>
#define INT_MIN 0x80000000
#define MAX(a, b) (a>b?a:b)
#define MAX_NUM 501
int data1[MAX_NUM];
int data2[MAX_NUM];
int len1;
int len2;
int dp[MAX_NUM][MAX_NUM];
int pre[MAX_NUM][MAX_NUM];
int res[MAX_NUM];

void getLCIS()
{
    int ans = 0;
    int lastIndex = 0;
    dp[0][0] = 0;
    for(int i=1; i<=len1; i++)
    { 
        int ma=0, last=0;
        for(int j=1; j<=len2; j++)
        {
            if (data1[i] == data2[j])
            {
                dp[i][j] = ma + 1;
                pre[i][j] = last;
            }
            else
                dp[i][j] = MAX(dp[i][j],dp[i-1][j]);
            if (data2[j]<data1[i] && ma<dp[i-1][j])
            {
                ma = dp[i-1][j];
                last = j;
            }
            if (ans < dp[i][j])
            {
                ans = dp[i][j];
                lastIndex = j;
            }
        }
    }
    printf("%d\n", ans);
    int p=0, x=len1;
    while( ans-- )
    {
        res[++p] = data2[lastIndex];
        while( data1[x] != data2[lastIndex] ) x--;
        lastIndex = pre[x][lastIndex];
        x--;
    }
    for(int i=p; i>=1; i--) printf("%d ", res[i]);
    printf("\n");
}
int main()
{
    memset(dp, 0, sizeof(dp));
    scanf("%d", &len1);
    for(int i=1; i<=len1; i++)
        scanf("%d", &data1[i]);
    scanf("%d", &len2);
    for(int i=1; i<=len2; i++)
        scanf("%d", &data2[i]);
    data2[0] = INT_MIN;
    getLCIS(); 
    return 0;
}
