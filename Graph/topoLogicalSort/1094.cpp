#include <cstdio>
#include <cstring>
using namespace std;
#define MAX_N 27

char topoSequence[MAX_N];
int inDegree[MAX_N];
bool expressions[MAX_N][MAX_N];
int numCharacter, numExpression;

int TopoLogicalSort()
{
    bool completeSort = true;
    memset(topoSequence, '\0', sizeof(topoSequence));
    memset(inDegree, 0, sizeof(inDegree));

    for(int i=1; i<=numCharacter; i++)
        for(int j=1; j<=numCharacter; j++)
            if( expressions[i][j] )
                inDegree[j]++;
    for(int i=1; i<=numCharacter; i++)
    {
        int nodeZeroID = 0;// node that inDegree is 0
        for(int j=1; j<=numCharacter; j++)
            if( inDegree[j] == 0 )
                if( nodeZeroID == 0 )
                    //first find a node, its inDegree is 0
                    nodeZeroID = j;
                else
                    // have another node, its inDegree is 0. So ,can't finsh
                    // because the relation between this two nodes is unkown 
                    completeSort = false;
        
        if( nodeZeroID == 0 ) return 0; // find loop
        inDegree[nodeZeroID] = -1;
        topoSequence[i-1] = nodeZeroID + 'A' - 1;
        for(int j=1; j<=numCharacter; j++)
            if( expressions[nodeZeroID][j] )
                inDegree[j]--;
    }
    if( completeSort ) return 1; // has no node which inDegree is 0
    else return 2; //expressions not enough
}

int main(int argc, const char *argv[])
{
    char inStr[4];
    char left, right;
    int result;
    while( scanf("%d%d", &numCharacter, &numExpression) && 
            !( numCharacter == 0 && numExpression == 0 ) )
    {

        bool finish = false;
        memset(expressions, false, sizeof(expressions));
        for(int i=1; i<=numExpression; i++)
        {
            scanf("%s", inStr);
            left = inStr[0] - 'A' + 1;
            right = inStr[2] - 'A' + 1;
            expressions[left][right] = true;
            if( finish )
                continue;
            result = TopoLogicalSort();
            if( result == 1 )
            {
                printf("Sorted sequence determined after %d relations: %s.\n",i,topoSequence);
                finish = true;
            }
            if( result == 0 )
            {
                printf("Inconsistency found after %d relations.\n",i);
                finish = true;
            }
        }
        if(!finish) printf("Sorted sequence cannot be determined.\n");
    }
    return 0;
}
