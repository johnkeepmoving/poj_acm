#include<cmath>
#include<queue>
#include<cstdio>
#include<cstring>
using namespace std;
#define RANGE_MAX 9999

queue<int> q;
int stat[RANGE_MAX];
int prime(int number)
{
    int i;
    int bound = sqrt( number );
    for(i=2; i<= bound; i++)
        if( number % i == 0)
            break;
    if( i <= bound )
        return 0;
    else
        return 1;
}

int main()
{
    int src, dst;
    int num_case;
    scanf("%d", &num_case);
    while( num_case-- )
    {
        scanf("%d%d", &src, &dst);
        memset(stat, -1, sizeof(stat));
        q.push(src);
        stat[src] = 0;
        while( !q.empty() )
        {
            src = q.front();
            q.pop();
            if( src == dst )
            {
                printf("%d\n", stat[src]);
                break;
            }
            
            int i;
            for(i=0; i<=9; i++)
            {
                int tmp;
                tmp = src /10 *10 + i;
                if( (stat[tmp] == -1) && (prime(tmp) == 1) )
                {
                    q.push(tmp);
                    stat[tmp] = stat[src] + 1;
                }

                tmp = src/100 *100 + i*10 + src%10; 
                if( (stat[tmp] == -1) && (prime(tmp) == 1) )
                {
                    q.push(tmp);
                    stat[tmp] = stat[src] + 1;
                }
                
                tmp = src/1000 *1000 + i*100 + src%100; 
                if( (stat[tmp] == -1) && (prime(tmp) == 1) )
                {
                    q.push(tmp);
                    stat[tmp] = stat[src] + 1;
                }
                
                tmp = i*1000 + src%1000; 
                if( (stat[tmp] == -1) && (prime(tmp) == 1) && ( tmp >= 1000))
                {
                    q.push(tmp);
                    stat[tmp] = stat[src] + 1;
                }
            }
        }
    
        memset(stat, -1, sizeof(stat));
        q = queue<int>();
    }
    return 0;
}
