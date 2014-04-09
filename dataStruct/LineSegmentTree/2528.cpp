#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <set>
using namespace std;
#define MAX_N 10005
bool hashPointVal[10000005];
int point[MAX_N<<1];
int uPoint[MAX_N<<1];
int map[10000005];

int col[MAX_N<<2];
int hash[MAX_N];
int numLine;
int uniqPointCount;

void init()
{
    memset(hashPointVal, 0 ,sizeof(hashPointVal));
    memset(point, 0, sizeof(point)); 
    memset(map, 0, sizeof(map));
    memset(col, 0, sizeof(col));
    memset(hash, 0, sizeof(hash));
    numLine = 0;
    uniqPointCount = 0;
}
void pushDown(int index)
{
    col[index<<1] = col[index<<1|1] = col[index];
}
//l r is the range of the line, and L R is the range of the treeNode
//index is the shift of the treeNode
void update(int numLine, int l, int r, int L, int R, int index)
{
    if (l<=L && R<=r)
    {
        col[index] = numLine;
        return;
    }
    if (r<L || l>R)
        return;
    if (col[index] != 0)
    {
        pushDown(index);
        col[index] = 0;
    }
    int mid = (L+R)>>1;
    update(numLine, l, r, L, mid, index<<1);
    update(numLine, l, r, mid+1, R, index<<1|1);
    if (col[index<<1] == col[index<<1|1] && col[index<<1] != 0)
        col[index] = col[index<<1];
}

int query(int L, int R, int index)
{
    if (col[index] != 0)
    {
        if (hash[col[index]] == 0)
        {
            hash[col[index]] = 1;
            return 1;
        }
        else
            return 0;
    }
    if (L == R)
        return 0;
    int mid = (L+R)>>1;
    int res = query(L, mid, index<<1) + query(mid+1, R, index<<1|1);
    return res;
}

int main(int argc, const char *argv[])
{
    int numCase;
    scanf("%d", &numCase);
    while (numCase--)
    {
        init();
        scanf("%d", &numLine);
        for(int i=0; i<2*numLine; i++)
        {
            scanf("%d", &point[i]);
            if (!hashPointVal[point[i]])
            {
                hashPointVal[point[i]] = true;
                uPoint[uniqPointCount++] = point[i]; 
            }
        }
        sort(uPoint, uPoint+uniqPointCount);
        map[uPoint[0]] = 1;
        int upBounder = 2; 
        for(int i=1; i<uniqPointCount; i++, upBounder++)
        {
            if (uPoint[i] - uPoint[i-1] > 1)
                upBounder++;
            map[uPoint[i]] = upBounder;
        }
        upBounder--;
        for(int i=0; i<numLine; i++)
            update(i+1, map[point[i<<1]], map[point[i<<1|1]], 1, upBounder, 1);
        int res = query(1, upBounder, 1); 
        cout << res << endl;
    }
    return 0;
}
