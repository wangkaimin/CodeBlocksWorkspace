#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "sorthdr.h"
#include "sortsub.h"

/* Bubble sort an array */
void BubbleSort ( Element **Array, int N, CompFunc Compare )
{
    int limit, j;
    int comparing_times=0, exchange_times=0;

    /* Make steadily shorter passes ... */
    for ( limit = N - 1; limit > 0; limit-- )
    {
        /* On each pass, sweep largest element to end of array */
        for ( j = 0; j < limit; j++ )
        {
            if ( Compare ( Array[j], Array[j+1] ) > 0 )
            {
                Element *temp;
                temp = Array[j];
                Array[j] = Array[j+1];
                Array[j+1] = temp;
                exchange_times++;
            }
            comparing_times += limit;
        }
        if ( !exchange_times )
            break; /* if no swaps, we have finished */
    }
    printf("比较次数：%d\t交换次数：%d\n",comparing_times,exchange_times);
}

void SelectSort( Element **Array, int N, CompFunc Compare )
{
    int i, j, pos;
    Element *temp;
    int comparing_times=0, exchange_times=0;
    for ( i = 0; i<N; i++ )
    {
        temp = Array[i];
        pos = i;
        for ( j = i+1; j < N; j++ )
        {
            if ( Compare ( temp, Array[j] ) > 0 )
            {
                temp = Array[j];
                pos = j;
                exchange_times++;
            }
        }
        comparing_times += N-i-1;
        Array[pos] = Array[i];
        Array[i] = temp;
    }
    printf("比较次数：%d\t交换次数：%d\n",comparing_times,exchange_times);
}
/* Insertion sort of an array */
void InsertionSort ( Element **Array, int N, CompFunc Compare )
{
    int step;
    int comparing_times=0, exchange_times=0;
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
                exchange_times++;
            }
            else /* Found it! */
                break;
        }
        comparing_times += step;
        /* Now insert original value from Array[step] */
        Array[i+1] = temp;
    }
    //exchange_times += N-1;
    printf("比较次数：%d\t交换次数：%d\n",comparing_times,exchange_times/3);
}

/* Shell's sort on an array */
void ShellSort ( Element **Array, int N, CompFunc Compare )
{
    int step, h;
    int comparing_times=0, exchange_times=0;
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
                    exchange_times++;
                }
                else /* Found it! */
                    break;
            }
            comparing_times += step-h+1;
            /* Now insert original value from Array[step] */
            Array[i + h] = temp;
        }
    }
    printf("比较次数：%d\t交换次数：%d\n",comparing_times,exchange_times);
}
/*
 * A comparison function
 */
int Cfunc ( Element *L, Element *R )
{
    //return ( strncmp ( L->text, R->text, 5 ));
    return (L->text) == (R->text) ? 0 : ((L->text) > (R->text) ? 1 : -1);
}
void showmenu()
{
    printf("\n--------其它键退出--------\n");
    printf("0、不排序\t1、冒泡排序\n");
    printf("2、选择排序\t3、插入排序\n");
    printf("4、希尔排序\n");
    printf("Input select：\n");
}
int main ( int argc, char *argv[] )
{
    Element **Array;
    int Items = 2000, i;
    void (*fun[5]) ( Element **, int, CompFunc);
    fun[1] = BubbleSort;
    fun[2] = SelectSort;
    fun[3] = InsertionSort;
    fun[4] = ShellSort;
    if ( argc != 2 && argc != 3 )
    {
        fprintf ( stderr, "Usage: insert infile [maxitems]\n" );
        return 1;
    }

    if ( argc == 3 )
        Items = atoi ( argv[2] );

    if (( Items = LoadArray ( argv[1], Items, &Array )) == -1 )
        return 1; /* Couldn't load file */
    showmenu();
    while(scanf("%d",&i)!=EOF && i>=0 && i<=4)
    {
        if(i!=0)
            fun[i] ( Array, Items, (CompFunc) Cfunc );
        ShowArray ( Array, Items, (CompFunc) Cfunc );
        showmenu();
    }

    return 0;
}
