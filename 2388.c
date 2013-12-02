#include<stdio.h>

#define MAX 10000
int data_array[MAX];

int Partion(int array[], int p, int r)
{
    int temp;
    
    int x = array[r];
    int i = p - 1;
    int j;
    for(j=p; j<r; j++)
    {
        if( array[j] <= x )
        {
            i++;
            //swap A[i] A[j]
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }
    
    temp = array[i+1];
    array[i+1] = array[r];
    array[r] = temp;
    return (i+1);
}

void Quick_Sort(int array[], int p, int r)
{
    if( p<r )
    {
        int q = Partion(array, p, r);
        Quick_Sort(array, p, q-1);
        Quick_Sort(array, q+1, r);
    }
}
int main()
{
    int _num;
    int milk;
    int count = 0;
    if( scanf("%d", &_num) != 0)
        for(count; count<_num; count++)
        {
            scanf("%d", &milk);
            data_array[count] = milk;
        }
    Quick_Sort(data_array, 0, count-1);
    printf("%d\n",data_array[count/2]); 
    return 0;
}
