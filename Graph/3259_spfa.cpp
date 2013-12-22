#include<cstdio>
#include<cstring>
#include<queue>

using namespace std;
#define MAX_TIME 25000000
#define MAX_FILEDS 501
struct Edge{
    int s, e, t;
};

int F, N, M, W;
int edge_num;
Edge edge[5500];

int time[MAX_FILEDS];
bool inq[MAX_FILEDS];
int num_enq[MAX_FILEDS];

queue<int> q;
bool spfa()
{
    int j;
    q.push(1);
    num_enq[1] = 1;
    inq[1] = true;
    while( !q.empty() )
    {
        int curr = q.front();
        q.pop();
        inq[curr] = false;
        for(j=1; j<edge_num; j++)
            {
                if( time[edge[j].e] > (time[edge[j].s] + edge[j].t) )
                {
                    time[edge[j].e] = time[edge[j].s] + edge[j].t;
                    num_enq[edge[j].e]++;
                    if( num_enq[edge[j].e] >= N )
                        return false;
                    if( !inq[edge[j].e] )
                    {
                        q.push(edge[j].e);
                        inq[edge[j].e] = true;
                    }
                }
            }
    }
    return true;
}

int main()
{
    scanf("%d", &F);
    int i, j;
    int temp_s, temp_e, temp_t;
    for(i=1; i<=F; i++)
    {
        memset(inq, 0, sizeof(inq));
        memset(num_enq, 0, sizeof(num_enq));
        memset(time, MAX_TIME, sizeof(time));
        while( !q.empty() )
           q.pop(); 
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
        if( spfa() )
            printf("NO\n");
        else
            printf("YES\n");
    }
    return 0;
}
