#include <stdio.h>
#include <stdlib.h>

#include "llgen.h"
#include "llapp.h"

extern unsigned long ElfHash ( const char );

#define TABLE_SIZE 10

int main()
{
    int i;
    // 创建一个结构体（包含双向链表的头指针、尾指针、节点数、一系列函数）的指针
    struct List *L[TABLE_SIZE];
    // 创建链表的数据结构
    for(i=0; i<TABLE_SIZE; i++)
        L[i] = CreateLList( CreateData1,
                            DeleteData1,
                            DuplicatedNode1,
                            NodeDataCmp1 );
    if( L == NULL )
    {
        fprintf(stderr,"Error creating linked list.\n");
        exit(EXIT_FAILURE);
    }

    printf("Hello world!\n");
    return 0;
}
