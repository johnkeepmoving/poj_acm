#include<cstdio>
using namespace std;
#define MAX_TOWN 101 
#define INF 200000000

int numTowns;
int distance[MAX_TOWN][MAX_TOWN];
int d[MAX_TOWN];
bool select[MAX_TOWN];
int edge[MAX_TOWN];
int Prim()
{
    int ret = 0;
    for(int i=1; i<=numTowns; i++)
    {
        d[i] = distance[1][i];
        //d[i] = INF; 
        select[i] = false;
    }
    for(int i=1; i<=numTowns; i++)
    {
        int minDis = INF;
        int minNode = -1;
        for(int j=1; j<=numTowns; j++)
            if( !select[j] && d[j] < minDis )
            {
                minDis = d[j];
                minNode = j;
            }
        select[minNode] = true;
        ret += minDis;
        edge[i] = minDis;
        for(int j=1; j<=numTowns; j++)
            if( !select[j] && distance[minNode][j] < d[j] )
                d[j] = distance[minNode][j];
    }
    return ret;
}

int main(int argc, const char *argv[])
{
    while( scanf("%d", &numTowns) != -1 ) 
    {
        for(int i=1; i<=numTowns; i++)
            for(int j=1; j<=numTowns; j++)
                scanf("%d", &distance[i][j]);
        int res = Prim();
        printf("%d\n", res);
    }
    return 0;
}
