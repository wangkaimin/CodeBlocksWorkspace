#include <stdio.h>
#include <stdlib.h>
void testSizeof(int a[10])
{
    printf("sizeof(a)=%d",sizeof(a));
}
//Ö÷º¯Êý
int main()
{
    int b[10];
    printf("Hello world!\n");
    printf("sizeof(b)=%d\n",sizeof(b));
    testSizeof(b);
    return 0;
}
