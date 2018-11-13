```c
bool isMonotonic(int* A, int ASize) {
    if (ASize == 1)
    {
        return true;
    }
    int flag = 0;
    
    for (int i = 1; i < ASize; i++)
    {
        
        if (flag == 0 && A[i] != A[i-1]) { //标记当前是哪种单调，-1 单调递减，1单调递增
            flag = A[i] > A[i-1] ? 1 : -1;
        }
        
        if ((flag > 0 && A[i] - A[i-1] < 0) || (flag < 0 && A[i] - A[i-1] > 0)) //如果出现悖论，则返回false
        {
            return false;
        }
    }
    
    return true;
}
```