#include<cstdio>
#include<cmath>
using namespace std;
#define MAX_N 201
#define MAX(a,b) (a>b?a:b)
#define MIN(a,b) (a<b?a:b)
#define DISTANCE(a,b) ( sqrt( (x[a]-x[b])*(x[a]-x[b]) + (y[a]-y[b])*(y[a]-y[b]) ) )

int n;
float d[MAX_N][MAX_N];
int x[MAX_N], y[MAX_N];

void Floyd()
{
    for(int k=1; k<=n; k++)
        for(int i=1; i<=n; i++)
            for(int j=1; j<=n; j++)
                d[i][j] = MIN(d[i][j], MAX(d[i][k], d[k][j]));
}

int main()
{
    int case_num = 1;
    while(scanf("%d", &n) != -1 && n != 0 )
    {
        for(int i=1; i<=n; i++)
            scanf("%d%d", &x[i], &y[i]);
        for(int i=1; i<=n; i++)
            for(int j=1; j<=n; j++)
                d[i][j] = DISTANCE(i, j); 
        //deal with
        Floyd();
        float ans = d[1][2];
        printf("Scenario #%d\n", case_num++);
        printf("Frog Distance = %.3f\n\n",ans);
    }

    return 0;
}
