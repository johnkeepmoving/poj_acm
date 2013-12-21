/*have error*/
#include <stdio.h>
#include <string.h>
#define MIN(a, b) (a<b?a:b)
int W, L;
char Dict[605][30];

char Mes[305];
int dp[305];
int mes_len;

int get_max_len(char *pattern, char *word)
{
    int i, j;
    int ret = -1;
    int len_p = strlen( pattern );
    int len_w = strlen( word );
    i = 0; j = 0; 
    while( i<len_p )
    {
        if( word[j] == pattern[i++])
            j++;
        if( j == len_w )
        {
            ret = dp[i]+ i-j;
            break;
        }
    }
    return ret;
}

void get_ans()
{
    int i, j, tmp;
    dp[mes_len] = 0;
    for(i=mes_len-1; i>=0; i--)
    {
        dp[i] = dp[i+1] + 1; 
        for(j=0; j<W; j++)
            if( strlen(Dict[j] ) <= (mes_len-i) && Dict[j][0] == Mes[i])
            {
                tmp =  get_max_len( &Mes[i] , Dict[j]);
                if( tmp != -1 ) dp[i] = MIN(dp[i], tmp);
            }
    }
}

int main()
{
    int i;
    scanf("%d %d", &W, &L);
    scanf("%s", &Mes);
    mes_len = strlen(Mes); 
   
    for(i=0; i<W; i++)
        scanf("%s", &Dict[i]);
    get_ans();
    printf("%d\n", dp[0]);
    return 0;
}
