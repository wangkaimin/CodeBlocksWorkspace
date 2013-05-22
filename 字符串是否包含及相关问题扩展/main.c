#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXHASH 256
typedef int (* cmpstr)(const char *lstr, const char *sstr);
// 最笨的方法 时间复杂度O(n^2)
// 遇到字符串时，尽量使用指针，这样简洁
int cmp_str00(const char *lstr, const char *sstr)
{
    int flag = 0;
    char *temp = lstr;
    while(*sstr != '\0')
    {
        while(*temp != '\0')
        {
            if(*sstr == *temp++)
            {
                flag = 1;
                break;
            }
        }
        if(flag == 0)
            return 1;
        flag = 0;
        sstr++;
        temp = lstr;
    }
    return 0;
}
// 最笨的方法 时间复杂度O(n^2)
int cmp_str01(char *longstring, char * shortstring)
{
    int len1 = strlen(longstring);
    int len2 = strlen(shortstring);
    int flag;
    int i, j;
    for(i=0;i<len2;i++)
    {
        flag = 1;
        for(j=0;j<len1;j++)
            if(longstring[j] == shortstring[i])
            {
                flag = 0;
                break;
            }
        if(flag == 1)
            return 1; // shortstring不完全包含在longstring中
    }
    return 0;
}

// 哈希、位图
int cmp_str02(const char *lstr, const char *sstr)
{
    unsigned short int hash[MAXHASH];
    memset(hash, 0, MAXHASH*sizeof(unsigned short int));
    while(*lstr != '\0')
    {
        hash[(*lstr++)] = 1;
    }
    while((*sstr) != '\0')
    {
        if(hash[(unsigned short int)(*sstr++)] != 1)
            return 1; // 不匹配
    }
    return 0;
}
// 素数法
// 只能是小写字母，没有考虑字母多次出现
int cmp_str03(const char* lstr, const char* sstr)
{
    int primenum[26] = { 2, 3, 5, 7, 11,
                        13, 17, 19, 23, 29,
                        31, 37, 41, 43, 47,
                        53, 59, 61, 67, 71,
                        73, 79, 83, 89, 97,
                        101};
    long long int product = 1;
    int i=0;
    for(i=0;i<strlen(lstr);i++)
    {
        product = product*primenum[lstr[i]-'a'];
    }
    for(i=0;i<strlen(sstr);i++)
    {
        if(product % (primenum[sstr[i]-'a']) != 0)
            return 1;
    }
    return 0;
}
int main()
{
    char lstr[] = "wangkaimin";
    char sstr[] = "kaimin";
    cmpstr cmp_str = cmp_str03;
    if((*cmp_str)(lstr,sstr) == 0)
        printf("Yes.\n");
    else
        printf("No.\n");
    return 0;
}
