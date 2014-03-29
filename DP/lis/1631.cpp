#include <cstdio>
#include <cstring>
#define MAX_PORTS 40001
int data[MAX_PORTS];
int max[MAX_PORTS];
int lis(int start, int end)
{
    max[1] = start;
    int len = 1;
    for(int i=start+1; i<=end; i++)
    {
        if (data[i] > data[max[len]])
            max[++len] = i;
        else
        {
            int l = 1, r = len;
            while ( l<r )
            {
                int mid = (l+r)/2;
                if ( data[i] <= data[max[mid]] )
                    r = mid;
                else
                    l = mid+1;
            }
            max[l] = i;
        }
    }
    return len;
}

int main(int argc, const char *argv[])
{
    int numCases;
    int numPorts;
    int ans;
    scanf("%d", &numCases);
    for(int i=1; i<=numCases; i++)
    {
        memset(data, 0, sizeof(data));
        scanf("%d", &numPorts);
        for(int j=1; j<=numPorts; j++)
            scanf("%d", &data[j]);
        ans = lis(1, numPorts);
        printf("%d\n", ans);
    }
    return 0;
}
