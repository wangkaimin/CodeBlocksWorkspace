#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef char *(* fun) (char *, int);

// 最简单的想法：k次的循环右移
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

// 增加了k>=len的判断
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

// 假设原数组序列为abcd1234，要求变换成的数组序列为1234abcd，即循环右移了4位。
// 比较之后，不难看出，其中有两段的顺序是不变的：1234和abcd，可把这两段看成两个整体。
// 右移K位的过程就是把数组的两部分交换一下。
// 变换的过程通过以下步骤完成：
// 逆序排列abcd：abcd1234 → dcba1234；
// 逆序排列1234：dcba1234 → dcba4321；
// 全部逆序：dcba4321 → 1234abcd。
char *Reverse(char *str, int begin, int end)
{
    int i=0, j=0;
    char c;
    for(i=begin, j=end; i<j; i++,j--)
    {
        c = str[i];
        str[i] = str[j];
        str[j] = c;
    }
    return str;
}

char * RightShift03(char *str, int k)
{
    int i, len = strlen(str);
    char c;
    k %= len;
    Reverse(str, 0, len - k - 1 );
    Reverse(str, len - k, len - 1 );
    Reverse(str, 0, len - 1 );
    return str;
}
int main()
{
    char str[] = "abcdefghijklmnopqrstuvwxyz";
    fun RightShift = RightShift03;
    printf("%s\tsizeof=%d\tk=%d\n", str, sizeof(str), strlen(str));
    (*RightShift)(str,100);
    printf("%s\n", str);
    return 0;
}
