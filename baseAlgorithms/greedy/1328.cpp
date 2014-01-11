#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
#define MAX_ISLANDS 1000
struct region
{
    double left, right;
};

int n, d;
region re[MAX_ISLANDS];

bool compare(region re1, region re2)
{
    return (re1.left - re2.left) < 0;
}

int greedy()
{
    int ans = 1;
    double pre = re[0].right;
    for(int i=1; i<n; i++)
    {
        if( (re[i].left - pre) > 0 )
        {
            ans++;
            pre = re[i].right;
        }else
        {
            if( (re[i].right - pre) < 0 )
                pre = re[i].right;
        }
    }
    return ans;
}

int main()
{
    int x, y;
    int cas = 0;
    while( scanf("%d%d", &n, &d) != -1 )
    {
        if( !n && !d )
            break;
        memset(re, 0, sizeof(re)); 
        bool impossible = false;
        for(int i=0; i<n; i++)
        {
            scanf("%d%d", &x, &y);
            if( !impossible && ( y<=d ) )
            {
                double tmp = sqrt(d*d - y*y);
                re[i].left = x - tmp;
                re[i].right = x + tmp;
            }
            else
                impossible = true;
        }
        if( impossible )
        {
            printf("Case %d: -1\n", ++cas);
            continue;
        }
        sort(re, re+n, compare);
        int result = greedy();
        printf("Case %d: %d\n", ++cas, result);
    }
    return 0;
}
