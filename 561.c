#include <stdio.h>
#include <stdlib.h>

int arrayPairSum(int* nums, int numsSize) {
    int new[20001] = {0}, i = 0, count = 0, sum = 0, flag = 1;

    for(i = 0; i < numsSize; i++)
    {
        new[nums[i] + 10000]++;
    }
    
    for(i = 0; i < 20001 && count < numsSize / 2;)
    {
        if (new[i] > 0) {
            if (flag) {
                sum = sum + i - 10000;
                count++;
                flag = 0;
                new[i]--;
            } else {
                flag = 1;
                new[i]--;
            }
            
        } else {
            i++;
        }
    }
    
    return sum;
}

int main(int argc, char const *argv[])
{
    int arr[] ={1,4,3,2,2,9};
    printf("%d\n",arrayPairSum(arr, 6));

    return 0;
}
