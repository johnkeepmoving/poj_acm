#include<cstdio>
using namespace std;
#define MAX_TOWN 501
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
    int longestEdge = 0;
    for(int i=1; i<=numTowns; i++)
        if( longestEdge < edge[i] )
            longestEdge = edge[i];
    return longestEdge;
}

int main(int argc, const char *argv[])
{
    int numCase;
    scanf("%d", &numCase);
    for(int t=1; t<=numCase; t++)
    {
        scanf("%d", &numTowns);
        for(int i=1; i<=numTowns; i++)
            for(int j=1; j<=numTowns; j++)
                scanf("%d", &distance[i][j]);
        int res = Prim();
        printf("%d\n", res);
    }
    return 0;
}
