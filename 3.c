#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lengthOfLongestSubstring(char *s);
int checkStringIsExit(char *s, char a, int start, int end);

int main(int argc, char const *argv[])
{
    char *s = "abcdfej";

    int maxStringLen = lengthOfLongestSubstring(s);
    printf("max is %d \n", maxStringLen);

    return 0;
}

int lengthOfLongestSubstring(char *s) {
    int max = 0, i = 0, index = 0, start = 0;

    while(s[i]){
        index = checkStringIsExit(s, s[i], start, i);
        
        if (index != -1) {
            start = index + 1;
            i = start;
        } else {
            i++;
        }

        max = max < i - start ? i - start : max;
    }

    return max;
}

// 检查一个字符是否在字符串中，是的话返回index，不是的话返回-1
int checkStringIsExit(char *s, char a, int start, int end)
{
    printf("check %c in string %d ~ %d \n", a, start, end);
    for(int i = start; i < end; i++) {
        if (s[i] == a) {
            printf("checked %c is exit, index %d \n", a, i);
            return i;
        }
        
    }
    printf("check ok, not exit \n");
    return -1;
}
