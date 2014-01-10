#include <cstdio>
#include <cstring>
using namespace std;

struct Edge
{
    int s,e;
    double r;
    double c;
}edge[210];

int pe;
int N,M,S;
double V;
double dis[110];

//if graph has loops
bool bellman_loop()
{
    bool sign;

    memset(dis,0,sizeof(dis));
    dis[S]=V;
    for(int j=0;j<N+1;j++)
    {
        sign=false;
        for(int i=0;i<pe;i++)
            if(dis[edge[i].e]<(dis[edge[i].s]-edge[i].c)*edge[i].r)
            {
                dis[edge[i].e]=(dis[edge[i].s]-edge[i].c)*edge[i].r;
                sign=true;
            }
        if(!sign)
            break;
    }
    if(sign)
        return true;
    else
        return false;
}

int main()
{
    while(scanf("%d%d%d%lf",&N,&M,&S,&V) != EOF)
    {
        pe=0;
        int a,b;
        double rab,cab,rba,cba;

        for(int i=0;i<M;i++)
        {
            scanf("%d%d%lf%lf%lf%lf",&a,&b,&rab,&cab,&rba,&cba);
            edge[pe].s=a;
            edge[pe].e=b;
            edge[pe].r=rab;
            edge[pe++].c=cab;
            edge[pe].s=b;
            edge[pe].e=a;
            edge[pe].r=rba;
            edge[pe++].c=cba;
        }
        if(bellman_loop())
           printf("YES\n"); 
        else
           printf("NO\n"); 
    }
    return 0;
}
