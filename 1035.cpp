#include<iostream>
#include<string>
#include<cstdio>
using namespace std;

string dic_str[10003];
int dic_len[10003];

int fix[10003];
int fix_index;

string str;
int len;

bool correct = false;

void Replace(int index)
{
    int num_diff = 0;
    for(int i=0; i<len; i++)
    {
        if( str[i] != dic_str[index][i] )
            num_diff++;
        if( num_diff >= 2 )
            return;
    }
    if( num_diff == 1 )
        fix[fix_index++] = index;
    else
        correct = true;
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
    char tmp[16];
    int n=0;
    while( scanf("%s",tmp) != -1 && tmp[0] != '#' )
    //while( cin>>dic_str[n] && dic_str[n][0] != '#' )
    {
        dic_str[n] = tmp; 
        dic_len[n] = dic_str[n].length();
        n++;
    }
    while( scanf("%s",tmp) != -1 && tmp[0] != '#' )
    //while( cin>>str && str[0] != '#' )
    {
        str = tmp;
        len = str.length();
        fix_index = 0;
        correct = false;
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
            printf("%s is correct\n",str.c_str());
        else
        {
            printf("%s:",str.c_str());
            for(int i=0; i<fix_index; i++)
                printf(" %s",dic_str[fix[i]].c_str());
            printf("\n");
        }
    }
    return 0;
}
