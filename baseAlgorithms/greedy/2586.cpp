#include<cstdio>
using namespace std;

int s, d;
int totalSurplus;
int main()
{
    while( scanf("%d%d", &s, &d) != -1 )
    {
        if ( d > 4*s )
            totalSurplus = 10*s - 2*d;
        else if ( d > 1.5*s )
            totalSurplus = 8*s - 4*d;
        else if ( d > 2.0/3.0*s )
            totalSurplus = 6*s - 6*d;
        else if ( d > 1.0/4.0*s )
            totalSurplus = 3*s - 9*d;
        else
            totalSurplus = -12*d;
        if( totalSurplus > 0 )
            printf("%d\n", totalSurplus);
        else
            printf("Deficit\n");
    }
    return 0;
}
