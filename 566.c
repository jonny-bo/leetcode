#include <stdio.h>
#include <stdlib.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** matrixReshape(int** nums, int numsRowSize, int numsColSize, int r, int c, int** columnSizes, int* returnSize) {
    int **res;
    int *arr;

    if (numsRowSize * numsColSize != r * c)
    {
        r = numsRowSize;
        c = numsColSize;
    }

    res = (int **)malloc(sizeof(int *)*r);
    arr = (int *)malloc(sizeof(int)*r*c);
    *columnSizes = malloc(sizeof(int) * r);

    int index = 0;
    *returnSize = r;

    for (int i = 0; i < numsRowSize; i++)
    {
        for (int j = 0; j < numsColSize; j++)
        {
            arr[index] = nums[i][j];
            index++;
        }
    }

    index = 0;
    for (int i = 0; i < r; i++)
    {
        res[i] = (int *)malloc(sizeof(int)*c);
        (*columnSizes)[i] = c;

        for (int j = 0; j < c; j++)
        {
            res[i][j] = arr[index];
            index++;
        }
    }

    return res;
}

void printArray(int** A, int row, int col) {
    for(int i = 0; i < row; i++)
    {    
        for(int j = 0; j < col; j++)
        {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }
}

int main(int argc, char const *argv[])
{
    int **res, **columnSizes, *returnSize, **nums;
    int row = 2, col = 3, r = 3, c = 2;

    nums = (int **)malloc(sizeof(int *)*row);
    
    columnSizes = (int **)malloc(sizeof(int *));
    returnSize = malloc(sizeof(int));

    for(int i = 0; i < row; i++)
    {
        nums[i] = (int *)malloc(sizeof(int)*col);
        for(int j = 0; j < col; j++)
        {
            nums[i][j] = i + j + 1;
        }
    }

    printArray(nums, row, col);

    res = matrixReshape(nums, row, col, r, c, columnSizes, returnSize);
    
    printArray(res, r, c);
    
    return 0;
}
