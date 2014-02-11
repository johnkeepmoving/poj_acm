#include <cstdio>
#include <cstring>
using namespace std;
#define MAX_VERTEX_NUM 510000
#define MAX_COLOR_LEN 11
struct TrieNode
{
    int vertexNum;
    TrieNode* next[26];
};

TrieNode node[MAX_VERTEX_NUM];
int degree[MAX_VERTEX_NUM], father[MAX_VERTEX_NUM];

char base = 'a';
int _index = 0;
int vertexCount = 0;
void init()
{
    int i;
    for(i=1; i<MAX_VERTEX_NUM; i++)
        father[i] = i;
    memset(degree, 0, sizeof(degree));
    memset(node, 0, sizeof(node));
}

TrieNode* create()
{
    TrieNode* root = &node[_index++];
    int i;
    for(i=0; i<26; i++)
        root->next[i] = NULL;
    return root;
}

int search(TrieNode *root, char *str)
{
    int i;
    int len = strlen(str);
    TrieNode *curr = root;
    for(i=0; i<len; i++)
    {
       if ( curr->next[str[i]-base] == NULL )
           return 0;
       curr = curr->next[str[i]-base];
    }
    return curr->vertexNum;
}

void insert(TrieNode *root, char *str, int num)
{
    int i;
    int len = strlen(str);
    TrieNode *curr = root;
    for(i=0; i<len; i++)
    {
        if ( curr->next[str[i]-base] == NULL )
            curr->next[str[i]-base] = create();
        curr = curr->next[str[i]-base];
    }
    curr->vertexNum = num;
}

int findSet(int num)
{
    if( num != father[num] )
        father[num] = findSet(father[num]);
    return father[num];
}

void unionSet(int x, int y)
{
    father[x] = y;
}

bool judgeEuler()
{
    int i;
    int oddNum = 0;
    for(i=1; i<=vertexCount; i++)
    {
        if ( degree[i]%2 != 0 )
            {
                oddNum++;
                if (oddNum > 2)
                    return false;
            }
    }
    if (oddNum != 2 && oddNum != 0)
        return false;
    int setNum1 = findSet(1);
    for(i=2; i<=vertexCount; i++)
        if ( setNum1 != findSet(i) )
            return false;
    return true;
}
int main(int argc, const char *argv[])
{
    char str1[MAX_COLOR_LEN], str2[MAX_COLOR_LEN];
    init();
    TrieNode *root = create();
    while( scanf("%s%s", &str1, &str2) != -1)
    {
        int num1 = search(root, str1);
        int num2 = search(root, str2);
        if (num1 == 0) insert(root, str1, num1= ++vertexCount);
        if (num2 == 0) insert(root, str2, num2= ++vertexCount);
        degree[num1]++;
        degree[num2]++;
        
        int x = findSet(num1);
        int y = findSet(num2);
        if ( x != y )
            unionSet(x, y);
    }
    if (judgeEuler())
        printf("Possible\n");
    else
        printf("Impossible\n");
    return 0;
}
