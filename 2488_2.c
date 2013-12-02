#include<stdio.h>

int mark[26][26];
char res[53];
int next[8][2] = { -2, -1, -2, 1, -1, -2, -1, 2, 1, -2, 1, 2, 2, -1, 2, 1};

int p, q;

int dfs(int x, int y, int mark_num)
{
    if( mark_num == p*q ) return 1;
    int i;
    for(i=0; i<8; i++)
    {
        int x1 = x + next[i][0];
        int y1 = y + next[i][1];

        if( 0<=x1 && x1<q && 0<=y1 && y1<p && mark[x1][y1] != 1 )
        {
            mark[x1][y1] = 1;
            res[mark_num << 2] = x1 + 'A';
            res[mark_num << 2 + 1] = y1 + '1';
            if( dfs(x1, y1, mark_num+1) == 1 )
                return 1;
            mark[x1][y1] = 0;
        } 
    }
    return 0;
}

int main()
{
    int num_case;
    scanf("%d", &num_case);
    int i=1;
    while( i<=num_case )
    {
        scanf("%d %d", &p, &q);
        res[0] = 'A';
        res[1] = '1';
        if (dfs(0, 0, 1) == 1)
        {
            printf("Scenario #%d:\n", i);
            res[(p*q) << 2] = '\0';
            printf("%s\n\n", res);
        }
        else
            printf("Scenario #%d:\nimpossible\n\n", i);
        //after deal
        i++;
    }
    return 0;
}
