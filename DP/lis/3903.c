#include<stdio.h>
#include<string.h>
int L;
long int data[100005];
int max[100005];

int get_ans(int start, int end)
{
    max[1] = start;
    int len = 1;
    int i, j;
    for(i=start+1; i<=end; i++)
    {
        if( data[i] > data[max[len]] )
            max[++len] = i;
        else //if(data[i] < data[max[len]])
        {
            int l = start, r = len;
            while( l<r )
            {
                int mid = (l+r)/2;
                if( data[i] <= data[max[mid]] )
                    r = mid;
                else
                    l = mid + 1;
            }
            max[l] = i;
        }
    }
    return len;
}

int main()
{
    while( scanf("%d", &L) != -1 )
    {
        memset(max, 0, sizeof(max));
        int i;
        for(i=1; i<=L; i++)
            scanf("%ld", &data[i]);
        int ans = get_ans(1, L);
        printf("%ld\n", ans);
    }
    return 0;
}
