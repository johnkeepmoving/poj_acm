#include<cstdio>
#include<cstring>
using namespace std;

const int N = 15;
const int MAXN = 500010;
const int MOD = 500003;

char str[N];
int cnt , father[MAXN];
int hash[MAXN] , degree[MAXN];
bool vis[MAXN];

void init()
{
    cnt = 1;
    memset(hash , 0 , sizeof(hash));
    memset(degree , 0 , sizeof(degree));
    memset(vis , false , sizeof(vis));
    for(int i = 1 ; i < MAXN ; i++)
       father[i] = i;
}

int find(int x)
{
    if(x != father[x])
       father[x] = find(father[x]);
    return father[x];
}

int Hash(char* s)
{
    int sum = 0;
    while(*s)
        sum = (*s++)+(sum<<6)+(sum<<16)-sum;
    return (sum&0x7FFFFFFF) % MOD;
}

int getHash(int x)
{
    if(!hash[x])
       hash[x] = cnt++;
    return hash[x];
}

bool isOk()
{
    int root;
    for(int i = 1 ; i <= cnt ; i++)
    {
       if(vis[i])
       {
          root = find(i); 
          break;
       }
    }
    for(int i = 1 ; i <= cnt ; i++)
       if(vis[i] && find(i) != root)
           return false;
    int num = 0;
    for(int i = 1 ; i <= cnt ; i++)
        if(degree[i]&1) 
            num++;
    return num <= 2;
}

int main()
{
    init();
    while(scanf("%s" , str) != EOF)
    {
         int x = Hash(str);
         x = getHash(x);
         scanf("%s" , str);
         int y = Hash(str);
         y = getHash(y);
         vis[x] = vis[y] = true;
         degree[x]++;
         degree[y]++;
         father[find(x)] = find(y);
    } 
    if(isOk())
        printf("Possible\n");
    else
        printf("Impossible\n");
    return 0;
}
