#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAMELEN 11

#define PEOPLENUM 6

typedef struct {
    char name[NAMELEN];
    int num;
    int time;
} info;
info team[PEOPLENUM]={
    {"wkm",1,123},
    {"abc",1,321},
    {"fda",1,123},
    {"bkm",1,123},
    {"wbc",4,123},
    {"ada",1,123}
};

void printint(int *array, int n)
{
    int i=0;
    for(i=0;i<n-1;i++)
        printf("%d ",array[i]);
    printf("%d\n",array[i]);
}
void printteam(info *team,int n)
{
    int i=0;
    for(i=0;i<n;i++)
        printf("name:%s\tnum:%d\ttime:%d\n",team[i].name,team[i].num,team[i].time);
}
int cmpint(const void * a, const void * b)
{
    return *(int *)a - *(int *)b;
}
int cmpinfo(const void * a, const void * b)
{
    info *c,*d;
    c = (info *)a;
    d = (info *)b;
    if(c->num != d->num)
        return c->num < d->num;
    else if(c->time != d->time)
        return c->time > d->time;
    return strcmp(c->name, d->name);
}
int main()
{
    int array[10]={5,3,1,8,0,7,2,9,4,6};
    printint(array,10);
    qsort(array,10,sizeof(array[0]),cmpint);
    printint(array,10);

//    strcpy(team[0].name,"wkm");
//    team[0].num = 1;
//    team[0].time = 500;
//    strcpy(team[1].name,"abc");
//    team[1].num = 1;
//    team[1].time = 500;
//    strcpy(team[2].name,"gfsdg");
//    team[2].num = 1;
//    team[2].time = 500;
    printteam(team,PEOPLENUM);
    printf("###############\n");
    qsort(team,PEOPLENUM,sizeof(team[0]),cmpinfo);
    printteam(team,PEOPLENUM);
    return 0;
}
