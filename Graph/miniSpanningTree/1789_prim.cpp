#include<cstdio>
using namespace std;
#define MAX_TRUNK 2001
#define INF 200000000
int numTrunk;
char Trunks[MAX_TRUNK][8];
int dis[MAX_TRUNK];
bool select[MAX_TRUNK];
int numSelect;
short GetDistance(int i, int j)
{
    short ret = 0;
    for(int k=0; k<7; k++)
        if(Trunks[i][k] != Trunks[j][k])
            ret++;
    return ret;
}

int Prim()
{
    int ret = 0;
    for(int i=1; i<=numTrunk; i++)
    {
        dis[i] = INF;
        select[i] = false;
    }
    numSelect = 0;
    dis[1] = 0;
    for(int i=0; i<numTrunk; i++)
    {
        int minDis = INF;
        int minNode = -1;
        for(int j=1; j<=numTrunk; j++)
            if( !select[j] && dis[j] < minDis )
            {
                minDis = dis[j];
                minNode = j;
            }
        select[minNode] = true;
        numSelect++;
        ret += minDis; 
        for(int j=1; j<=numTrunk; j++)
            if( !select[j] )
            {
                int tmpDistance = GetDistance(minNode, j);
                if( tmpDistance < dis[j] )
                    dis[j] = tmpDistance;
            } 
    }
    return ret;
}

int main(int argc, const char *argv[])
{
    while( scanf("%d", &numTrunk)!= -1 && numTrunk != 0 )
    {
        for(int i=1; i<=numTrunk; i++)
            scanf("%s", Trunks[i]);

        int res = Prim();
        printf("The highest possible quality is 1/%d.\n", res);
    }
    return 0;
}
