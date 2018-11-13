#include <stdio.h>
#include <stdlib.h>

typedef struct hashmap {
    int freq;
    int loc[2];
} hash_m;

int findShortestSubArray(int* nums, int numsSize) {
    hash_m hash[50000] = {0};
    int max = 0, val;

    for (int i = 0; i < numsSize; i++)
    {
        if (hash[num[i]].freq == 0) {
            hash[num[i]].loc[0] = i;
            hash[num[i]].loc[1] = i;
        } else {
            hash[num[i]].loc[1] = i;
        }
        hash[num[i]].freq++;
    }

    for (int i = 0; i < numsSize; i++)
    {
        if (max < hash[num[i]].freq)
        {
            max = hash[num[i]].freq;
            val = hash[num[i]].loc[1] - hash[num[i]].loc[0];
        } else if (max == hash[num[i]].freq)
        {
            val = val < hash[num[i]].loc[1] - hash[num[i]].loc[0] ? val : hash[num[i]].loc[1] - hash[num[i]].loc[0];
        }
    }

    return val + 1;
}