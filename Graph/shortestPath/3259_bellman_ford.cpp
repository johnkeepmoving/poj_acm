#include<cstdio>
#include<cstring>
using namespace std;
#define MAX_TIME 25000000
struct Edge{
    int s, e, t;
};

int F, N, M, W;
int edge_num;
Edge edge[5500];
int time[501];

bool bellman_ford()
{
    int i, j;
    bool over; 
    for(i=1; i<N+1; i++)
    {
        over = true;
        for(j=1; j<edge_num; j++)
        {
            if( time[edge[j].e] > (time[edge[j].s] + edge[j].t) )
            {
                time[edge[j].e] = time[edge[j].s] + edge[j].t;
                over = false;
            }
        }
        if( over )
            break;
    }
    return over;
}

int main()
{
    scanf("%d", &F);
    int i, j;
    int temp_s, temp_e, temp_t;
    for(i=1; i<=F; i++)
    {
        memset(time, MAX_TIME, sizeof(time));
        time[1] = 0;
        scanf("%d%d%d", &N, &M, &W);
        edge_num = 1;
        for(j=1; j<=M; j++)
        {
            scanf("%d%d%d", &temp_s, &temp_e, &temp_t);
            edge[edge_num].s = temp_s;
            edge[edge_num].e = temp_e;
            edge[edge_num].t = temp_t;
            edge_num++;
            edge[edge_num].s = temp_e;
            edge[edge_num].e = temp_s;
            edge[edge_num].t = temp_t;
            edge_num++;
        }
        for(j=1; j<=W; j++)
        {
            scanf("%d%d%d", &temp_s, &temp_e, &temp_t);
            edge[edge_num].s = temp_s;
            edge[edge_num].e = temp_e;
            edge[edge_num].t = -temp_t;
            edge_num++;
        }
        if( bellman_ford() )
            printf("NO\n");
        else
            printf("YES\n");
    }
    return 0;
}
