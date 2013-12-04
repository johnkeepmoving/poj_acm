#include<stdio.h>
#include<string.h>
char chess[8][8];
int mark_row[8];
int n, k;
int C;
void dfs(int sum, int col)
{
    if( sum >= k )
    {
        C++;
        return;
    }
    if( col >= n )
        return;
    int i;
    for(i=0; i<n; i++)
    {
        if( chess[i][col] == '#' && !mark_row[i] )
        {
            mark_row[i] = 1;
            dfs(sum+1, col+1);
            mark_row[i] = 0;
        }
    }
    dfs(sum, col+1);
}
int main()
{
    while(scanf("%d %d", &n, &k) != -1 && n != -1)
    {
        C = 0;
        memset(mark_row, 0, sizeof(mark_row));
        getchar();
        int i, j;
        for(i=0; i<n; i++)
        {    
            for(j=0; j<n; j++)
                scanf("%c", &chess[i][j]);
            getchar();
        }
        dfs(0, 0);
        printf("%d\n", C);
    }
    return 0;
}
