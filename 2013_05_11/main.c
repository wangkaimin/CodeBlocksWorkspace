#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void testSizeofAndStrlen(int a[10])
{
    int b[10];
    int c[10]= {0};
    // 整型数组作为参数 sizeof是指针类型的大小
    printf("sizeof(a)=%d\n",sizeof(a));
    // 一般的局部整型数组 sizeof是单个整型的整数倍
    printf("sizeof(b)=%d\n",sizeof(b));
    // 未初始化的strlen为随机值
    printf("strlen(a)=%d\n",strlen(a));
    printf("strlen(b)=%d\n",strlen(b));
    // 初始化后正常
    printf("strlen(c)=%d\n",strlen(c));
}
void testSizeof()
{
    short testarray[4][3] = { {1}, {2, 3}, {4, 5, 6} };
    printf("sizeof(testarray[4][3])=%d\n",sizeof(testarray));
}
// 中文注释 测试是否乱码？
int main()
{
    int b[10];
    int c[10]= {0};
//    printf("#main begin#\n");
//    printf("sizeof(b)=%d\n",sizeof(b));
//    printf("strlen(b)=%d\n",strlen(b));
//    printf("strlen(c)=%d\n",strlen(c));
//    printf("\n#testSizeofAndStrlen begin#\n");
    //testSizeofAndStrlen(b);
    testSizeof();
    return 0;
}
