#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>

using namespace std;

typedef double DB;

DB p[1005][35];
DB f[1005][35][35];
DB g[1005][35];

int main()
{
    int n, m, t;
    while(scanf("%d%d%d", &m, &t, &n)!=EOF && (m!=0 || n!=0 || t!=0))
    {
        memset(p, 0, sizeof(p));
        for(int i=1; i<=t; i++)
            for(int j=1; j<=m; j++)
                scanf("%lf", &p[i][j]);
        memset(f, 0, sizeof(f));
        for(int i=1; i<=t; i++)
        {
            f[i][1][1]=p[i][1];
            f[i][1][0]=1-p[i][1];
        }
        for(int i=1; i<=t; i++)
            for(int j=2; j<=m; j++)
                for(int k=0; k<=j; k++)
                {
                    if(j>0) f[i][j][k]=f[i][j-1][k]*(1.0-p[i][j]);
                    if(k>0) f[i][j][k]+=f[i][j-1][k-1]*p[i][j];
                }
        memset(g, 0, sizeof(g));
        for(int i=1; i<=t; i++)
            for(int j=1; j<=m; j++)
                for(int k=1; k<=j; k++)
                    g[i][j]+=f[i][m][k];

        DB ans1=1.0;
        DB ans2=1.0;
        for(int i=1; i<=t; i++)
        {
            ans1*=g[i][m];
            ans2*=g[i][n-1];
        }
        printf("%.3lf\n",ans1-ans2);
    }
    return 0;
} 
