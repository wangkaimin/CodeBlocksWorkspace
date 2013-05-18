#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef char *(* fun) (char *, int);

char *RightShift01(char *str, int k)
{
    int i, len = strlen(str);
    char c;
    while(k--)
    {
        c = str[len-1];
        for(i=len-1;i>=1;i--)
            str[i] = str[i-1];
        str[0] = c;
    }
    return str;
}

char *RightShift02(char *str, int k)
{
    int i, len = strlen(str);
    char c;
    k %= len;
    while(k--)
    {
        c = str[len-1];
        for(i=len-1;i>=1;i--)
            str[i] = str[i-1];
        str[0] = c;
    }
    return str;
}
int main()
{
    char str[] = "abcdefghijklmn";
    fun RightShift = RightShift03;
    printf("%s\tsizeof=%d\tk=%d\n", str, sizeof(str), strlen(str));
    (*RightShift)(str,100);
    printf("%s\n", str);
    return 0;
}
