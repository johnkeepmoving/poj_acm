#include<cstdio>
#include<cmath>
using namespace std;
#define INF 200000000.0
#define MAX_N 201
#define MAX(a,b) (a>b?a:b)
#define MIN(a,b) (a<b?a:b)
#define DISTANCE(a,b) ( sqrt( (x[a]-x[b])*(x[a]-x[b]) + (y[a]-y[b])*(y[a]-y[b]) ) )

//suppose from node 1 to node x(1...n) there exists one path, then there is a max distance between adjacent nodes, MAX(path1)
//and because may be there exists many paths, so we want the MIN(MAX())
int n;
float d[MAX_N][MAX_N];
float dis[MAX_N]; //
int x[MAX_N], y[MAX_N];
bool visted[MAX_N];
float Dijkstra()
{
    for(int i=1; i<=n; i++)
    {
        dis[i] = d[1][i];
        visted[i] = false;
    }
    visted[1] = true;
    for(int i=2; i<n; i++)
    {
        //select the min dis
        float min_dis = INF;
        int min_node = -1;
        for(int j=1; j<=n; j++)
            if( !visted[j] && dis[j] < min_dis )
            {
                min_node = j;
                min_dis = dis[j];
            }
        if( min_node == -1 ) break;
        if( min_node == 2 ) return dis[2]; 
        visted[min_node] = true;

        //relaxing the adjacent edge
        for(int j=1; j<=n; j++)
            if( !visted[j] ) 
                dis[j] = MIN(dis[j], MAX(dis[min_node], d[min_node][j])); 
    }
    return dis[2];
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
        float ans = Dijkstra();
        printf("Scenario #%d\n", case_num++);
        printf("Frog Distance = %.3f\n\n",ans);
    }
    return 0;
}
