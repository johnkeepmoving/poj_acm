#include <stdio.h>
#include <string.h>
#define max(a, b) (a>b?a:b)

int N;
char str[5005];
char rev_str[5005];
//short res[5005][5005];
short res[2][5005];

int lcs()
{
    int i, j; 
    for(i=1; i<=N; i++)
        for(j=1; j<=N; j++)
        {
            if ( str[i] == rev_str[j] )
            {
                res[i%2][j] = res[(i-1)%2][j-1] + 1;
            }
            else
            {
                res[i%2][j] = max(res[i%2][j-1], res[(i-1)%2][j]);
            }
        }
    return res[N%2][N];
}

int main()
{
    memset(res, 0, sizeof(res));
    scanf("%d", &N);
    getchar();
    int i;
    for(i=1; i<=N; i++)
       scanf("%c", &str[i]); 
    str[N+1] = '\0';
    for(i=1; i<=N; i++)
        rev_str[i] = str[N-i+1];
    rev_str[N+1] = '\0';
    
    int ans = lcs();
    printf("%d\n", (N-ans) ); 
    return 0;
}
