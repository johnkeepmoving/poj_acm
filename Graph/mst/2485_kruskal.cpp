#include<cstdio>
#include <cstdlib>
using namespace std;
#define MAX_TOWN 501
#define INF 200000000

struct Edge{
    int x, y;
    int weight;
};

int numTowns;
int edge_num;
int distance[MAX_TOWN][MAX_TOWN];
int set[MAX_TOWN];
Edge edge[MAX_TOWN*MAX_TOWN/2+1];
int get_set(int n)
{
    return set[n] == n? n:get_set(set[n]); 
}

int cmp(const void *a, const void *b)
{
    return ( (*(Edge *)a).weight - (*(Edge *)b).weight );
}

int Kruskal()
{
    for(int i=1; i<=numTowns; i++)
        set[i] = i;
    int longest_edge = 0;
    for(int i=0; i<edge_num; i++)
    {
        if( get_set(edge[i].x) != get_set(edge[i].y) )
        {
            if( longest_edge < edge[i].weight )
                longest_edge = edge[i].weight;
            set[get_set(edge[i].x)] = edge[i].y;
        } 
    }
    return longest_edge;
}

int main(int argc, const char *argv[])
{
    int numCase;
    scanf("%d", &numCase);
    for(int t=1; t<=numCase; t++)
    {
        scanf("%d", &numTowns);
        edge_num = 0;
        int tmp_distance;
        for(int i=1; i<=numTowns; i++)
            for(int j=1; j<=numTowns; j++)
            {
                scanf("%d", &tmp_distance);
                if( j>i )
                {
                    edge[edge_num].x = i;
                    edge[edge_num].y = j;
                    edge[edge_num].weight = tmp_distance;
                    edge_num++;
                }
            }
        qsort(edge, edge_num, sizeof(Edge), cmp); 
        int res = Kruskal(); 
        printf("%d\n", res);
    }
    return 0;
}
