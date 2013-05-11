/* 【实验要求】
 * 应用需求：判断键盘输入的字符串是否首尾对称。比如，"245542"，"24542"，"a4b1b4a"都是首尾对称的字符串。
 * 问题描述：
 *         1）假设键盘输入的字符串中只包含数字字符和字母字符；
 *         2）键盘输入的字符串所包含的字符数可能是奇数个，也可能是偶数个，因此需首先确定首尾对称的字符串的判断依据；（难点）
 *         3）依据判断依据，可以判别输入字符串是否为首尾对称的字符串。
 * 算法思想：
 *     输入：合法的字符串（通过键盘输入）；
 *     输出：返回判断结果。1表示键盘输入的字符串是首尾对称，0表示键盘输入的字符串不是首尾对称，-1表示错误退出。
 *     算法设计思路的提示：
 *     1、创建空的双向链表；
 *     2、逐字符读取键盘输入的合法字符串，并依次插入到双向链表中。具体的，对于当前读取的字符，
 *     1）构造其对应的结点。
 *     2）利用头插法（或尾插法）将该结点按照键盘输入的顺序插入到双向链表中。
 *     3、判断双向链表中各节点是否首尾对称，并打印出是否首尾对称的提示信息。
 *     （【提示】：可以利用双向链表的头指针和尾指针，其中头指针往链表尾部移动，尾指针向链表头部方向移动。当头尾指针最后能相遇时，则可认为输入字符串是首尾对称的。）
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// 链表的应用头文件
#include "llgen.h"

// 通用链表的头文件
#include "llapp.h"
#define LLHead (L->LHead)      /* The head of the current list */
#define LLTail (L->LTail)      /* The tail of the current list */
#define NodeCount (L->LCount)  /* Nodes in the current list */
// 允许一次输入的最大字符串长度
#define INTPUT_MAX 100

int print(struct List *);
int isSymmetry(struct List *);
int DeleteAllNode(struct List *);

int DeleteAllNode(struct List *L)
{
    while(NodeCount>0)
    {
        DeleteNode(L, LLTail);
    }
    return 1;
}


/*
 *  功能：判断是否对称
 *  参数：
 *  返回值：1：对称
 *          0：不对称
 */
int isSymmetry(struct List *L)
{
    // 数据节点指针
    int tmp = 0, i;
    Link lh,lt;
    lh = LLHead;
    lt = LLTail;
    for(i=1; i<=NodeCount/2; i++)
    {
        //printf("%s\t%s\n",((pND2)(lh->pdata))->word, ((pND2)(lt->pdata))->word);
        //if ( (((pND2)(lh->pdata))->word)[0] == (((pND2)(lt->pdata))->word)[0] )
        if( strcmp( ((pND2)(lh->pdata))->word, ((pND2)(lt->pdata))->word) == 0 )
        {
            lh = lh->next;
            lt = lt->prev;
            continue;
        }
        else
        {
            return 0;
        }
    }
    //printf("OK.\n");
    return 1;
}

int print(struct List * L)
{
    Link lh = LLHead;
    printf("***Begin***\n");
    while(lh!=NULL)
    {
        printf("print(L)=%s\n",((pND2)(lh->pdata))->word);
        lh = lh->next;
    }
    printf("****End****\n");
    return 1;
}

int main(int argc, char *argv[])
{
    // 创建一个结构体（包含双向链表的头指针、尾指针、节点数、一系列函数）的指针
    struct List *L;

    // 数据节点指针
    // Link lh,lt;

    // 输入的字符串
    char str[INTPUT_MAX];
    char ch[2];
    unsigned int i;
    ch[0] = ch[1] = '\0';
    // 创建链表的数据结构
    L = CreateLList( CreateData2,
                     DeleteData2,
                     DuplicatedNode2,
                     NodeDataCmp2 );

    if( L == NULL )
    {
        fprintf(stderr,"Error creating linked list.\n");
        exit(EXIT_FAILURE);
    }

    while(1)
    {
        // 输入字符
        //ch[0] = getchar();
        while(ch[0]=getchar())
        {
            if(ch[0] != '\n')
            {
                if( ! AddNodeAtHead(L,ch) )
                    fprintf(stderr, "Error while adding node to L.\n");
            }
            else if(NodeCount != 0)
            {
                //print(L);
                if(isSymmetry(L) == 1)
                    printf("对称\n");
                else
                    printf("不对称\n");
                DeleteAllNode(L);
            }
        }

    }
    return 0;
}
