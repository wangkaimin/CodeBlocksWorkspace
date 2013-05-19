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

//④ 所有序号为 (j+i *m) % n (j 表示每个循环链起始位置，i 为计数变量，m表示左旋转位数，n表示字符串长度)
//会构成一个循环链（共有gcd(n,m)个，gcd为n、m的最大公约数）
//每个循环链上的元素只要移动一个位置即可，最后整个过程总共交换了n次
//（每一次循环链，是交换n/gcd(n,m)次，共有gcd(n,m)个循环链，所以，总共交换n次）
int gcd(int a, int b)
{
    int r=a%b;
    while(r)
    {
        a=b;
        b=r;
        r=a%b;
    }
    return b;
}
char *RightShift04(char *str, int k)
{
    int n=strlen(str);
    int i,j;
    char c;
    int num_of_group;
    int elem_i_sub;
    k%=n;
    num_of_group = gcd(n, k);
    elem_i_sub = n / num_of_group;
    for(j=0;j<num_of_group;j++)
    {
        //c = str[j%n];
        c = str[(j+(elem_i_sub-1)*k)%n];
        for(i=elem_i_sub-1;i>0;i--)
            str[(j+i*k)%n]=str[(j+(i-1)*k)%n];
        str[(j+i*k)%n] = c;
    }
    return str;
}

int main()
{
    char str[] = "abcdefghijklmnopqrstuvwxyz";
    fun RightShift = RightShift04;
    printf("%s\tsizeof=%d\tk=%d\n", str, sizeof(str), strlen(str));
    (*RightShift)(str,100);
    printf("%s\n", str);
    return 0;
}
