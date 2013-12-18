#include<cstdio>
#include<cstring>
using namespace std;
#define NUMBER_LEN 11
// 10000 * 10
#define MAX_NODE_NUM 100001
#define MAX_NUM_WORD 10

struct Trie_Node
{
    char complete;
    Trie_Node* branch[MAX_NUM_WORD];
};

Trie_Node trie[MAX_NODE_NUM];
char base = '0';
int _index = 0;//start from 0 to allocate node

int insert(Trie_Node *root, char *word, int len)
{
    Trie_Node* curr = root;
    int i;
    int revers = 1; //means new word is a prefix of older words
    for(i=0; i<len; i++)
    {
        if( curr->branch[ word[i] - base ] == NULL )
        {
            curr->branch[ word[i] - base ] = &trie[_index++];
            revers = 0;
        }
        else
        {
            if( curr->branch[ word[i] - base ]->complete == 1 )
                return 0;
        }
        curr = curr->branch[ word[i] - base ];
    }
    curr->complete = 1;
    if( revers == 0 )
        return 1;
    else
        return 0;
}
int t;
int n;
char phone[NUMBER_LEN];
int main()
{
    scanf("%d", &t);
    int i, j;
    int res;
    for(i=0; i<t; i++)
    {
        memset(trie, 0, sizeof(trie));
        _index = 0;
        Trie_Node* root = &trie[_index++];  
        scanf("%d", &n);
        res = 1;
        for(j=1; j<=n; j++)
        {
            scanf("%s", &phone);
            if( res == 1 )
                res = insert(root, phone, strlen(phone));
        }
        if( res == 1 )
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
