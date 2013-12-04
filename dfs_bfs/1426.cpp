#include<cstdio>
#include<queue>
using namespace std;
#define num_type long long

queue<long long> q;
long long tmp;
int main()
{
    int n;
    while( (scanf("%d", &n) != -1 )&& (n != 0) )
    {
        q.push(1);
        while( !q.empty() )
        {
            tmp = q.front();
            q.pop();
            if( tmp % n == 0 )
            {
                printf("%d\n", tmp);
                break;
            }
            long long tt = tmp*10;
            q.push( tt );
            q.push( tt+1);
        }
        q = queue<long long>();
    }
    return 0;
}
