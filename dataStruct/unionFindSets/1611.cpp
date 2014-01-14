#include <cstdio>
using namespace std;
#define MAX_STU 30005
int numStu;
int numGroup;
int fatherNode[MAX_STU], nodeNum[MAX_STU];

void makeSet(int number)
{
    for(int i=0; i<number; i++)
    {
        fatherNode[i] = i;
        nodeNum[i] = 1;
    }
}

int findSet(int num)
{
    if ( num != fatherNode[num] )
        fatherNode[num] = findSet( fatherNode[num] );
    return fatherNode[num];
}

void unionSet(int num1, int num2)
{
    num1 = findSet(num1);
    num2 = findSet(num2);
    if ( num1 == num2 ) return;
    if ( nodeNum[num1] > nodeNum[num2] )
    {
        fatherNode[num2] = num1;
        nodeNum[num1] += nodeNum[num2];
    }
    else
    {
        fatherNode[num1] = num2;
        nodeNum[num2] += nodeNum[num1];
    }
}

int main(int argc, const char *argv[])
{
    while( scanf("%d %d", &numStu, &numGroup) != -1 && 
            !( numGroup == 0 && numStu == 0) )
    {
        makeSet(numStu);
        int totalNum;
        int firstNode;
        int stuNum; 
        for(int i=1; i<=numGroup; i++)
        {
            scanf("%d %d", &totalNum, &firstNode);
            for(int j=1; j<totalNum; j++)
            {
                scanf("%d", &stuNum);
                unionSet(firstNode, stuNum);
            }
        }
        printf("%d\n", nodeNum[findSet(0)]);
    }
    return 0;
}
