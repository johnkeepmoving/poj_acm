#include<stdio.h>
#include<string.h>

int mark[26][26];
char path[53]; //26*2+1
int move[8][2] ={ -2, -1, -2, 1, -1, -2, -1, 2, 1, -2, 1, 2, 2, -1, 2, 1};
int n, p, q;

int dfs(int x, int y, int mark_num)
{
    if( mark_num == p*q ) return 1;
    int x1, y1;
    int i;
    for(i=0; i<8; i++)
    {
        x1 = x + move[i][0];
        y1 = y + move[i][1];

        if( 0<=x1 && x1<q && 0<=y1 && y1<p && mark[y1][x1] == 0)
        {
            mark[y1][x1] = 1;
            path[(mark_num<<1)] = x1 + 'A';
            path[(mark_num<<1)+1] = y1 + '1';
            if( dfs(x1, y1, mark_num+1) )
                return 1;
            mark[y1][x1] = 0;
        }
    }
    return 0;
}

int main()
{
    scanf("%d", &n);
    int i;
    for(i=1; i<=n; i++)
    {
        scanf("%d%d", &p, &q);
        memset(path, 0, sizeof(path));
        memset(mark, 0, sizeof(mark));
        mark[0][0] = 1;
        path[0] = 'A';
        path[1] = '1';

        if( dfs(0, 0, 1) )
        {
            printf("Scenario #%d:\n", i);
            printf("%s\n\n", path);
        }
        else
            printf("Scenario #%d:\nimpossible\n\n", i);
    } 
    return 0;
}
