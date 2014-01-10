#include<cstdio>
#include<algorithm>
using namespace std;
int h[20001];

int main()
{
    int N, B;
    scanf("%d %d", &N, &B);
    int i;
    for(i=0; i<N; i++)
        scanf("%d", &h[i]);
    sort(h, h+N);
    int sum = 0;
    for(i=N-1 ; i>=0; i--)
    {
        sum += h[i];
        if( sum >= B )
            break;
    }
    printf("%d\n", N-i);
    return 0;
}
