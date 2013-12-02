#include<cstdio>
using namespace std;
#define RANGE_C 101
int C;
int stack1[RANGE_C];
int stack2[RANGE_C];
int stack12[2*RANGE_C];
int init_stack[2*RANGE_C];//store the first step stack

int dest_stack[2*RANGE_C];
int step = -1;

int cmp(int arr1[], int arr2[], int len)
{
    int i;
    for(i=1; i<=len; i++)
        if( arr1[i] != arr2[i] )
            break;
    if( i<=len )
        return -1;
    else
        return 1;
}

int get_ans()
{
    int i;
    for(i=1; i<=2*C; i++)
        init_stack[i] = stack12[i];
    step = 1;
    while(1)
    {
        //equal
        if( cmp(stack12, dest_stack, 2*C) == 1 )
        {
            break;
        }
        //if not equal, check if back to init stack?
        if( (cmp(stack12, init_stack, 2*C) == 1) && (step > 1) )
        {
            step = -1;
            break;
        }
        for(i=1; i<=C; i++)
            stack1[i] = stack12[i];
        for(i=1; i<=C; i++)
            stack2[i] = stack12[C+i];
        for(i=1; i<=C; i++)
            stack12[2*i] = stack1[i];
        for(i=1; i<=C; i++)
            stack12[2*(i-1)+1] = stack2[i];
        step++;
    }
    return step;
}

int main()
{
    int N;
    char card;
    scanf("%d", &N);
    int k = 1;
    int ans;
    while( k<=N )
    {
        scanf("%d", &C);
        getchar();
        int i;
        for(i=1; i<=C; i++)
        {
            scanf("%c", &card);
            stack1[i] = card - 'A';
            stack12[2*i] = stack1[i];
        }
        getchar();
        for(i=1; i<=C; i++)
        {
            scanf("%c", &card);
            stack2[i] = card - 'A';
            stack12[2*(i-1)+1] = stack2[i];
        }
        getchar();
        for(i=1; i<=2*C; i++)
        {
            scanf("%c", &card);
            dest_stack[i] = card - 'A';
        }
        getchar();
        ans = get_ans();
        printf("%d %d\n", k, ans);
        k++;
    }
    return 0;
}
