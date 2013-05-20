#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef int (* cmpstr)(const char *lstr, const char *sstr);
// 最笨的方法 时间复杂度O(n^2)
int compare_string01(char *longstring, char * shortstring)
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
                flag = 0;
        if(flag == 1)
            return 1; // shortstring不完全包含在longstring中
    }
    return 0;
}


int main()
{
    char lstr[] = "wangkaimin.";
    char sstr[] = "kaimin.,";
    cmpstr compare_string = compare_string01;
    if((*compare_string)(lstr,sstr) == 0)
        printf("Yes.\n");
    else
        printf("No.\n");
    return 0;
}
