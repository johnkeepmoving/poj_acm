#include<stdio.h>

int g_queue[300000];
int g_count[300000];
int g_stat[300000];
int g_n, g_head, g_tail;

void Enq(int x)
{
    g_queue[g_head++] = x;
}

int Deq()
{
    return g_queue[g_tail++];
}

int Que_Empty()
{
    if(g_head == g_tail)
        return 1;
    return 0;
}

int main()
{
    int src, dst, tmp;
    while( scanf("%d%d", &src, &dst) != -1 )
    {
        g_head = 0;
        g_tail = 0;
        memset( g_stat, 0, sizeof(g_stat) );
        memset( g_count, 0, sizeof(g_count) );
        memset( g_queue, 0, sizeof(g_queue) );
        Enq( src );
        g_stat[src] = 1;
        while( !Que_Empty() )
        {
            src = Deq();
            if( src == dst )
            {
                printf("%d\n", g_count[src]);
                break;
            }
            tmp = src + 1;
            if( tmp <= 100000 && g_stat[tmp] == 0)
            {
                g_stat[tmp] = 1;
                g_count[tmp] = g_count[src] + 1;
                Enq( tmp );
            }
            tmp = src - 1;
            if( tmp >= 0 && g_stat[tmp] == 0 )
            {
                g_stat[tmp] = 1;
                g_count[tmp] = g_count[src] + 1;
                Enq( tmp );
            }
            tmp = 2*src;
            if( tmp <= 100000 && g_stat[tmp] == 0 )
            {
                g_stat[tmp] = 1;
                g_count[tmp] = g_count[src] + 1;
                Enq( tmp );
            }
        }
    }
    return 0;
}
