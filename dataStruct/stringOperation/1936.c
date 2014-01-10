#include<stdio.h>
#include<string.h>

#define Max 100000

char str1[Max], str2[Max];
int pmt[Max];


void get_next(char *pat, int plen, int *next)
{
    int i=0,j=-1;
    next[0] = -1;
    while( i < plen-1 )
    {
        if( j == -1 || pat[i] == pat[j] )
        {
            i++;j++;
            if( pat[i] != pat[j] )
                next[i] = j;
            else
                next[i] = next[j];
        }
        else
            j = next[j];
    }

}

int Kmp(char *src, int slen, char *pat, int plen, int *next)
{
    int i=0,j=0;
    while( i<slen && j<plen )
    {
        if( j==-1 || src[i] == pat[j] )
        {
            i++;j++;
        }
        else
            j = next[j];
    }
    if( j >= plen )
        return (i-plen);
    else
        return -1;
}

int main()
{
    char *src, *pat;
    int slen, plen;
    while( scanf("%s%s", str1, str2) != -1 )
    {
        memset(pmt, 0, sizeof(int)*Max);
        if( strlen(str1) <= strlen(str2) )
        {
            src = str2; slen = strlen(str2);
            pat = str1; plen = strlen(str1);
        }
        else
        {
            src = str1; slen = strlen(str1);
            pat = str2; plen = strlen(str2);
        }
        get_next(pat, plen, pmt);
        if ( Kmp(src, slen, pat, plen, pmt) == -1 )
            printf("No\n");
        else
            printf("Yes\n");
    }
    return 0;
}
