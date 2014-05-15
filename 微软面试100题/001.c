#include <stddef.h>

#include "tree.h"

static void helper(BinaryTree **rightHead, BinaryTree **leftTail, BinaryTree *root);

BinaryTree *BinaryTreeToDoubleList(BinaryTree *root)
{
    BinaryTree *rightHead=NULL, *leftTail=NULL;
    helper(&rightHead, &leftTail, root);
    return rightHead;
}

static void helper(BinaryTree **rightHead, BinaryTree **leftTail, BinaryTree *root)
{
    BinaryTree *rightTail=NULL, *leftHead=NULL;
    if(NULL == root)
    {
        *rightHead = NULL;
        *leftTail = NULL;
        return;
    }
    helper(rightHead, &rightTail, root->pLeft);
    if(NULL == rightTail)
        *rightHead = root;
    else
    {
        rightTail->pRight = root;
        root->pLeft = rightTail;
    }
    helper(&leftHead, leftTail, root->pRight);
    if(NULL == leftHead)
        *leftTail = root;
    else
    {
        leftHead->pLeft = root;
        root->pRight = leftHead;
    }
}
