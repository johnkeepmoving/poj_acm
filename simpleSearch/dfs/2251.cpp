#include <cstdio>
#include <cstring>
#define MAX 100000

struct Node
{
    int x, y, z;
    int step;
};

Node allNode[100005];

int next[6][3] = { {0,0,1}, {0,0,-1}, {0,1,0}, {0,-1,0}, {1,0,0}, {-1,0,0}};
int sx, sy, sz;
int ex, ey, ez;

int Level, Row, Column;
int totalStep;
int map[35][35][35];
int visted[35][35][35];

int judge(int x, int y, int z)
{
    if ( 0<=x && x<Level && 0<=y && y<Row && 0<=z && z< Column )
        return 1;
    else 
        return 0;
}

int bfs()
{
    int head = 0;
    int tail = 0; 
    allNode[head].x = sx;
    allNode[head].y = sy;
    allNode[head].z = sz;
    allNode[head].step = 0;
    tail++;

    int nx, ny, nz, nstep;
    while( head < tail )
    {
        int i;
        for(i=0; i<6; i++)
        {
            nx = allNode[head].x + next[i][0];
            ny = allNode[head].y + next[i][1];
            nz = allNode[head].z + next[i][2];

            if ( judge(nx, ny, nz) )
                if ( map[nx][ny][nz] && !visted[nx][ny][nz] )
                {
                    visted[nx][ny][nz] = 1;
                    nstep = allNode[head].step + 1;
                    if ( nx == ex && ny == ey && nz == ez )
                    {
                        totalStep = nstep;
                        return 1;
                    }
                    else
                    {
                        allNode[tail].x = nx;
                        allNode[tail].y = ny;
                        allNode[tail].z = nz;
                        allNode[tail].step = nstep;
                        tail++;
                    }
                }
        }
        head++;
    }
    return 0;
}

int main()
{
    char tmpINStr[40];
    while( scanf("%d%d%d", &Level, &Row, &Column) != EOF )
    {
        if ( Level == 0 && Row == 0 && Column ==0 )
            break;
        memset(map, 0, sizeof(map));
        memset(visted, 0, sizeof(visted));
        totalStep = 0;
        int i, j, k;
        for(i=0; i<Level; i++)
            for(j=0; j<Row; j++)
            {
                scanf("%s", &tmpINStr);
                for(k=0; k<Column; k++)
                {
                    if ( tmpINStr[k] == 'S' )
                    {
                        sx = i; sy = j; sz = k;
                        map[i][j][k] = 1;
                    } else if ( tmpINStr[k] == 'E' )
                    {
                        ex = i; ey = j; ez = k;
                        map[i][j][k] = 1;
                    } else if ( tmpINStr[k] == '#' )
                        map[i][j][k] = 0;
                    else
                        map[i][j][k] = 1;
                }
            }
        if ( bfs() )
            printf("Escaped in %d minute(s).\n", totalStep);
        else
            printf("Trapped!\n");
    }
    return 0;
}
