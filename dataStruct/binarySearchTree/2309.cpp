#include <cstdio>
using namespace std;

int main(int argc, const char *argv[])
{
    int num;
    int node;
    int tmp;
    int count = 0;
    int range;
    scanf("%d", &num);
    for(int i=1; i<=num; i++)
    {
        scanf("%d", &node);
        count = 0; 
        tmp = node;
        while(1)
        {
            if ( tmp&1 )
                break;
            count++;
            tmp = tmp >>1;
        }
        tmp = (1<<count)-1;
        printf("%d %d\n", node-tmp, node+tmp);
    } 
    return 0;
}
