#include<stdio.h>

#define MAX 18750000

short hash[MAX*2] = { 0 };

int main()
{
    short coeff[5];
    int result = 0;
    int sum = 0;
    if( scanf("%d%d%d%d%d", &coeff, &coeff[1], &coeff[2], &coeff[3], &coeff[4]) == -1 )
        return -1;
    int i, j, k;
    for(i=-50; i<=50; i++)
        for(j=-50; j<=50; j++)
            for(k=-50; k<=50; k++)
            {
                if( i && j && k )
                {
                    result = i*i*i*coeff[0] + j*j*j*coeff[1] + k*k*k*coeff[2];
                    result += MAX;
                    hash[result]++;
                }
            }
    for(i=-50; i<=50; i++)
        for(j=-50; j<=50; j++)
        {
            if( i && j )
            {
                result = -(i*i*i*coeff[3] + j*j*j*coeff[4]);
                result += MAX;
                sum += hash[result];
            }
        }
    printf("%d\n", sum);
    return 0;
}
