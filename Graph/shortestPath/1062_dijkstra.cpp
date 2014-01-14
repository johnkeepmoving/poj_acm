#include<cstdio>
#include<cstring>
using namespace std;
#define INF 200000000
#define MAX 101
int map[MAX][MAX], level[MAX], d[MAX], value[MAX];
bool within_lim[MAX], visted[MAX];
int lev_lim, n;

int Dijkstra()
{
    memset(visted, 0, sizeof(visted));
    for(int i=1; i<=n; i++)
        d[i] = (i == 1? 0:INF);
    for(int i=1; i<=n; i++)
    {
        int min_d = INF;
        int min_node;
        //get the min d from all visted nodes;
        for(int j=1; j<=n; j++)
            if( within_lim[j] && !visted[j] && d[j] < min_d)
            {
                min_node = j;
                min_d = d[j];
            }
        visted[min_node] = true;
        //relax the adjacent edge of min_node
        for(int j=1; j<=n; j++)
            if( within_lim[j] && (d[min_node] + map[min_node][j] < d[j]) )
            {
                d[j] = d[min_node] + map[min_node][j];
            }
    }
    int min_cost = INF;
    for(int i=1; i<=n; i++)
    {
        d[i] += value[i];//对于每个d[i]值，还需加上进入该结点的花费，再进行比较
        min_cost = ( d[i]<min_cost? d[i]:min_cost);
    }
    return min_cost;
}

int main()
{
    scanf("%d%d", &lev_lim, &n);
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            map[i][j] = ( i == j? 0 : INF);
    for(int i=1; i<=n; i++)
    {
        int t;
        scanf("%d%d%d", &value[i], &level[i], &t);
        for(int j=1; j<=t; j++)
        {
            int k;
            scanf("%d", &k);
            scanf("%d", &map[i][k]);
        }
    }
    //finish construct a map
    int king_level = level[1];
    int min_cost = INF;
    //enum available nodes 
    for(int i=0; i<=lev_lim; i++)
    {
        memset(within_lim, 0, sizeof(within_lim));
        for(int j=1; j<=n; j++)
           if( (king_level-lev_lim+i)<=level[j] && level[j] <= (king_level+i) )
               within_lim[j] = 1;
        int min_d = Dijkstra();
        if( min_d < min_cost ) 
            min_cost = min_d;
    }
    printf("%d\n", min_cost);
    return 0;
}
