#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int Max = 62;
 
char text[10][Max], pat[Max];
int n, ma, lenp, next[Max];
 
void get_next(){
    int i = 0, j = -1;
    next[0] = -1;
    while(i < lenp){
        if(j == -1 || pat[i] == pat[j])
        {
            i ++; j ++;
            next[i] = j;
        }
        else j = next[j];
    }
}
 
void KMP(){
    int k, m, i, j;
    get_next();
    ma = 100;
    for(k = 1; k < n; k ++){
        i = 0; j = 0; m = 0;
        while(i < 60 && j < lenp){
            if(j == -1 || text[k][i] == pat[j]){
                i ++; j ++;
            }
            else j = next[j];
            if(j > m) m = j;
        }
        if(m < ma) ma = m;
    }
}
 
int main()
{
    int t, i;
    char result[Max];
    scanf("%d", &t);
    while(t --)
    {
        scanf("%d", &n);
        for(i = 0; i<n; i++)
            scanf("%s", text[i]);
        int ans = 0;
        for(i = 0; i <= 57; i ++){
            strcpy(pat, text[0] + i);    //  枚举第一个串的所有后缀串（当然最后2个可以省去）。
            lenp = 60 - i;
            KMP();                       //  KMP求出这个后缀串与其余所有串的最大匹配。
            if(ans < ma){                                                                                                                
                ans = ma;
                strncpy(result, text[0] + i, ans);
                result[ans] = '\0';                                                                                                                                                 
            }
            else if(ans == ma){         //  存在多个最长公共子串，输出字典序最小的，WA了一次。
                char tmp[Max];
                strncpy(tmp, text[0] + i, ans);    //  复习: strncpy()没有复制最后的'\0'。
                tmp[ans] = '\0';
                if(strcmp(tmp, result) < 0)
                    strcpy(result, tmp);
            }
        }
        if(ans >= 3)
            printf("%s\n", result);  
        else
            printf("no significant commonalities\n");  
    }
    return 0;
}
