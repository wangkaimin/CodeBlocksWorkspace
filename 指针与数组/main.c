#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a[10] = {9,8,7,6,5,4,3,2,1,0};
    printf("a \t is 0x%08x\n",a);
    printf("&a \t is 0x%08x\n",&a);
    printf("a+1 \t is 0x%08x\n",a+1);
    printf("&a+1 \t is 0x%08x\n",&a+1);
    printf("a+3 \t is 0x%08x\n",a+3);
    printf("&a[3] \t is 0x%08x\n",&a[3]);
    //编译不能通过的
    //printf("&(a+3) \t is 0x%08x\n",&(a+3));
    printf("&a[2] \t is 0x%08x\n",&a[2]);
    printf("(&a)[3] \t is 0x%08x\n",(&a)[3]);
    printf("(a[3] \t is 0x%08x\n",a[3]);
    return 0;
}
