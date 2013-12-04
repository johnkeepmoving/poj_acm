#include<stdio.h>
#include<string.h>

#define MAX 100001
#define WORD_LEN 12
#define HASH_NUM 1000000 

typedef struct node
{
    char e_word[11];
    char f_word[11];
    int next;
}Node;

Node po[MAX];
int head[HASH_NUM];

int main()
{
    memset(head, -1, sizeof(head));
    char str[25];
    int num = 0;

    while( gets(str) && strcmp(str,"")!= 0)
    {
        int i, len = strlen(str);
        for(i=0; i<len; i++)
            if(str[i] == ' ')
            {
                str[i] = '\0';
                break;
            }
        strcpy(po[num].e_word, str);
        strcpy(po[num].f_word, str+(i+1));
        int m = 1;
        int len_2 = strlen(po[num].f_word);
        for(i=0; i<len_2; i++) m=( m*( po[num].f_word )[i] )%HASH_NUM;
        po[num].next = head[m];
        head[m] = num;
        num++;
    }
    while( scanf("%s", str) != -1 )
    {
        int h, m=1, len=strlen(str);
        int i;
        for(i=0; i<len; i++) m=(m*str[i])%HASH_NUM;
        h = head[m];
        while( h != -1 )
        {
            if( strcmp(po[h].f_word, str) == 0 )
            {
                printf("%s\n",po[h].e_word);
                break;
            }
            h = po[h].next;
        }
        if( h == -1 ) printf("eh\n");
    }
    return 0;
}