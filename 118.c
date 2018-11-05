#include <stdio.h>
#include <stdlib.h>

/**
 * Return an array of arrays.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generate(int numRows, int** columnSizes) {
    int **res;
    res = (int **)malloc(sizeof(int *) * numRows);
    *columnSizes = (int *)malloc(sizeof(int ) * numRows);

    for (int i = 0; i < numRows; i++)
    {
        res[i] = (int *)malloc(sizeof(int)*(i+1));
        (*columnSizes)[i] = i + 1;

        res[i][0] = 1;
        res[i][i] = 1;

        for (int j = 1; j < i; j++)
        {
            res[i][j] = res[i-1][j-1] + res[i-1][j];
        }
    }
    
    return res;
}

int main(int argc, char const *argv[])
{
    int numRows, ** columnSizes, **res;

    numRows = 5;
    columnSizes = (int **)malloc(sizeof(int *) * numRows);

    res = generate(numRows, columnSizes); 

    for(int i = 0; i < numRows; i++)
    {
        
        for(int j = 0; j < i + 1; j++)
        {
            printf("%d ", res[i][j]);
        }
        printf("\n");
        
    }

    return 0;
}
