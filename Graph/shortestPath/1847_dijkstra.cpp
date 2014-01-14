#include<cstdio>
#include<cstring>
using namespace std;
#define MAX_N 110
#define INF 100000000 
int N, A, B;
int intersection[MAX_N][MAX_N];
int ds[MAX_N];
bool relax[MAX_N];
int Dijkstra()
{  
    memset(relax, false, sizeof(relax));
    int i, j;
    for(i=1; i<=N; i++)
       ds[i] = intersection[A][i]; 
    ds[A] = 0;
    relax[A] = true; 
    for(i=1; i<=N; i++)
    {
        int min_value = INF;
        int min_node;
        for(j=1; j<=N; j++)
            if( !relax[j] && (ds[j]<=min_value) )
            {
                min_node = j;
                min_value = ds[min_node];
            }
        relax[min_node] = true;
        for(j=1; j<=N; j++)
        {
            if( intersection[min_node][j] < INF && 
                    (ds[min_node] + intersection[min_node][j]) < ds[j] )
            {
                ds[j] = ds[min_node] + intersection[min_node][j];
            }
        }
    }
    return ds[B]; 
}

int main()
{    
 
    scanf("%d%d%d", &N, &A, &B);
    int i, j, ki;
    for(i=1; i<=N; i++)
    {
        ds[i] = INF;
        for(j=1; j<=N; j++)
            intersection[i][j] = INF;
    }
    
    for(i=1; i<=N; i++)
    {
        scanf("%d", &ki);
        int temp;
        for(j=1; j<=ki; j++)
        {
           scanf("%d",&temp);
           if(j == 1)
               intersection[i][temp] = 0;
           else
               intersection[i][temp] = 1;
        }
    }
    int ans = Dijkstra();
    if( ans < INF )
        printf("%d\n", ans);
    else
        printf("-1\n");
    return 0;
}
