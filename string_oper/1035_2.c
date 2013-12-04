#include<stdio.h>
#include<string.h>

char *dic_str[10003] = { NULL };
int dic_len[10003];

int fix[10003];
int fix_index;

char str[16];
int len;

int correct = 0;

void Replace(int index)
{
    int num_diff = 0;
    int i;
    for(i=0; i<len; i++)
    {
        if( str[i] != dic_str[index][i] )
            num_diff++;
        if( num_diff >= 2 )
            return;
    }
    if( num_diff == 1 )
        fix[fix_index++] = index;
    else
        correct = 1;
    return;
}

void Add(int index) //str'len = dic_len[index] + 1
{
    int i=0,j=0;
    int num_diff = 0;
    while( i<len && j<(len-1))
    {
        if( str[i] != dic_str[index][j] )
        {
            num_diff++;
            i++;
        }
        else
        {
            i++;
            j++;
        }
        if( num_diff >= 2 )
            return;
    }
    fix[fix_index++] = index;
    return;
}

void Delete(int index)
{
    int i=0,j=0;
    int num_diff = 0;
    while(i<len && j<(len+1))
    {
        if( str[i] != dic_str[index][j] )
        {
            num_diff++;
            j++;
        }
        else
        {
            i++;
            j++;
        }
        if( num_diff >= 2 )
            return;
    }
    fix[fix_index++] = index;
    return;
}

int main()
{
    int n=0;
    dic_str[n] = (char *)malloc(sizeof(char)*16);     
    while( scanf("%s",dic_str[n]) != -1 && dic_str[n][0] != '#' )
    {
        dic_len[n] = strlen( dic_str[n] );
        dic_str[n+1] = (char *)malloc(sizeof(char)*16);
        n++;
    }
    while( scanf("%s",str) != -1 && str[0] != '#' )
    {
        len = strlen( str );
        fix_index = 0;
        correct = 0;
        int i=0;
        while(i<n && !correct)
        {
            if( len == dic_len[i] )
            {
                Replace(i);
            }else if( len-1 == dic_len[i])
                Add(i);
            else if( len+1 == dic_len[i])
                Delete(i);
            i++;
        }
        if( correct )
            printf("%s is correct\n",str);
        else
        {
            printf("%s:",str);
            int i;
            for(i=0; i<fix_index; i++)
                printf(" %s",dic_str[fix[i]]);
            printf("\n");
        }
    }
    return 0;
}
