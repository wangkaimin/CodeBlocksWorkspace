/*
* 首先，逐行读取指定文件中的数据，并进行解析后保存在顺序表中。
* 其中，文件中每行数据格式为“学号,姓名,年龄”，比如“SA10225048,张三,24”。
*
* （提示：采用顺序表结构时，顺序表中每个表元素包含三类信息：学号，姓名，和年龄；
* 采用单链表结构时，单链表中每个结点的数据域包含三类信息：学号，姓名，和年龄。）
*
* 再根据键盘输入进行相关操作（查找，删除和插入）。
* 比如，若键盘输入为“P3”，则表示打印出第3项的信息
* （注意：采用顺序表结构时，第3项数据对应下标为2的表元素；
* 采用单链表结构时，第3项数据对应链表中第3个结点的信息；）；
*
* 若键盘输入为“D3”，则表示删除第3个表元素；
*
* 若键盘输入为“I3,SA10225038,张四,24”，
* 则表示在第3项前插入一个学生的信息（SA10225038,张四,24）。
*/


#include <stdio.h>
#include <stdlib.h>

#define MAX_NAME    20
#define MAX_ID      11

struct Node
{
    char *id;
    char *name;
    unsigned int age;
    struct Node *next;
};

typedef struct Node *pstu;
pstu head;
unsigned count;

void init();
pstu str2stu(char*);
int ins(unsigned, char*);
int del(unsigned);
int print(unsigned);
void freeNode(pstu);
void destroyNode();

int main()
{
    char comm[50];
    int pos;
    init();

    while(scanf("%s",comm) != EOF)
    {
        sscanf(comm+1,"%d",&pos);
        switch(comm[0])
        {
        case 'P':
            print(pos);
            fflush(stdin);
            break;
        case 'D':
            del(pos);
            fflush(stdin);
            break;
        case 'I':
            ins(pos, comm+3);
            fflush(stdin);
            break;
        default :
            break;
        }
        if(comm[0] == '0')
        {
            printf("exit");
            break;
        }
    }
    destroyNode();
    return 0;
}

void init()
{
    int i=0;
    char stu[50];
//    head = (pstu)malloc(sizeof(struct Node));
//    if(head == NULL)
//        exit(1);
//    head->next = NULL;
    head = NULL;
    count = 0;
    printf("Initting, insert from Lab1test.DAT\n");

    if(freopen("Lab1test.DAT","r",stdin) != NULL)
    {

        while(scanf("%s",stu) != EOF)
        {
            ins(++i,stu);
        }
        //fclose(stdin);
        freopen("CON","r",stdin);
        printf("Successfully insert %d data.\n",count);
    }
    else
        printf("初始文件Lab1test.DAT不存在，你可以手动插入\n");
}

pstu str2stu(char *stu)
{
    int i;
    pstu p=(pstu)malloc(sizeof(struct Node));
    if(p == NULL)
        exit(1);
    p->id = (char*)malloc(sizeof(char)*MAX_ID);
    p->name = (char*)malloc(sizeof(char)*MAX_NAME);
    if(p->id == NULL || p->name == NULL)
        exit(1);
    for(i=0; stu[i] != '\0'; i++)
        if(stu[i] == ',')
            stu[i] = ' ';
    //printf("%s\n",stu);
    sscanf(stu,"%s%*c%s%*c%d",p->id,p->name,&p->age);
    //printf("%s %s %d\n",p->id,p->name,p->age);
    return p;
}

int ins(unsigned pos, char *stu)
{
    int i;
    pstu now, to_add;
    pstu dump = (pstu)malloc(sizeof(struct Node));
    if(dump == NULL)
        exit(1);
    dump->next = head;
    now = dump;
    if(pos > count+1)
        return 1;
    to_add = str2stu(stu);
    for(i=1; i<pos; i++)
    {
        now = now->next;
    }
    to_add->next = now->next;
    now->next = to_add;
    count++;
    printf("Successfully insert %s\n",stu);
    head = dump->next;
    free(dump);
    return 0;
}
int del(unsigned pos)
{
    int i;
    pstu dump = (pstu)malloc(sizeof(struct Node));
    if(dump == NULL)
        exit(1);
    dump->next = head;
    pstu pre=dump, now;
    if(pos <=0 || pos > count)
        return 1;
    for(i=1; i<pos; i++)
    {
        pre = pre->next;
    }
    now = pre->next;
    pre->next = now->next;
    printf("Successfully delete Info %s %s %d\n",now->id,now->name,now->age);
    freeNode(now);
    count--;
    head = dump->next;
    free(dump);
    return 0;
}
int print(unsigned pos)
{
    int i;
    pstu dump = (pstu)malloc(sizeof(struct Node));
    if(dump == NULL)
        exit(1);
    dump->next = head;
    pstu now = dump;
    if(pos <=0 || pos > count)
        return 1;
    for(i=1; i<=pos; i++)
    {
        now = now->next;
    }
    printf("%s %s %d\n",now->id,now->name,now->age);
    free(dump);
    return 0;
}
void freeNode(pstu now)
{
    free(now->id);
    free(now->name);
    free(now);
}
void destroyNode()
{
    pstu now;
    while(head->next != NULL)
    {
        now = head->next;
        head->next = now->next;
        freeNode(now);
    }
    free(head);
}
