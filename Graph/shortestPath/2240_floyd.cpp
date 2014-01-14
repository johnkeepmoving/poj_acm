#include<cstdio>
#include<cstring>
using namespace std;
#define INF 200000000
#define MAX_NUM_CURRENCY 31
char currencyName[MAX_NUM_CURRENCY][30]; int numCurrency;
float table[MAX_NUM_CURRENCY][MAX_NUM_CURRENCY];

void Floyd()
{
    for(int k=1; k<=numCurrency; k++)
        for(int i=1; i<=numCurrency; i++)
            for(int j=1; j<=numCurrency; j++)
                if (table[i][j] < (table[i][k]*table[k][j]))
                    table[i][j] = table[i][k]*table[k][j];
}

int main()
{
    char srcCurrency[30], dstCurrency[30];
    int srcID, dstID;
    float tradeRate;
    int numCase = 0;
    while( scanf("%d", &numCurrency) != -1 && numCurrency != 0 )
    {
        //set the table
        for(int i=1; i<=numCurrency; i++)
            for(int j=1; j<=numCurrency; j++)
                table[i][j] = (i == j? 1:-INF);
        //read data
        for(int i=1; i<=numCurrency; i++)
            scanf("%s", currencyName[i]);
        int numTable;
        scanf("%d", &numTable);
        for(int i=1; i<=numTable; i++)
        {
            srcID = -1;
            dstID = -1;
            scanf("%s%f%s", srcCurrency, &tradeRate, dstCurrency);
            for(int j=1; j<=numCurrency; j++)
            {
                if (strcmp(currencyName[j], srcCurrency) == 0)
                    srcID = j;
                if (strcmp(currencyName[j], dstCurrency) == 0)
                    dstID = j;
                if( srcID != -1 && dstID != -1 )
                    break;
            }
            table[srcID][dstID] = tradeRate;
        }
        Floyd();
        bool result = false;
        for(int i=1; i<=numCurrency; i++)
            if( table[i][i] > 1 )
            {
                result = true;
                break;
            }
        if (result)
            printf("Case %d: Yes\n", ++numCase);
        else
            printf("Case %d: No\n", ++numCase);
    }
    return 0;
}
