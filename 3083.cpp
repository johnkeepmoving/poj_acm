#include<iostream>
#include<queue>
#include<cstdio>
#include<cstring>
using namespace std;

char Maze[44][44] = { 0 };
int dirL[4][2] = { {0,1}, {1,0}, {0,-1}, {-1,0}};
int dirR[4][2] = { {0,1}, {-1,0}, {0,-1}, {1,0}};
int sr, sc, er, ec, w, h;
bool vis[44][44];

struct Point
{
    int r, c, step;
} node[42][42];


int dfs(int r, int c, int way, int dir[][2])
{
    if( r == er && c == ec )
        return 1;
    int t, a, b;
    for( int i=0; i<4; i++)
    {
        t = ( way+i )%4;
        a = r + dir[t][0];
        b = c + dir[t][1];
        if( a<h && a >=0 && b<w && b>=0 && Maze[a][b] != '#' )
            return dfs(a, b, (t+3)%4, dir) + 1;
    }
}

int bfs()
{
    memset(vis, 0, sizeof(vis));
    queue<Point> q;
    Point current, next;
    current.step = 1;
    current.r = sr;
    current.c = sc;
    vis[sr][sc] = 1;
    q.push( current );
    
    while( !q.empty() )
    {
        current = q.front();
        q.pop();
        if( current.r == er && current.c == ec )
        {
            return current.step;
        }
        for(int i=0; i<4; i++)
        {
            int a = current.r + dirL[i][0];
            int b = current.c + dirL[i][1];
            if( a<h && a>=0 && b<w && b>=0 && Maze[a][b] != '#' && !vis[a][b] )
            {
                next.r = a;
                next.c = b;
                vis[a][b] = true;
                next.step = current.step + 1;
                q.push( next );
            }
        }
    }
    return -1;
}

int main()
{
    int n, way;
    scanf("%d", &n);
    while( n-- )
    {
        scanf("%d%d", &w, &h);getchar();
        for(int i=0; i<h; i++)
        {
            scanf("%s", Maze[i]);
            for(int j=0; j<w; j++)
            {
                if( Maze[i][j] == 'S' )
                {
                    sr = i;
                    sc = j;
                }
                if( Maze[i][j] == 'E' )
                {
                    er = i;
                    ec = j;
                }
            }
        }
        if( sr == 0 )
            way = 0;
        else if ( sc == 0 )
            way = 1;
        else if ( sr == h-1 )
            way = 2;
        else if ( sc == w-1 )
            way = 3;
        printf("%d %d %d\n",dfs(sr, sc, way, dirL), dfs(sr, sc, way, dirR), bfs());
    }
    return 0;
}
