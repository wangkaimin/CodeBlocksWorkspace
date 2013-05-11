#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "llgen.h"
#include "llapp.h"

extern unsigned long ElfHash ( const char *);
int CreateTable(Link **t);
int find_info_by_telnum(char *tel);


#define TABLE_SIZE 10
#define INFO_SIZE 50
#define TELNUM_SIZE 12
#define PATH_SIZE 20

void get_info_from_file(struct List * L[])
{
    FILE *f;
    unsigned hash_key;
    char str[INFO_SIZE];
    struct NodeData1 nd1;

    char fpath[PATH_SIZE] = "Lab3test.DAT";
    f = fopen(fpath,"rt");
    while(fgets(str,INFO_SIZE,f) != NULL) {
        strcpy(element.telnum,strtok(str,delim));
        strcpy(element.name, strtok(NULL, delim));
        element.age = atoi(strtok(NULL, delim));
        hash_key = (ElfHash(element.telnum))%TABLE_SIZE;
        //L[hash_key]->LHead = Table[hash_key];
        nd1.element = &element;
        nd1.u = 1;
        printf("ret_Add=%d\n",AddNodeAscend(L[hash_key],&nd1));
        printf("L[hash_key]->LHead=%s\n",((pND1)(L[hash_key]->LHead->pdata))->element->telnum);
        //Table[hash_key] = L->LHead;
        printf_element(&element);
    }
    //check_table();
}

int find_info_by_telnum(struct List *L[], char *tel)
{
    Link lk;
    //lk = Table[(ElfHash(tel))%TABLE_SIZE];
    //lk = lk->next;
    lk = L[(ElfHash(tel))%TABLE_SIZE]->LHead;
    printf("tel=%s\n",tel);
    while(lk != NULL)
    {
        if(strcmp(tel,((pND1)(lk->pdata))->element->telnum) == 0)
        {
            printf("Find telnum=%s\n",tel);
            return 1;
        }
        printf("lk->next\n");
        lk = lk -> next;
    }
    printf("Not find.\n");
    return 0;
}

int main(int argc, char *argv[])
{
    int i;
    // 创建一个结构体（包含双向链表的头指针、尾指针、节点数、一系列函数）的指针
    struct List *L[TABLE_SIZE];
    // 创建链表的数据结构
    char tel[TELNUM_SIZE];


    if(!CreateTable(&Table))
    {
        fprintf(stderr, "Error! Could not create table\n");
        exit(EXIT_FAILURE);
    }
    for(i=0;i<TABLE_SIZE;i++)
    {
        L[i] = CreateLList( CreateData1,
                            DeleteData1,
                            DuplicatedNode1,
                            NodeDataCmp1 );
        if( L[i] == NULL )
        {
            fprintf(stderr,"Error creating linked list.\n");
            exit(EXIT_FAILURE);
        }
    }
    get_info_from_file(L);
    while(scanf("%s",tel)!=EOF)
    {
        find_info_by_telnum(L,tel);
    }
    return 0;
}
