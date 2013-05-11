#include <stdio.h>
#include <stdlib.h>

typedef int (*CompFunc) ( void *, void * );
typedef struct sElement {
    char name[20];
    int num;
    int time;
} Element;

/*
 * A comparison function
 */
 int CompareNameFunc ( Element *L, Element *R )
{
    return ( strncmp ( L->name, R->name, 20 ));
}
int CompareNumFunc ( Element *L, Element *R )
{
    return (L->num) == (R->num) ? 0 : ((L->num) > (R->num) ? -1 : 1);
}
int CompareTimeFunc ( Element *L, Element *R )
{
    return (L->time) == (R->time) ? 0 : ((L->time) > (R->time) ? 1 : -1);
}
void SelectSort( Element **Array, int N, CompFunc Compare )
{
    int i, j, pos;
    Element *temp;
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
            }
        }
        Array[pos] = Array[i];
        Array[i] = temp;
    }
}
int FindDup(Element **Array, int N, CompFunc Compare )
{
    int count=1, i;
    Element *temp;
    for(i=1;i<N;i++)
    {
        if( Compare ( Array[0], Array[i] ) == 0 )
            count++;
        else
            break;
    }
    //printf("count=%d\n",count);
    return count;
}
int main()
{
    int c, n, dup;
    int i,j;
    Element ele[51];
    Element *Array[51];
    freopen("in.txt","rt",stdin);

    while(scanf("%d",&c)!=EOF)
    {
        for(i=0;i<c;i++)
        {
            scanf("%d",&n);
            for(j=0;j<n;j++)
                scanf("%s%d%d",ele[j].name,&(ele[j].num),&(ele[j].time));
            for(j=0;j<n;j++)
                Array[j] = &(ele[j]);
            SelectSort((Element **)Array, n, (CompFunc) CompareNumFunc);
            dup=FindDup((Element **)Array, n, (CompFunc) CompareNumFunc);
            SelectSort((Element **)Array, dup, (CompFunc) CompareTimeFunc);
            dup=FindDup((Element **)Array, n, (CompFunc) CompareTimeFunc);
            SelectSort((Element **)Array, dup, (CompFunc) CompareNameFunc);
            printf("%s\n",Array[0]->name);
        }
    }
    return 0;
}
