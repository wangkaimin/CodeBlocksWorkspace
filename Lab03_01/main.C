#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "llgen.h"
#include "llapp.h"

extern unsigned long ElfHash ( const char *);
void print_element(ElementType *e);
int find_info_by_telnum(char *tel);


#define TABLE_SIZE 10
#define INFO_SIZE 50
#define TELNUM_SIZE 12
#define PATH_SIZE 20


void print_element(ElementType *e)
{
    printf("telnum=%s\t",e->telnum);
    printf("name=%s\t",e->name);
    printf("age=%d\n",e->age);
}

void get_info_from_file(struct List * L[])
{
    FILE *f;
    unsigned hash_key;
    ElementType element;
    char delim[2] = ",";
    char str[INFO_SIZE];
    char fpath[PATH_SIZE] = "Lab3test.DAT";
    f = fopen(fpath,"rt");
    while(fgets(str,INFO_SIZE,f) != NULL) {
        strcpy(element.telnum,strtok(str,delim));
        strcpy(element.name, strtok(NULL, delim));
        element.age = atoi(strtok(NULL, delim));
        hash_key = (ElfHash(element.telnum))%TABLE_SIZE;
        AddNodeAscend(L[hash_key],&element);
        print_element(&element);
    }
}

int find_info_by_telnum(struct List *L[], char *tel)
{
    Link lk;
    lk = L[(ElfHash(tel))%TABLE_SIZE]->LHead;
    while(lk != NULL)
    {
        if(strcmp(tel,((pND1)(lk->pdata))->element->telnum) == 0)
        {
            print_element(((pND1)(lk->pdata))->element);
            return 1;
        }
        lk = lk -> next;
    }
    printf("Not find info.\n");
    return 0;
}
int main()
{
    int i;
    // 创建一个结构体（包含双向链表的头指针、尾指针、节点数、一系列函数）的指针
    struct List *L[TABLE_SIZE];
    // 创建链表的数据结构
    char tel[TELNUM_SIZE];

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
