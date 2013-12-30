#include<cstdio>
using namespace std;
#define INF 200000000
#define MIN(a, b) ( a<b? a:b )
#define MAX_NUM_BROKER 101


int numBrokers;
int timeSpread[MAX_NUM_BROKER][MAX_NUM_BROKER];
void Floyd()
{
    for(int k=1; k<=numBrokers; k++)
        for(int i=1; i<=numBrokers; i++)
            for(int j=1; j<=numBrokers; j++)
                timeSpread[i][j] = 
                    MIN( timeSpread[i][j], (timeSpread[i][k]+timeSpread[k][j]) );
}

int main()
{
    while( scanf("%d", &numBrokers) != -1 && numBrokers != 0 )
    {
        int numPair;
        int destBroker;
        int time;
        for(int i=1; i<=numBrokers; i++)
            for(int j=1; j<=numBrokers; j++)
                timeSpread[i][j] = ( i == j ? 0:INF );
        for(int i=1; i<=numBrokers; i++)
        {
            scanf("%d", &numPair);
            for(int j=1; j<=numPair; j++)
            {
                scanf("%d%d", &destBroker, &time);
                timeSpread[i][destBroker] = time;
            }
        }
        Floyd();
        int brokerID = -1;
        int minTime = INF;
        for(int i=1; i<=numBrokers; i++)
        {
            int max = 0;
            for(int j=1; j<=numBrokers; j++)
                if( timeSpread[i][j] > max )
                    max = timeSpread[i][j];
            if( max < minTime )
            {
                minTime = max;
                brokerID = i;
            }
        }
        if (brokerID == -1)
            printf("disjoint\n");
        else
            printf("%d %d\n", brokerID, minTime);
    }
    return 0;
}
