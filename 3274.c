#include<stdio.h>
#include<math.h>

#define MAX_RAW 100001
#define MAX_FEATURE 30

#define MOD 10000

struct Node
{
    int index;
    struct Node *p_next;
};
typedef struct Node Node;

//int is 32bit, so a int can store all features.
int count[MAX_RAW][MAX_FEATURE] = { 0 };
int all_count[MAX_FEATURE] = { 0 };
Node *hash_array[100000] = { NULL };

int isSame(int index1, int index2,int feature_num)
{
    int i,j=0;
    for(i=0; i<feature_num; i++)
    {
        if( count[index1][i] != count[index2][i] )
            break;
        else
            j++;
    }
    if( j != feature_num )
        return 0;
    else
        return 1;
}

int Length(Node *Link_head, Node *curr_node, int feature_num)
{
    if( !Link_head || !curr_node )
        return -1;
    int len = 0;
    while( Link_head != NULL )
    {
        if( isSame( Link_head -> index, curr_node ->index, feature_num ) )
            if( (curr_node -> index - Link_head -> index ) > len )
                len = curr_node -> index - Link_head -> index;
        Link_head = Link_head -> p_next;
    }
    return len;
}

int Add(Node *Link_head, Node *new_node)
{
    if( !Link_head || !new_node)
        return 0;

    while( Link_head -> p_next != NULL )
    {
        Link_head = Link_head -> p_next;
    }
    Link_head -> p_next = new_node;
    return 1;
}

int main()
{
    int N,K;
    scanf("%d%d", &N, &K);
    int i;
    int max_len = 0;
    int feature;
    memset(all_count, 0, MAX_FEATURE);
    for(i=0; i<=N; i++)
    {
        if( i == 0 )
            feature = 0;
        else
            scanf("%d", &feature);
        int j;
        int sum = 0;
        for(j=K-1; j>=0; j--)
        {
            all_count[j] = all_count[j] + (feature & 1);
            feature = feature >> 1;
            count[i][j] = all_count[j] - all_count[K-1]; 
            sum += count[i][j];
        }
        Node *new_node = (Node*)malloc(sizeof(Node));
        new_node->index = i;
        new_node->p_next = NULL;
        sum += 3000000;
        int t_index = sum%MOD;
        if( hash_array[t_index] )
        {
            int t_len = Length(hash_array[t_index], new_node, K);
            if( t_len > max_len )
                max_len = t_len;
            Add( hash_array[t_index], new_node);
        }
        else
        {
            hash_array[t_index] = new_node;
        }
    }
    printf("%d\n",max_len);
    return 0;
}