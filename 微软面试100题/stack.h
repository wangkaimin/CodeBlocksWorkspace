#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

struct tagMinStackData
{
    int val;
    int min;
};

typedef struct tagMinStack
{
    struct tagMinStackData *data;
    int top;
    int max;
} MinStack;

int init(MinStack **ms, int max);
int push(MinStack *ms, int val);
int pop(MinStack *ms, int *val);
int min(MinStack *ms, int *val);

#endif // STACK_H_INCLUDED
