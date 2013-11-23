#include<stdio.h>
#include<stdlib.h>
#define MAX 100000
#define FILL_1 1
#define FILL_2 2
#define DROP_1 3
#define DROP_2 4
#define POUR_1_2 5
#define POUR_2_1 6

char *operation[7] = {
    " ",
    "FILL(1)",
    "FILL(2)",
    "DROP(1)",
    "DROP(2)",
    "POUR(1,2)",
    "POUR(2,1)"};

typedef struct
{
    int v1;
    int v2;
    int step;
    int action;//from 1 to 6
    int pre;
}node;

void copy_node(node *src, node* dst)
{
    dst -> v1 = src -> v1;
    dst -> v2 = src -> v2;
    dst -> step = src -> step;
    dst -> action = src -> action;
    dst -> pre = src -> pre;
}
int A, B, C;
int flags[101][101];
node que[MAX];
int head, tail;

void Enq(node *n)
{
    copy_node(n, &que[tail]);
    tail++;
}

node *Deq()
{
    return &que[head++];
}

int empty()
{
    if( head == tail )
        return 1;
    else
        return 0;
}

int get_ans()
{
    node *curr_node = (node *)malloc(sizeof(node));
    curr_node -> v1 = 0;
    curr_node -> v2 = 0;
    curr_node -> step = 0;
    curr_node -> action = 0;
    curr_node -> pre = -1;
    Enq( curr_node );
    flags[0][0] = 1;
    while( empty() == 0)
    {
        node *t_node;
        t_node = Deq();
        int curr_index = head -1;
        printf("this pop: v1 is %d, v2 is %d.Its step is %d\n", t_node -> v1, t_node -> v2, t_node->step);
        if( t_node -> v1 == C || t_node -> v2 == C )
        {
            return head-1;
        }
        node *next_node = (node *)malloc(sizeof(node));
        copy_node(t_node, curr_node);
        copy_node(curr_node, next_node);
        if( (curr_node -> v1 < A) && (flags[A][curr_node->v2] != 1) )
        {
            next_node -> v1 = A;
            next_node -> step = curr_node -> step + 1;
            next_node -> action = 1;
            next_node -> pre = curr_index;
            Enq( next_node );
            printf("add node %d %d\n", A, curr_node->v2);
            flags[A][curr_node->v2] = 1;
        }
        if( (curr_node -> v1 > 0) && (flags[0][curr_node->v2] != 1) )
        {
            next_node -> v1 = 0;
            next_node -> step = curr_node -> step + 1;
            next_node -> action = 3;
            next_node -> pre = curr_index;
            Enq( next_node );
            printf("add node %d %d\n", 0, curr_node->v2);
            flags[0][curr_node->v2] = 1;
        }
        if( (curr_node -> v2 < B) && (flags[curr_node->v1][B] != 1) )
        {
            next_node -> v2 = B;
            next_node -> step = curr_node -> step + 1;
            next_node -> action = 2;
            next_node -> pre = curr_index;
            Enq( next_node );
            printf("add node %d %d\n", curr_node->v1, B);
            flags[curr_node->v1][B] = 1;
        }
        if( (curr_node -> v2 > 0) && (flags[curr_node->v1][0] != 1) )
        {
            next_node -> v2 = 0;
            next_node -> step = curr_node -> step + 1;
            next_node -> action = 4;
            next_node -> pre = curr_index;
            Enq( next_node );
            printf("add node %d %d\n", curr_node->v1, 0);
            flags[curr_node->v1][0] = 1;
        }
        if( (curr_node -> v1 > 0) && ( curr_node->v2 < B) )
        {
            int diff = curr_node->v1 - (B - curr_node->v2);
            if( (diff >= 0) && (flags[diff][B] != 1) )
            {
                next_node -> v1 = diff;
                next_node -> v2 = B;
                next_node -> step = curr_node -> step + 1;
                next_node -> action = 5;
                next_node -> pre = curr_index;
                Enq( next_node );
                printf("add node %d %d\n", diff, B);
                flags[diff][B] = 1;
            }
            if( (diff < 0) && (flags[0][B+diff] != 1) )
            {
                next_node -> v1 = 0;
                next_node -> v2 = B+diff;
                next_node -> step = curr_node -> step + 1;
                next_node -> action = 5;
                next_node -> pre = curr_index;
                Enq( next_node );
                printf("add node %d %d\n", 0, B+diff);
                flags[0][B+diff] = 1;
            }
        }
        if( (curr_node -> v2 > 0) && ( curr_node->v1 < A) )
        {
            int diff = curr_node->v2 - (A - curr_node->v1);
            if( (diff >= 0) && (flags[A][diff] != 1) )
            {
                next_node -> v1 = A;
                next_node -> v2 = diff;
                next_node -> step = curr_node -> step + 1;
                next_node -> action = 6;
                next_node -> pre = curr_index;
                Enq( next_node );
                printf("add node %d %d\n", A,diff);
                flags[A][diff] = 1;
            }
            if( (diff < 0) && (flags[A+diff][0] != 1) )
            {
                next_node -> v1 = A+diff;
                next_node -> v2 = 0;
                next_node -> step = curr_node -> step + 1;
                next_node -> action = 6;
                next_node -> pre = curr_index;
                Enq( next_node );
                printf("add node %d %d\n", A+diff, 0);
                flags[A+diff][0] = 1;
            }
        }
    }
}

void print_ans(int index)
{
    if( que[index].pre >0 )
        print_ans(que[index].pre);
    printf("%s\n", operation[ que[index].action ]);
}
int main()
{
    scanf("%d%d%d", &A, &B, &C);
    printf("A is %d, B is %d, C is %d\n", A, B, C);
    head = 0; tail = 0;
    int last_index = get_ans();
    int step = que[last_index].step;
    printf("%d\n", step);
    print_ans(last_index);
    return 0;
}
