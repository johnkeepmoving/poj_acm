#include <cstdio>
#define MAX_NUM 1000001
int number, winSize;

int num[MAX_NUM];
int minNum[MAX_NUM];
int maxNum[MAX_NUM];

int ascendNum[MAX_NUM];
int ascendHead = 1;
int ascendTail = 1;

int descendNum[MAX_NUM];
int descendHead = 1;
int descendTail = 1;

void getSolution()
{
    descendHead = 1;
    descendTail = 1; 
    descendNum[descendHead] = 1;
    descendTail++;
    maxNum[1] = num[1]; 

    for(int i=2; i<=number; i++)
    {  
        while ( (descendTail > descendHead) && num[descendNum[descendTail-1]] <= num[i] )
        {
            descendTail--;
        }
        if ( descendTail > descendHead )
        {
            descendNum[descendTail] = i;
            descendTail++;
        }
        else
        {
            //The queue is empty
            descendHead = 1;
            descendTail = descendHead + 1;
            descendNum[descendHead] = i;
        }
        //delete the head element of queue!
        while( descendHead < descendTail && descendNum[descendHead] < (i-winSize+1) )
            descendHead++;
        if (i >= winSize)
            maxNum[i] = num[descendNum[descendHead]];
    }

    ascendHead = 1;
    ascendTail = 1;
    ascendNum[ascendHead] = 1;
    ascendTail++;
    minNum[1] = num[1];
    for(int i=2; i<=number; i++)
    {  
        while ( (ascendTail > ascendHead) && num[ascendNum[ascendTail-1]] >= num[i] )
        {
            ascendTail--;
        }
        if ( ascendTail > ascendHead )
        {
            ascendNum[ascendTail] = i;
            ascendTail++;
        }
        else
        {
            //The queue is empty
            ascendHead = 1;
            ascendTail = ascendHead + 1;
            ascendNum[ascendHead] = i;
        }
        //delete the head element of queue
        while ( ascendHead<ascendTail && ascendNum[ascendHead] < (i-winSize+1) ) 
            ascendHead++;
        if (i >= winSize)
            minNum[i] = num[ascendNum[ascendHead]];
    }
}

int main(int argc, const char *argv[])
{
    while( scanf("%d %d", &number, &winSize) != - 1)
    {
        for(int i=1; i<=number; i++)
            scanf("%d", &num[i]);
        getSolution();
        for(int i=winSize; i<=number; i++)
            printf("%d ", minNum[i]);
        printf("\n"); 
        for(int i=winSize; i<=number; i++)
            printf("%d ", maxNum[i]);
        printf("\n"); 
    }
    return 0;
}
