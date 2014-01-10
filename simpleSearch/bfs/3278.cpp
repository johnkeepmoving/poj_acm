#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
#define MAX_RANGE 100000

int src, dst, next;
queue<int> que;
int stat[100001];
int main()
{
    while( scanf("%d%d", &src, &dst) != -1 )
    {
        memset(stat, -1, sizeof(stat));
        que.push(src);
        stat[src] = 0;
        while( !que.empty() )
        {
            src = que.front();
            que.pop();
            if( src == dst )
            {
                printf("%d\n", stat[src]);
                break;
            }

            next = src + 1;
            if( next <= MAX_RANGE && stat[next] == -1 )
            {
                stat[next] = stat[src] + 1;
                que.push(next);
            }

            next = src - 1;
            if( 0 <= next && next <= MAX_RANGE && stat[next] == -1 )
            {
                stat[next] = stat[src] + 1;
                que.push(next);
            }

            next = 2*src;
            if( next <= MAX_RANGE && stat[next] == -1 )
            {
                stat[next] = stat[src] + 1;
                que.push(next);
            }
        }
    }
    return 0;
}
