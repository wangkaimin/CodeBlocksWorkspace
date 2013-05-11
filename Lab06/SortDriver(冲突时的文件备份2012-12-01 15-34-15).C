#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "sortsub.h"
#include "sorthdr.h"

void BubbleSort ( Element **Array, int N, CompFunc Compare )
{
    int limit;

    /* Make steadily shorter passes ... */
    for ( limit = N - 1; limit > 0; limit-- )
    {
        int j, swapped;

        /* On each pass, sweep largest element to end of array */
        swapped = 0;
        for ( j = 0; j < limit; j++ )
        {
            if ( Compare ( Array[j], Array[j+1] ) > 0 )
            {
                Element *temp;

                temp = Array[j];
                Array[j] = Array[j+1];
                Array[j+1] = temp;
                swapped = 1;
            }
        }

        if ( !swapped )
            break; /* if no swaps, we have finished */
    }
}

void InsertionSort ( Element **Array, int N, CompFunc Compare )
{
    int step;

    /* Look at 2nd thru Nth elements, putting each in place */
    for (step = 1; step < N; step++)
    {
        int i;
        Element *temp;

        /* Now, look to the left and find our spot */
        temp = Array[step];
        for ( i = step - 1; i >= 0; i-- )
        {
            if ( Compare(Array[i], temp ) > 0 )
            {
                /* Not there yet, so make room */
                Array[i+1] = Array[i];
            }
            else /* Found it! */
                break;
        }
        /* Now insert original value from Array[step] */
        Array[i+1] = temp;

    }
}

void ShellSort ( Element **Array, int N, CompFunc Compare )
{
    int step, h;

    /* Find starting h */
    for ( h = 1; h <= N / 9; h = 3*h + 1 )
                ;

    /* Now loop thru successively smaller h's */
    for ( ; h > 0; h /= 3 )
    {
        /* Look at hth thru Nth elements */
        for ( step = h; step < N; step++ )
        {
            int i;
            Element *temp;

            /* Now, look to the left and find our spot */
            temp = Array[step];
            for ( i = step - h; i >= 0; i -= h )
            {
                if ( Compare ( temp, Array[i] ) < 0 )
                {
                    /* Not there yet, so make room */
                    Array[i + h] = Array[i];
                }
                else /* Found it! */
                    break;
            }
            /* Now insert original value from Array[step] */
            Array[i + h] = temp;
        }
    }
}


int main()
{
    printf("Hello world!\n");
    return 0;
}
