#include <stdlib.h>
#include <stdio.h>

int* sortArrayByParity(int* A, int ASize, int* returnSize);

int main(int argc, char const *argv[])
{
    int ASize, *res;
    ASize = 3;

    int *A = (int *)malloc(sizeof(int) * ASize);
    int *returnSize = (int *)malloc(sizeof(int) * 1);
    
    
    for(int j = 0; j < ASize; j++)
    {
        scanf("%d", &A[j]);
    }

    res = sortArrayByParity(A, ASize, returnSize);
    
    
    for(int i = 0; i < ASize; i++)
    {
       printf("%d" , res[i]);
    }
    

    return 0;
}

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortArrayByParity(int* A, int ASize, int* returnSize) {
    int lastIndex = 0;
    int middle;
    *returnSize = ASize;

    for(int i = 0; i < ASize; i++)
    {
        if (A[i] % 2 == 0) {
            middle = A[lastIndex];
            A[lastIndex] = A[i];
            A[i] = middle;
            lastIndex++;
        }
    }

    return A;
}

