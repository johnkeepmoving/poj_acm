#include<stdio.h>
#include<stdlib.h>
#define MAX 500000

int data_array[MAX];
int reverse_count = 0;

/**** merge sort *****/
void merge(int *arr, int p, int q, int r)
{
    int len1 = q-p+1;
    int len2 = r-q;

    int *arr1 = (int *)malloc(sizeof(int)*(len1+1));
    int *arr2 = (int *)malloc(sizeof(int)*(len2+1));

    int i,j;
    for( i=0; i<len1; i++)
        arr1[i] = arr[p+i];
    for( j=0; j<len2; j++)
        arr2[j] = arr[q+1+j];
    arr1[len1] = 1000000000;
    arr2[len2] = 1000000000;

    i=j=0;
    int k;
    for(k=p; k<=r; k++)
        if( arr1[i] <= arr2[j])
        {
            arr[k] = arr1[i];
            i++;
        }
        else
        {
            arr[k] = arr2[j];
            j++;
            if(arr1[i] < 1000000000)
            {
                reverse_count += (q-(i+p)+1) ;
            }

        }
    free(arr1);
    free(arr2);
}

void merge_sort(int *arr, int p, int r)
{
    if( p<r && 0<=p && 0<=r )
    {
        int q = (p+r)/2;
        merge_sort( arr, p, q);
        merge_sort( arr, q+1, r);
        merge( arr, p, q, r);
    }
}

int main()
{
    int num;
    while(scanf("%d", &num) != -1)
    {
        if( num == 0 )
        {
            return 0;
        }
        reverse_count = 0;
        int i;
        for(i=0; i<num; i++)
            scanf("%d", &data_array[i]);
        merge_sort(data_array, 0, i-1);
        printf("%d\n", reverse_count);
    }
    return 0;
}
