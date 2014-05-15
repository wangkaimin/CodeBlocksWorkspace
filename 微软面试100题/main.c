#include <stdio.h>
#include <stdlib.h>

#include "tree.h"

/* 001 */
extern BinaryTree *BinaryTreeToDoubleList(BinaryTree *root);
/* 003 */
extern int findMaxSubSum(int arr[], int start, int end);

extern BinaryTree *initTree(int arr[], int len);
extern void printPaths(BinaryTree *root, int sum);

static BinaryTree *myInitTree()
{
    BinaryTree *root;
    ElementType arr[TREE_NODES] = {7,5,11,4,6,2};
    int len = 6;
    root = initTree(arr, len);
    return root;
}

void test001()
{
    BinaryTree *root;
    root = BinaryTreeToDoubleList(myInitTree());
    temp = root;
    while(temp != NULL)
    {
        printf("%d\n",temp->e);
        temp = temp->pRight;
    }
}

void test003()
{
    int arr[6] = {-4,-6,-5,-2,-1,-3};
    printf("max=%d\n",findMaxSubSum(arr, 0, 6));
}

void test004()
{
    int sum = 18;
    printPaths(myInitTree(), sum);
}

int main()
{
    test001();
    return 0;
}
