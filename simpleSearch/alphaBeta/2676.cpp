#include <cstdio>
#include <cstring>
#define GetSquare(i, j) ( (i-1)/3*3 + (j-1)/3+1)
int sudoku[10][10];
bool rowFlag[10][10];
bool colFlag[10][10];
bool squareFlag[10][10]; 

bool dfs(int row, int col)
{
    int nextRow = 0;
    int nextCol = 0;
    if ( col < 9)
    {
        nextRow = row;
        nextCol = col + 1;
    }
    else if (row < 9)
    {
        nextRow = row + 1;
        nextCol = 1;
    }
    if( sudoku[row][col] != 0 )
    {
        if ( nextRow==0 && nextCol==0 )
            return true;
        else
            return dfs(nextRow, nextCol);
    }
    //chose a num
    for(int i=1; i<=9; i++)
    {
        if ( !rowFlag[row][i] && !colFlag[col][i] && !squareFlag[GetSquare(row, col)][i] )
        {
            rowFlag[row][i] = true; colFlag[col][i] = true; squareFlag[GetSquare(row, col)][i] = true;
            sudoku[row][col] = i;
            if ( (nextRow==0 && nextCol==0) || dfs(nextRow, nextCol) )
                return true;
            else
            {
                sudoku[row][col] = 0; 
                rowFlag[row][i] = false; colFlag[col][i] = false; squareFlag[GetSquare(row, col)][i] = false;
            }
        }
    }
    return false;
}

void echoAns()
{
    for(int i=1; i<=9; i++)
    { 
        for(int j=1; j<=9; j++)
            printf("%d", sudoku[i][j]);
        printf("\n");
    }
}

int main(int argc, const char *argv[])
{
    int numCase;
    char row[10];
    scanf("%d", &numCase);
    for(int i=1; i<=numCase; i++)
    {
        memset(rowFlag, 0, sizeof(rowFlag));
        memset(colFlag, 0, sizeof(colFlag));
        memset(squareFlag, 0, sizeof(squareFlag));
        for(int j=1; j<=9; j++)
        {
            scanf("%s", row);
            for(int k=1; k<=9; k++)
            {
                sudoku[j][k] = row[k-1] - '0';
                if ( sudoku[j][k] != 0 )
                {
                    rowFlag[j][sudoku[j][k]] = true;
                    colFlag[k][sudoku[j][k]] = true;
                    squareFlag[GetSquare(j,k)][sudoku[j][k]] = true;
                }
            }
        }
        //compute
        if ( dfs(1, 1) )
            echoAns();
        else
            printf("No solution\n");
    }
    return 0;
}
