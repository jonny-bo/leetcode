#include <stdlib.h>
#include <stdio.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** transpose(int** A, int ARowSize, int *AColSizes, int** columnSizes, int* returnSize) {
    
    int m = ARowSize;
    int n = *AColSizes;

    int** res;
    res = (int **)malloc(sizeof(int *) * n);
    *columnSizes = malloc(sizeof(int) * n);
    *returnSize = n;

    for(int i = 0; i < n; i++)
    {
        res[i] = (int *)malloc(sizeof(int) * m);
        for(int j = 0; j < m; j++)
        {
            res[i][j] = A[j][i];
        }
        (*columnSizes)[i] = m;
    }

    return res;
}

void printArray(int** A) {
    for(int i = 0; i < 3; i++)
    {    
        for(int j = 0; j < 3; j++)
        {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }
}

int main(int argc, char const *argv[])
{
    int ** A, ARowSize, *AColSizes, ** columnSizes, *returnSize, **res;

    ARowSize = 3;

    AColSizes = malloc(sizeof(int));
    returnSize = malloc(sizeof(int));
    columnSizes = (int **)malloc(sizeof(int *));

    *AColSizes = 3;

    A = (int **)malloc(sizeof(int *) * 3);

    for(int i = 0; i < 3; i++)
    {   
        A[i] = (int *)malloc(sizeof(int) * 3);  
        for(int j = 0; j < 3; j++)
        {
            A[i][j] = i;
        }
    }

    printArray(A);
    printf("\ntranspose return\n");

    res = transpose(A, ARowSize, AColSizes, columnSizes, returnSize);

    printArray(res);

    return 0;
}
