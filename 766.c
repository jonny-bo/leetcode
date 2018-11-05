#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isToeplitzMatrix(int** matrix, int matrixRowSize, int *matrixColSizes) {
    if (matrixRowSize == 1 || *matrixColSizes == 1) {
        return true;
    }
    for (int i = 1; i < matrixRowSize; i++) 
    {
        for (int j = 1; j < *matrixColSizes; j++)
        {
            if (matrix[i][j] != matrix[i-1][j-1])
            {
                return false;
            }
        }
    }
    
    return true;
}

int main(int argc, char const *argv[])
{
    int** matrix, matrixRowSize, *matrixColSizes, col;
    bool res;

    matrixRowSize = 3;

    matrixColSizes = (int *)malloc(sizeof(int));
    *matrixColSizes = 3;

    matrix = (int **)malloc(sizeof(int *) * matrixRowSize);

    for(int i = 0; i < matrixRowSize; i++)
    {
        matrix[i] = (int *)malloc(sizeof(int)*(*matrixColSizes));
        
        for(int j = 0; j < (*matrixColSizes); j++)
        {
            matrix[i][j] = j + 2*i + 1;
            
            if (i >= 1 && j >= 1) {
                matrix[i][j] = matrix[i-1][j-1];
            }
            
        }
        
    }

    res = isToeplitzMatrix(matrix, matrixRowSize, matrixColSizes);
    
    printf("%d", res);

    return 0;
}
