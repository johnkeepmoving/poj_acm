/*
 * =====================================================================================
 *
 *       Filename:  3260.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05/09/2014 10:15:06 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  jiangheng , johnloveryan@gmail.com
 *        Company:  Institute Of Computing Technology Chinese Academy of Sciences
 *
 * =====================================================================================
 */

#include <cstdio>
#include <iostream>
using namespace std;
const int maxv = 20000;
const int maxn = 120;
const int INF = 1000001;

int value[maxn], amount[maxn];
int dp_give[maxv], dp_recive[maxv];
int n, V, T;

void zeroOnePack(int cost, int value, int dp[])
{
    for(int i=V; i>=cost; i--)
        dp[i] = min(dp[i], dp[i-cost]+value);
}

void completePack(int cost, int value, int dp[])
{
    for(int i=cost; i<=V; i++)
        dp[i] = min(dp[i], dp[i-cost]+value);
}

void multiPack(int cost, int value, int amount, int dp[])
{
    if (cost * amount > V)
    {
        completePack(cost, value, dp);
        return;
    }
    for(int i=1; i<=amount; i<<=1)
    {
        zeroOnePack(cost * i, value * i, dp);
        amount -= i;
    }
    zeroOnePack(cost*amount, value*amount, dp);
}

int solve()
{
    for(int i=1; i<=V; i++) dp_give[i] = INF;
    dp_give[0] = 0;
    for(int i=1; i<=n; i++)
        multiPack(value[i], 1, amount[i], dp_give);
    V -= T;
    for(int i=1; i<=V; i++) dp_recive[i] = INF;
    dp_recive[0] = 0;
    for(int i=1; i<=n; i++)
        completePack(value[i], 1, dp_recive);

    int minCent = INF;
    for(int i=0; i<=V; i++)
        if (dp_give[i+T] + dp_recive[i] < minCent)
            minCent = dp_give[i+T] + dp_recive[i];
    if (minCent == INF)
        return -1;
    else
        return minCent;
}

int main(int argc, const char *argv[])
{
    scanf("%d%d", &n, &T);
    V = T + 10000;
    for(int i=1; i<=n; i++)
        scanf("%d", &value[i]);
    for(int i=1; i<=n; i++)
        scanf("%d", &amount[i]);
    int ans = solve();
    printf("%d\n", ans);
    return 0;
}
