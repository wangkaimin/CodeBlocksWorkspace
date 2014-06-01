#include <stddef.h>

#include "tree.h"

static void helper02(BinaryTree **rightHead, BinaryTree **leftTail, BinaryTree *root);
static void helper01(BinaryTree **rightHead, BinaryTree **leftTail, BinaryTree *root);

BinaryTree *BinaryTreeToDoubleList(BinaryTree *root)
{
    BinaryTree *rightHead=NULL, *leftTail=NULL;
    helper02(&rightHead, &leftTail, root);
    return rightHead;
}
static void helper02(BinaryTree **rightHead, BinaryTree **leftTail, BinaryTree *root)
{
    BinaryTree *rightTail=NULL, *leftHead=NULL;

    if(NULL == root)
    {
        *rightHead = NULL;
        *leftTail = NULL;
        return;
    }

    if(NULL != root->pLeft)
        helper02(rightHead, &rightTail, root->pLeft);
    else
        *rightHead = rightTail = root;

    if(NULL != root->pRight)
        helper02(&leftHead, leftTail, root->pRight);
    else
        *leftTail = leftHead = root;

    //if(*rightHead != *leftTail)
    //{
        if(rightTail != root)
        {
            rightTail->pRight = root;
            root->pLeft = rightTail;
        }
        if(leftHead != root)
        {
            leftHead->pLeft = root;
            root->pRight = leftHead;
        }
    //}
}
static void helper01(BinaryTree **rightHead, BinaryTree **leftTail, BinaryTree *root)
{
    BinaryTree *rightTail=NULL, *leftHead=NULL;
    if(NULL == root)
    {
        *rightHead = NULL;
        *leftTail = NULL;
        return;
    }
    helper01(rightHead, &rightTail, root->pLeft);
    if(NULL == rightTail)
        *rightHead = root;
    else
    {
        rightTail->pRight = root;
        root->pLeft = rightTail;
    }
    helper01(&leftHead, leftTail, root->pRight);
    if(NULL == leftHead)
        *leftTail = root;
    else
    {
        leftHead->pLeft = root;
        root->pRight = leftHead;
    }
}
