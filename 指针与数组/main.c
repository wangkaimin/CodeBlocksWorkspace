#include <stdio.h>
#include <stdlib.h>
#define ARRAY_OR_POINTER 0

void test1()
{
    char a[20];
    char *b, (*c)[20]; /* c的类型为“指向含20个char元素的数组的指针” */
    b=&a; /* 编译不过，因类型不匹配 */
    b=a;  /* OK */
    c=&a; /* OK */
    c=a; /* 编译不过，因类型不匹配 */
}

void test2()
{
    int a[10] = {9,8,7,6,5,4,3,2,1,0};
    int *p=NULL;
    printf("a \t is 0x%08x\n",a);
    printf("&a \t is 0x%08x\n",&a);
    printf("a+1 \t is 0x%08x\n",a+1);
    // &a+1 是增加了10*4个字节的长度
    // &array表示整个数组的地址
    printf("&a+1 \t is 0x%08x\n",&a+1);
    printf("a+3 \t is 0x%08x\n",a+3);
    printf("&a[3] \t is 0x%08x\n",&a[3]);
    //编译不能通过的
    //printf("&(a+3) \t is 0x%08x\n",&(a+3));
    printf("&a[2] \t is 0x%08x\n",&a[2]);
    printf("(&a)[3] \t is 0x%08x\n",(&a)[3]);
    printf("(a[3] \t is 0x%08x\n",a[3]);
}

void test3()
{
    int a[10] = {9,8,7,6,5,4,3,2,1,0};
    int *p=NULL;
    printf("指针与数组的区别\n");
    p=a;
    printf("p \t is 0x%08x\n",p);
    p = a+1;
    printf("p=a+1 \t is 0x%08x\n",p);
    ++p;
    printf("++p \t is 0x%08x\n",p);

    p=&a+1;
    printf("p \t is 0x%08x\n",p);
    ++p;
    printf("++p \t is 0x%08x\n",p);
}
int main()
{
    test1();
    return 0;
}
