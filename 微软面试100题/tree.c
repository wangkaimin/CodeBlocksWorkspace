#include "tree.h"
#include <assert.h>
#include <stdio.h>

static BinaryTree *buildTree(BinaryTree *root, ElementType e)
{
    BinaryTree *temp = root;
    BinaryTree *newNode;

    assert(NULL != temp);

    newNode = (BinaryTree *)malloc(sizeof(BinaryTree));
    if(NULL != newNode)
    {
        newNode->e = e;
        newNode->pLeft = NULL;
        newNode->pRight = NULL;
    }

    while(1)
    {
        if(e < temp->e)
        {
            if(NULL != temp->pLeft)
                temp = temp->pLeft;
            else
            {
                temp->pLeft = newNode;
                break;
            }
        }
        else
        {
            if(NULL != temp->pRight)
                temp = temp->pRight;
            else
            {
                temp->pRight = newNode;
                break;
            }
        }
    }

    return root;
}

BinaryTree *initTree(ElementType arr[], int len)
{
    int i = 0;
    BinaryTree *root = (BinaryTree *)malloc(sizeof(BinaryTree));
    if(NULL != root)
    {
        root->e = arr[i];
        root->pLeft = NULL;
        root->pRight = NULL;
    }
    else
        return NULL;

    for(i=1;i<len;i++)
    {
        root = buildTree(root, arr[i]);
    }

    return root;
}
