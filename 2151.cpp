#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

#define MAX_TEAM_NUM 1001
#define MAX_PROBLEM 31

double p[MAX_TEAM_NUM][MAX_PROBLEM];
double f[MAX_TEAM_NUM][MAX_PROBLEM][MAX_PROBLEM];
double g[MAX_TEAM_NUM][MAX_PROBLEM];

int main()
{
    int N, M, T;
    while( (scanf("%d%d%d", &M, &T, &N) != -1) &&
            (M != 0 || T != 0 || N != 0) )
    {
        memset(p, 0, sizeof(double)*MAX_TEAM_NUM*MAX_PROBLEM);
        for(int i=1; i<=T; i++)
            for(int j=1; j<=M; j++)
                scanf("%lf", &p[i][j]);

        memset(f, 0, sizeof(double)*MAX_PROBLEM*MAX_PROBLEM*MAX_TEAM_NUM);
        for(int i=1; i<=T; i++)
        {
            f[i][1][1] = p[i][1];
            f[i][1][0] = 1 - p[i][1];
        }
        for(int i=1; i<=T; i++)
            for(int j=2; j<=M; j++)
                for(int k=0; k<=j; k++)
                {
                    f[i][j][k] =  f[i][j-1][k] * (1.0 - p[i][j]);
                    if( k >= 1 ) f[i][j][k] += f[i][j-1][k-1] * p[i][j];
                }
        memset(g, 0, sizeof(double)*MAX_PROBLEM*MAX_TEAM_NUM);
        for(int i=1; i<=T; i++)
            for(int j=1; j<=M; j++)
                for(int k=1; k<=j; k++)
                    g[i][j] += f[i][M][k];
        
        double ans1=1.0, ans2=1.0;
        for(int i=1; i<=T; i++)
        {
            ans1 *= g[i][M];
            ans2 *= g[i][N-1];
        }
        printf("%.3lf\n", (ans1-ans2) );
    }
    return 0;
}
