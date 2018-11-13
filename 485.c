int findMaxConsecutiveOnes(int* nums, int numsSize) {
    int max = nums[0], star = 0, res = 1;
    
    for (int i = 0; i < numsSize; i++)
    {
        res = res * nums[i];
        if (res == 0)
        {
            max = max > i - star ? max : i - star;
            res = 1;
            star = i + 1;
        }
    }
    
    if (res == 1 && star < numsSize)
         max = max > numsSize - star ? max : numsSize - star;
    
    return max;
}