#include <cstdio>
#include <cstring>
#define MAX_TREE_NAME 40
#define MAX_TREE_SPECIES 10000
struct Node
{
    char treeName[MAX_TREE_NAME];
    Node *left, *right;
    int count;
};
Node treeNode[MAX_TREE_SPECIES];
int speciesCount = 0;
int treeCount = 0;
char inTree[MAX_TREE_NAME];

void insertNode(Node *root, char *treeName)
{
    bool find = false;
    Node *node = root;
    while ( !find )
    {
        int cmp = strcmp(node->treeName, treeName);
        if ( cmp == 0 )
        {
            node->count++;
            find = true;
        } else if ( cmp < 0 )
        {
            if ( node->right )
                node = node->right;
            else //insert
            {
                node->right = &treeNode[speciesCount++];
                node = node->right;
                strncpy(node->treeName, treeName, sizeof(node->treeName)-1);
                node->treeName[sizeof(node->treeName)-1] = '\0';
                node->left = NULL;
                node->right = NULL;
                node->count = 1;
                find = true;
            }
        }
        else
        {
            if ( node->left)
                node = node->left;
            else //insert
            {
                node->left= &treeNode[speciesCount++];
                node = node->left;
                strncpy(node->treeName, treeName, sizeof(node->treeName)-1);
                node->treeName[sizeof(node->treeName)-1] = '\0';
                node->left = NULL;
                node->right = NULL;
                node->count = 1;
                find = true;
            }
        }            
    }
}

void inoderTraverse(Node *root)
{
    //if ( root == NULL )
    //    return;
    if ( root->left )
        inoderTraverse( root->left );
    printf("%s %.4f\n", root->treeName, root->count*100.0/treeCount);
    if ( root->right )
        inoderTraverse( root->right );
}

int main(int argc, const char *argv[])
{
    memset(treeNode, 0, sizeof(treeNode));
    Node *root;
    root = &treeNode[speciesCount++];
    
    gets( inTree );
    treeCount++;
    strncpy(root->treeName, inTree, sizeof(root->treeName)-1);
    root->treeName[sizeof(root->treeName)-1] = '\0';

    root->left = NULL;
    root->right = NULL;
    root->count = 1;
    //strcpy(root->treeName, inTree);
    while( gets(inTree) )
    {
        treeCount++;
        insertNode( root, inTree );
    }
    inoderTraverse(root);
    return 0;
}
