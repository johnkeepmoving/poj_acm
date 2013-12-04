#include <stdio.h>
#include <string.h>
#define N 100001
 
char s[N],t[N];
 
int main()
{
      int slen,tlen,i,j,tag;
      while( scanf("%s  %s",s,t) != EOF )
      {
          slen = strlen(s); 
          tlen = strlen(t);
          for(i = 0 ,j = 0;i < tlen && j < slen; ++i)
              if(s[j] == t[i])
                  ++j;          
          if(j == slen)  puts("Yes");
          else puts("No");  
      }  
      return 0;
}
