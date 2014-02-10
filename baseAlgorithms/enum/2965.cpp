#include <cstdio>
using namespace std;

int handles[5][5] = { 0 };
int flag;
int step;
int ansx[20];
int ansy[20];
int x[20];
int y[20];

bool judge_all()
{
    int i, j;
    for(i=1; i<5; i++)
        for(j=1; j<5; j++)
            if( handles[i][j] == 0 )
                return false;
    return true;
}

void switch_handles(int row, int col)
{
    int i;
    for(int i=1; i<5; i++)
    {
        handles[row][i] = 1 - handles[row][i];
    }
    for(int i=1; i<5; i++)
    {
        handles[i][col] = 1 - handles[i][col];
    }
    handles[row][col] = 1 - handles[row][col];
}

void dfs(int row, int col, int deep)
{
    if( deep == step )
    {
        flag = judge_all();
        if ( flag )
        {
            int i;
            for(i=0; i< step; i++)
            {
                ansx[i] = x[i];
                ansy[i] = y[i];
            }
        }
        return;
    }

    if (flag || row == 5) return;
    
    switch_handles(row, col);
    x[deep] = row;
    y[deep] = col;
    if (col < 4)
        dfs(row, col+1, deep+1);
    else
        dfs(row+1, 1, deep+1);

    switch_handles(row, col);
    if (col < 4)
        dfs(row, col+1, deep);
    else
        dfs(row+1, 1, deep);
}

int main()
{
    char tmp;
    int i, j;
    for( i=1; i<5; i++)
    {
        for( j=1; j<5; j++)
        {
            scanf("%c",&tmp);
            if( tmp == '-' )
                handles[i][j] = 1;
        }
        getchar();
    }
    for( step=0; step<=20; step++)
    {
        dfs(1, 1, 0);
        if ( flag ) break;
    }
    if ( flag )
    {
        printf("%d\n", step);
        int i;
        for(i=0; i<step; i++)
            printf("%d %d\n", ansx[i], ansy[i]);
    }
    return 0;
}
