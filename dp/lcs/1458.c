#include<stdio.h>
#include<string.h>
#define MAX_LEN 1000

char str1[MAX_LEN];
char str2[MAX_LEN];
int c[MAX_LEN][MAX_LEN];
char b[MAX_LEN][MAX_LEN];

int LCS()
{
    int len1 = strlen(str1+1);
    int len2 = strlen(str2+1);
    int i, j;
    for(i=1; i<=len1; i++)
        c[i][0] = 0;
    for(i=1; i<=len2; i++)
        c[0][i] = 0;

    for(i=1; i<=len1; i++)
        for(j=1; j<=len2; j++)
        {
            if( str1[i] == str2[j] )
            {
                c[i][j] = c[i-1][j-1] + 1;
                b[i][j] = '\\';
            }
            else if( c[i-1][j] > c[i][j-1] )
            {
                c[i][j] = c[i-1][j];
                b[i][j] = '|';
            }
            else
            {
                c[i][j] = c[i][j-1];
                b[i][j] = '-';
            }
        }
    return c[len1][len2];
}

int main()
{
    while (scanf("%s %s", str1+1, str2+1) != -1)
    {
        memset(c, 0, sizeof(c) );
        printf("%d\n", LCS());
    }
    return 0;
}
