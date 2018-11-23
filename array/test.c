#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int *B;
    B = (int *)malloc(sizeof(int)*1);

    *B = 1;

    return 0;
}

int* add(int *A)
{
    (*A)++;
}