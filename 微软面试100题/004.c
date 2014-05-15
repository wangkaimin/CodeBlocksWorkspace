/*
004、在二元树中找出和为某一值的所有路径
题目：输入一个整数和棵二元树。
从树的根结点开始往下访问一直到叶所经过有形成条路径。
打印出和与输入整数相等的所有路径。
*/
#include "tree.h"
#include <stdio.h>

static void printPath(int path[], int top)
{
    int i=0;
    for(i=0;i<top-1;i++)
        printf("%d ", path[i]);
    printf("%d\n", path[i]);
}

static void helper(BinaryTree *root, int sum, int path[], int top)
{
    path[top] = root->e;
    sum -= path[top];
    top++;
    if(NULL == root->pLeft && NULL == root->pRight)
    {
        if(0 == sum)
            printPath(path, top);
    }
    else
    {
        if(NULL != root->pLeft)
            helper(root->pLeft, sum, path, top);
        if(NULL != root->pRight)
            helper(root->pRight, sum, path, top);
    }
    top--;
    sum += root->e;
}

void printPaths(BinaryTree *root, int sum)
{
    int top=0;
    int path[TREE_DEPTH];
    helper(root, sum, path, top);
}
