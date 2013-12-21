//lis
#include <stdio.h>
#include <string.h>
#define MAX_N 1005
#define MAX(a, b) (a>b?a:b)

int n;
float heights[MAX_N];
int lis[MAX_N];
int lds[MAX_N];
void init()
{
    int i;
    for(i=1; i<=n; i++)
        lis[i] = 1;

    for(i=1; i<=n; i++)
        lds[i] = 1;
    lds[n+1] = 0;
    lis[0] = 0;
}

void get_lis_lds()
{
    int i, j;
    for(i=2; i<=n; i++)
        for(j=1; j<i; j++)
            if( heights[i] > heights[j] )
                lis[i] = MAX(lis[i], lis[j]+1); 

    for(i=n-1; i>=1; i--)
        for(j=n; j>i; j--)
            if( heights[i] > heights[j] )
                lds[i] = MAX(lds[i], lds[j]+1);
}

int solve()
{   
    int i, j, result = 0, li = 0, ld;
    for(i=0; i<=n; i++)
    {
        li = MAX(li, lis[i]);
        for(j=i+1, ld=0; j<=n; j++)
            ld = MAX(ld, lds[j]);
        result = MAX(result,li+ld); 
    }
    return (n-result);
}

int main()
{
    scanf("%d", &n);
    int i;
    for(i=1; i<=n; i++)
        scanf("%f", &heights[i]);
    init();
    get_lis_lds();
    int ans = solve();
    printf("%d\n", ans);
    return 0;
}
