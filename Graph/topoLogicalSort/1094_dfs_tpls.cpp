#include <cstdio>
#include <cstring>
using namespace std;

int n,m;
int e[27][27];
int cur,incons,color[27];
char inStr[4],resultStr[27];

//color 0:white, 1:gray, 2:black
void dfs(int k){
  color[k]=1;
  int i;
  for(i=1;i<=n;i++){
        if(e[k][i]&&color[i]==0) dfs(i);
        else if(e[k][i]&&color[i]==1) incons=1;                
  }     
    color[k]=2;
    resultStr[cur++]=k-1+'A';
}
int main(){
    int i,j,found;
    while( scanf("%d%d", &n, &m)!=-1 && n && m)
    {   
        memset(e,0,sizeof(e));
        found=0;
        incons=0;
        for(i=1;i<=m;i++){
            scanf("%s", &inStr); 
            e[inStr[0]-'A'+1][inStr[2]-'A'+1]=1;
            if(!found&&!incons){
                cur=0;
                memset(color,0,sizeof(color));
                for(j=1;j<=n;j++)
                      if(color[j]==0)
                            dfs(j);
                resultStr[cur]='\0';
                if(incons==1)
                    incons=i;
                else{
                   int bb=1;
                   for(j=cur-1;j>0;j--)
                       if(!e[resultStr[j]-'A'+1][resultStr[j-1]-'A'+1])
                           {
                              bb=0;
                              break;                                   
                           }    
                    if(bb)
                        found=i;
                }                     
            }                  
        }    
        char tt;
        for(i=0,j=cur-1;i<j;i++,j--)  //reverse the sorted sequence
         {
             tt=resultStr[i];
             resultStr[i]=resultStr[j];
             resultStr[j]=tt;
         }
         if(incons) printf("Inconsistency found after %d relations.\n",incons);
         else if(found) printf("Sorted sequence determined after %d relations: %s.\n",found,resultStr);
              else printf("Sorted sequence cannot be determined.\n");                                             
    }
    return 0;
} 
