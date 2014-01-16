#include <cstdio>
#include <cstring>
using namespace std;
#define MAX_NUM 27

struct Node
{
    char c;
    Node *left, *right;
};
Node allNode[MAX_NUM];
char preOrd[MAX_NUM];
char inOrd[MAX_NUM];
int inTree[MAX_NUM];
int len = 0;
int nodeCount = 0;
void constructTree(Node **root, int start, int end)
{
    if ( start > end )
    {
        printf("error\n");
        return;
    } else if ( start == end )
    {
        *root = &allNode[nodeCount++];
        (*root)->c = preOrd[start];
        return;
    }
    else
    {
        *root = &allNode[nodeCount++];
        (*root)->c = preOrd[start];
        
        int lstart, lend, rstart, rend;
        lstart = start + 1;
        rend = end;
        int location = -1;
        int tmpCount = 0;
        for(int i=0; i<len; i++)
        {
            if ( preOrd[start] == inOrd[i] )
            {
                inTree[i] = 1;
                lend = lstart+tmpCount-1;
                break;
            }
            else
            {
                if ( !inTree[i] )
                    tmpCount++;
                else
                    tmpCount = 0;
            }
        }
        rstart = lend + 1;
        if ( lend >= lstart )
            constructTree( &((*root)->left), lstart, lend);
        if ( rend >= rstart )
            constructTree( &((*root)->right), rstart, rend);
    }
}

void postOrder(Node *root)
{
    if ( root == NULL )
    {
        printf("error post\n");
        return;
    }
    if ( root->left )
        postOrder(root->left);
    if ( root->right )
        postOrder(root->right);
    printf("%c", root->c);
}

int main(int argc, const char *argv[])
{
    Node *root;
    while( scanf("%s %s", preOrd, inOrd) != -1)
    {
        memset(allNode, 0, sizeof(allNode));
        memset(inTree, 0, sizeof(inTree));
        nodeCount = 0;
        len = strlen(preOrd);
        constructTree(&root,0, len-1);
        postOrder(root);
        printf("\n");
    }
    return 0;
}
