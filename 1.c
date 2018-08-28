/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/malloc.h>

#define DEBUG

int* twoSum(int* nums, int numsSize, int target) {
    int *answer = (int *)malloc(sizeof(int) * 2);
    
    for(int left = 0; left < numsSize; left++)
    {
        for(int right  = left + 1; right < numsSize; right++)
        {
            if (nums[left] + nums[right] == target) {
                answer[0] = left;
                answer[1] = right;
                break;
            }
        }
        
    }

    return answer;
}

#ifdef DEBUG

int main(void)
{
    int nums[5] = {3, 2, 4};
    int *answer = NULL;
    answer = twoSum(nums, 3, 6);
    printf("[%d, %d]\n", answer[0], answer[1]);
}
#endif