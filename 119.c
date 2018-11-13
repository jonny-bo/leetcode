/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getRow(int rowIndex, int* returnSize) {
    int * res, temp;
    
    res = (int *)malloc(sizeof(int)* (rowIndex + 1));
    *returnSize = rowIndex + 1;
    for (int i = 0; i <= rowIndex; i++)
    {
        res[i] = 0;
    }
        
    for (int i = 0; i <= rowIndex; i++ )
    {
        if (i == 0)
        {
            res[i] = 1;  
            continue;
        }
        
        for (int j = rowIndex; j > 0; j--)
        {
            res[j] = res[j-1] + res[j];
        }
    }
    
    return res;
}
