/*
 * Write a procedure is_little_endian that will return 1 when compiled and run
 * on a little-endian machine, and will return 0 when compiled and run on a bigendian
 * machine. This program should run on any machine, regardless of its word
 * size.
 */

#include <stdio.h>
#include <stdlib.h>


int is_little_endian(void)
{
    int x = 1;

    /* Return 0 when big-endian, 1 when little-endian */
    return (int) (* (char *) &x);
}

int main()
{
    printf("%d\n",is_little_endian());
    return 0;
}
