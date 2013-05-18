#include <stdio.h>
#include <stdlib.h>

unsigned short int ui;
signed short int si;

int main()
{
    ui=(unsigned short int)0x8000u;
    si=(signed short int)0x8000;
    printf("ui\t%u\n",ui);
    printf("si\t%d\n",si);
    ui>>=1;
    si>>=1;
    printf("ui\t%u\n",ui);
    printf("si\t%d\n",si);
    printf("#############\n");
    ui=(unsigned short int)0x8000;
    si=(signed short int)0x8000;
    printf("ui\t%u\n",ui);
    printf("si\t%d\n",si);
    ui=(signed short int)ui>>1;
    si=(unsigned short int)si>>1;
    printf("ui\t%u\n",ui);
    printf("si\t%d\n",si);
    return 0;
}
