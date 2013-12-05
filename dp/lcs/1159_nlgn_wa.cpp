#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <utility>
using namespace std;
typedef multimap<char, int> :: const_iterator CIT;
typedef pair<CIT, CIT> Range;

int N;
char str[5005];
char rev_str[5005];
//short res[5005][5005];
short index_seq[5005 * 5005]; 
int seq_len;
int seq_max[5005]; 

int lis(short int arr[], int start, int end)
{
    seq_max[1] = start; //seq_max[len] = index, and arr[index] is ascending!(index in seq_max)
    int len = 1;
    int i, j;
    for(i=start+1; i<=end; i++)
    {
        if( arr[i] > arr[seq_max[len]] )
            seq_max[++len] = i;
        else //binary search 
        {
            int l = start, r = len;
            while( l<r )
            {
                int mid = (l+r)/2;
                if(arr[i] <= arr[seq_max[mid]])
                    r = mid;
                else
                    l = mid+1;
            }
            seq_max[l] = i; 
        }
    }
    return len;
}
int lcs()
{
    multimap<char, int> mm;
    int i, j;
    for(i=1; i<=N; i++)
        mm.insert(pair<char, int>(str[i],i));
    seq_len = 0;
    int t_index;
    for(i=1; i<=N; i++)
    {
        Range range = mm.equal_range(rev_str[i]);
        for(CIT cit=range.first; cit!=range.second; cit++)
           index_seq[++seq_len] = cit->second; 
    }
    //lis between index_seq and {1, 2, 3, ......, N}
    return lis(index_seq, 1, seq_len);
}

int main()
{
    scanf("%d", &N);
    getchar();
    int i;
    for(i=1; i<=N; i++)
       scanf("%c", &str[i]); 
    str[N+1] = '\0';
    for(i=1; i<=N; i++)
        rev_str[i] = str[N-i+1];
    rev_str[N+1] = '\0';
    
    int ans = lcs();
    printf("%d\n", (N-ans) ); 
    return 0;
}
