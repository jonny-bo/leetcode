#include <stdio.h>
#include <stdlib.h>

#define MAX 1000000

int guess(int i)
{
    int l = 0, r = MAX, m;
    int status;
    while (l < r)
    {
        m = (l+r) >> 1;
        printf("guess %d %d\n", i, m);
        fflush(stdout);
        scanf("%d", &status);
        switch (status)
        {
            case -1:
                l = m + 1;
                break;
            case 1:
                r = m - 1;
                break;
            case 0:
                return m;
        }
    }
    return l;
}

int main()
{
    int n, a[100];
    printf("get_num\n");
    fflush(stdout);
    scanf("%d", &n);
    for (int i=0; i<n; i++)
        a[i] = guess(i);
    printf("submit");
    for (int i=0; i<n; i++)
        printf(" %d", a[i]);
    printf("\n");
    fflush(stdout);
}