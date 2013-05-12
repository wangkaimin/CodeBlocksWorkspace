#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i=40;
    printf("Begin:\t%i\n",i);
    {
        printf("Before \t int i=10 i=%i\n",i);
        int i=10;
        printf("After \t int i=10 i=%i\n",i);
        //goto lbl;
    }
    {
        printf("Before \t int i=20 i=%i\n",i);
        i=20;
        printf("After \t int i=20 i=%i\n",i);
        {
            printf("Before \t int i=30 i=%i\n",i);
            int i=30;
            printf("After \t int i=30 i=%i\n",i);
            //lbl:;
        }
        printf("After \t {} i=%i\n",i);
    }
    printf("End:\t%i\n",i);
    return 0;
}
