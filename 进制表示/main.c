#include <stdio.h>
#include <stdlib.h>

void test1()
{
    int a=011;
    printf("0%o\n",a);
    a = 0x11;
    printf("%i\n",a);
    a = 0;
}

int main()
{
    test1();
    return 0;
}
