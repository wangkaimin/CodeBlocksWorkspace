#include <stdio.h>
#include <stdlib.h>
void testSizeof(int a[10])
{
    int b[10];
    int c[10]={0};
    printf("sizeof(a)=%d\n",sizeof(a));
    printf("sizeof(b)=%d\n",sizeof(b));
    printf("strlen(a)=%d\n",strlen(a));
    printf("strlen(b)=%d\n",strlen(b));
    printf("strlen(c)=%d\n",strlen(c));
}
// 中文注释 测试是否乱码？
int main()
{
    int b[10];
    int c[10]={0};
    printf("#main begin#\n");
    printf("sizeof(b)=%d\n",sizeof(b));
    printf("strlen(b)=%d\n",strlen(b));
    printf("strlen(c)=%d\n",strlen(c));
    printf("\n#testSizeof begin#\n");
    testSizeof(b);
    return 0;
}
