#include <cstdio>
using namespace std;
#define MAX_STU 50005
int numStu;
int numGroup;
int fatherNode[MAX_STU], nodeNum[MAX_STU];
int maxNum;

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
    maxNum--;
}

int main(int argc, const char *argv[])
{
    int caseNum = 1;
    while( scanf("%d %d", &numStu, &numGroup) != -1 && 
            !( numGroup == 0 && numStu == 0) )
    {
        makeSet(numStu);
        maxNum = numStu;
        int firstNode;
        int secondNode; 
        for(int i=1; i<=numGroup; i++)
        {
            scanf("%d %d", &firstNode, &secondNode);
            unionSet(firstNode, secondNode);
        }
        printf("Case %d: %d\n", caseNum++, maxNum); 
    }
    return 0;
}
