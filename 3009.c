#include<stdio.h>
#include<string.h>

int w, h;
int sx, sy, ex, ey;
int best;
int maps[30][30];
int dir[4][2] = { {0,1}, {0,-1}, {-1,0}, {1,0} };

void dfs(int cx, int cy, int step)
{
    int nx, ny;
    if( step > best )
        return;
    int i;
    for(i=0; i<4; i++)
    {
        nx = cx + dir[i][0];
        ny = cy + dir[i][1];
        if( nx>=h || nx<0 || ny>=w || ny<0 || maps[nx][ny] == 1 )
            continue;
        while( nx>=0 && nx<h && ny>=0 && ny<w && maps[nx][ny] != 1 )
        {
            if( nx==ex && ny==ey )
            {
                if( step+1 < best )
                    best = step + 1;
                break;
            }
            nx += dir[i][0];
            ny += dir[i][1];
        }
        if( nx==ex && ny==ey )
            continue;
        if( nx>=0 && nx<h && ny>=0 && ny<w )
        {
            maps[nx][ny] = 0;
            dfs(nx-dir[i][0], ny-dir[i][1], step+1);
            maps[nx][ny] = 1;
        }
    }
}

int main()
{
    int i,j;
    int tmp;
    while( scanf("%d%d", &w, &h) != -1 && w && h)
    {
        best = 11;// >10
        for(i=0; i<h; i++)
            for(j=0; j<w; j++)
            {
                scanf("%d", &tmp);
                maps[i][j] = tmp;
                if( tmp == 2 )
                {
                    sx = i;
                    sy = j;
                }
                if( tmp == 3 )
                {
                    ex = i;
                    ey = j;
                }
            }
        dfs(sx, sy, 0);
        if( best <= 10 )
            printf("%d\n", best);
        else
            printf("-1\n");
    }
    return 0;
}
