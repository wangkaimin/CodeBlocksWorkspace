#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i = 4;

    switch (i)
    {
        default:
        ;
        case 3:
            i += 5;
            if ( i == 8)
            {
                i++;
                if (i == 9) break;
                i *= 2;
            }
            i -= 4;
            break;
        case 8:
            i += 5;
            break;
    }
    printf("i = %d\n", i);
    return 0;
}
