#include <stdio.h>
#include <stdlib.h>

typedef union
{
    char str[9]; //9
    int i; // 4
    long long ll; //8
}test1;

typedef struct {
    int a[7]; //32
    test1 test; // 16
    char c[7]; // 7
} test2;

void sizeoftest()
{
    printf("sizeof(long long)=%d\n",sizeof(long long));
}

int main()
{
    printf("sizeof(test1)=%d\n",sizeof(test1));
    printf("sizeof(test2)=%d\n",sizeof(test2));
    printf("%d\n",sizeof(test1)+sizeof(test2));
    sizeoftest();
    return 0;
}
