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
#include <string.h>

#define MAX_NAME    20
#define MAX_ID      12
#define FIRST_MALLOC    100
#define SECOND_REALLOC  50

struct Node
{
    char id[MAX_ID];
    char name[MAX_NAME];
    unsigned int age;
};

typedef struct Node *pstu;

struct Node1 {
    pstu stu;
    unsigned count; // 学生数据
    unsigned cap;   // 已分配大小
} stus;

void init();
pstu str2stu(char*);
void stucpy(pstu, pstu);
pstu alloc(pstu);
void firstmalloc();
void secondrealloc();
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
        pos = 0;
        sscanf(comm+1,"%d",&pos);
        if(comm[0] == '0')
        {
            printf("exit");
            break;
        }
        if(pos == 0)
            continue;
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
    }
    destroyNode();
    return 0;
}

void init()
{
    int i=0;
    char stu[50];
    if(stus.cap == 0)
        firstmalloc();
    printf("Initting, insert from Lab1test.DAT\n");
    if(freopen("Lab1test.DAT","r",stdin) != NULL)
    {

        while(scanf("%s",stu) != EOF)
        {
            ins(++i,stu);
        }
        //fclose(stdin);
        freopen("CON","r",stdin);
        //printf("Successfully insert %d data.\n",stus.count);
    }
    else
    {
        freopen("CON","r",stdin);
        printf("初始文件Lab1test.DAT不存在，你可以手动插入\n");
    }

}

pstu str2stu(char stu[])
{
    int i;
    pstu p=(pstu)malloc(sizeof(struct Node));
    if(p == NULL)
        exit(1);
    for(i=0; stu[i] != '\0'; i++)
        if(stu[i] == ',')
            stu[i] = ' ';
    //printf("stu=%s\n",stu);
    sscanf(stu,"%s%*c%s%*c%d",p->id,p->name,&p->age);
    //printf("id=%s name=%s age=%d\n",p->id,p->name,p->age);
    return p;
}

void stucpy(pstu src, pstu dst)
{
    strcpy(src->id, dst->id);
    strcpy(src->name, dst->name);
    src->age = dst->age;
}


void firstmalloc()
{
    stus.stu = (pstu)malloc(sizeof(struct Node)*FIRST_MALLOC);
    if(stus.stu == NULL)
        exit(1);
    stus.cap = FIRST_MALLOC;
    stus.count = 0;
    //printf("FirstMalloc();\n");
}

void secondrealloc()
{
    stus.stu = (pstu)realloc(stus.stu,sizeof(struct Node)*(SECOND_REALLOC+stus.cap));
    if(stus.stu == NULL)
    {
        exit(0);
    }
    stus.cap += SECOND_REALLOC;
    //printf("SecondRealloc();\n");
}

int ins(unsigned pos, char stu[])
{
    int i;
    pstu to_add;
    if(pos<1 || pos > stus.count+1)
        return 1;
    if(stus.count == stus.cap)
        secondrealloc();
    to_add = str2stu(stu);

    for(i=stus.count;i>=pos;i--)
    {
        stucpy(&(stus.stu[i]), &(stus.stu[i-1]));
    }

    stucpy(&(stus.stu[i]), to_add);
    stus.count++;
    printf("Successfully insert %s\n",stu);
    freeNode(to_add);
    return 0;
}
int del(unsigned pos)
{
    int i;
    if(pos <1 || pos > stus.count)
        return 1;
    printf("Successfully delete Info %s %s %d\n",
           stus.stu[pos-1].id,stus.stu[pos-1].name,stus.stu[pos-1].age);
    for(i=pos-1; i<stus.count-1; i++)
    {
        stucpy(&(stus.stu[i]), &(stus.stu[i+1]));
    }
    stus.count--;
    return 0;
}
int print(unsigned pos)
{
    pstu now;
    if(pos <1 || pos > stus.count)
        return 1;
    now = &stus.stu[pos-1];
    printf("%s %s %d\n",now->id,now->name,now->age);
    return 0;
}
void freeNode(pstu now)
{
    free(now);
}
void destroyNode()
{
    free(stus.stu);
}
