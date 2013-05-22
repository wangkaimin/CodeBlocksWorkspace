#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

//typedef char *(* strcpy)(char *, const char*);

// const 2分
char * strcpy01(char *dest, const char * src)
{
    char *temp = dest;
    // 目标、原字符串是否为空3分
    assert(dest != NULL && src != NULL);
    // 2分
    while((*dest++ = *src++) != '\0')
        ;
    // 返回值3分
    return temp;
}
int main()
{
    char str[] = "wangkaimin";
    char *p = NULL;
    p = strcpy01(str,p);
    //p = strcpy01(str,p);
    printf("str=%s\t%s\n",str,p);
    return 0;
}
