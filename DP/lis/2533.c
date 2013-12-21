#include <stdio.h>
#include <string.h>
#define MAX(a, b) (a>b?a:b)
int N;
int arr[10005];
int res[10005];

int max[10005];// used in o(nlgn)

//default counting lis by ascending
int lis_ascend(int start, int end)
{
    int i, j;
    res[start] = 1;
    for(i=start+1; i<=end; i++)
    {
        int len = 1;
        for(j=start; j<i; j++)
            if( arr[i] > arr[j] )
                len = MAX(res[j]+1, len);
        res[i] = len;
    }
    int max_len = 1;
    for(i=start; i<=end; i++)
        max_len = MAX(max_len, res[i]);
    return max_len;
}

int lis_nlgn(int start, int end)
{
    max[1] = start; //max[len] = index, and arr[index] is ascending!(index in max)
    int len = 1;
    int i, j;
    //res[start] = 1;
    for(i=start+1; i<=end; i++)
    {
        if( arr[i] > arr[max[len]] )
            max[++len] = i;
        else //binary search 
        {
            int l = start, r = len;
            while( l<r )
            {
                int mid = (l+r)/2;
                if(arr[i] < arr[max[mid]])
                    r = mid;
                else
                    l = mid+1;
            }
            max[l] = i; 
        }
    }
    for(i=end; i>=start;i--)
       if( max[i] > -1 )
            return i;
}

int main()
{
    memset(arr, 0, sizeof(arr)); 
    memset(res, 0, sizeof(res)); 
    memset(max, -1, sizeof(max)); 
    
    scanf("%d", &N);
    int i;
    for(i=1; i<=N; i++)
        scanf("%d", &arr[i]);

    int ans = lis_nlgn(1, N);
    printf("%d\n", ans);
    return 0;
}
