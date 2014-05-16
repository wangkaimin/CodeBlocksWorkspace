/* 002 MinStack */
#include <stdlib.h>
#include "stack.h"


int init(MinStack **ms, int max)
{
    *ms = (MinStack *)malloc(sizeof(MinStack));
    if(NULL == *ms)
        return 1;
    (*ms)->data = (struct tagMinStackData *)malloc(max * sizeof(struct tagMinStackData));
    if(NULL == (*ms)->data)
        return 1;
    (*ms)->top = 0;
    (*ms)->max = max;
    return 0;
}

int push(MinStack *ms, int val)
{
    int top;
    if(NULL == ms || ms->max == (top=ms->top))
        return 1;
    if(0 == ms->top)
    {
        (ms->data)[top].min = val;
    }
    else
    {
        if(val < (ms->data)[top-1].min)
            (ms->data)[top].min = val;
        else
            (ms->data)[top].min = (ms->data)[top-1].min;
    }
    (ms->data)[top].val = val;
    (ms->top)++;
    return 0;
}

int pop(MinStack *ms, int *val)
{
    int top;
    if(NULL == ms || 0 == (top = ms->top))
        return 1;
    *val = ms->data[top].val;
    ms->top--;
    return 0;
}

int min(MinStack *ms, int *val)
{
    int top;
    if(NULL == ms || 0 == (top = ms->top))
        return 1;
    *val = (ms->data)[top-1].min;
    return 0;
}
