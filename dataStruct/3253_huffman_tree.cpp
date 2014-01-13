#include <cstdio>
#include <queue>
using namespace std;
#define MAXPLANKS 20001

struct plank{
    int len;
    friend bool operator < (plank x, plank y)
    { 
        return (x.len > y.len);
    }
};
plank totalPlanks[MAXPLANKS];
int numPlanks;
int totalCost;

int main(int argc, const char *argv[])
{
    priority_queue<plank> pq;
    while( !pq.empty() ) pq.pop();
    
    scanf("%d", &numPlanks);
    for(int i=1; i<=numPlanks; i++)
    {
        scanf("%d", &totalPlanks[i].len);
        pq.push( totalPlanks[i] );
    }

    int num1, num2;
    plank tmpPlank;
    totalCost = 0;
    while ( pq.size() > 1 )
    {
        num1 = pq.top().len; pq.pop();
        num2 = pq.top().len; pq.pop();
        totalCost += (num1+num2);
        tmpPlank.len = num1+num2;
        pq.push( tmpPlank );
    }
    printf("%d\n", totalCost);
    return 0;
}
