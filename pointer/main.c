/*
 * Copyright 2007 (c), Shandong University
 * All rights reserved.
 *
 * Filename : test.c
 * Description: about pointer
 * Author : Liu Qingmin
 * Version : 1.0
 * Date : 2007-08-27
 */

#include <stdio.h>

/*
 * define a macro which is used to debug array mode and pointer mode.
 * if 1, debug array mode; else debug pointer mode.
 * You can change it according to your decision.
 */
#define ARRAY_OR_POINTER 1

// http://www.cnblogs.com/csyisong/archive/2010/03/18/1688877.html
int main(void)
{
        char *p1;
        char *p2;
        char **pp;

        //test1

        #if ARRAY_OR_POINTER
                char ch[] = "hello, world!\n";

                printf("%d, %d, %d, %d\n", sizeof(p1), sizeof(p2),
                                           sizeof(pp), sizeof(ch));
        #else
                char *ch = "hello, world!\n";

                printf("%d, %d, %d, %d\n", sizeof(p1), sizeof(p2),
                                           sizeof(pp), sizeof(ch));
        #endif

        //test2

        p1 = ch;

        #if ARRAY_OR_POINTER
                pp = &p1;
        #else
                pp = &ch;
        #endif

        p2 = *pp;


        if (p1 == p2) {
                printf("p1 equals to p2\n");
        } else {
                printf("p1 doesn't equal to p2\n");
        }

        return 0;
}
