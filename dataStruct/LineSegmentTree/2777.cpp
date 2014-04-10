#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;
#define MAX_BOARDLEN 100005 
#define MAX_COLNUM 40
int boardLen;
int colNum;
int opNum;
int col[MAX_BOARDLEN<<2];
int cnt[MAX_BOARDLEN<<2];

void init()
{
    memset(col, 0, sizeof(col));
    memset(cnt, 0, sizeof(cnt));
    col[1] = 1;
    cnt[1] = 1;
}

void pushDown(int index)
{
    cnt[index<<1]=cnt[index<<1|1] = 1<<(col[index]-1);
    col[index<<1] = col[index<<1|1] = col[index];
}
//L R is the range of node
void update(int index, int L, int R, int l, int r, int color)
{
    if (l<=L && R<=r)
    {
        col[index] = color;
        cnt[index] = 1<<(col[index]-1);
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
    update(index<<1, L, mid, l, r, color);
    update(index<<1|1, mid+1, R, l, r, color);
    cnt[index] = cnt[index<<1] | cnt[index<<1|1];
}
int query(int index, int L, int R, int l, int r)
{
    if (l<=L && R<=r)
        return cnt[index];
    if (r<L || l>R)
        return 0;
    if (col[index] != 0)
    {
        pushDown(index);
        col[index] = 0;
    }
    int mid = (L+R)>>1;
    return query(index<<1, L, mid, l, r) | query(index<<1|1, mid+1, R, l, r);
}
int main()
{
    init();
    scanf("%d%d%d", &boardLen, &colNum, &opNum);
    getchar(); 
    char op; 
    int start, end, color;
    int res;
    //update(1, 1, boardLen, 1, boardLen, 1);
    for(int i=1; i<=opNum; i++)
    {
        scanf("%c", &op);
        if (op == 'C')
        {
            scanf("%d%d%d", &start, &end, &color);
            getchar();
            if (start > end)
                swap(start, end);
            update(1, 1, boardLen, start, end, color);
        }else if (op == 'P')
        { 
            scanf("%d%d", &start, &end);
            getchar();
            if (start > end)
                swap(start, end);
            int flag; 
            res = 0;
            flag = query(1, 1, boardLen, start, end);
            while (flag != 0)
            {
                res++;
                flag = flag & (flag-1);
            }
            printf("%d\n", res);
        }
    }
    return 0;
}
