#include <stdio.h>
#include <stdlib.h>

#include "tree.h"
#include "stack.h"

/* 001 */
//extern BinaryTree *BinaryTreeToDoubleList(BinaryTree *root);
/* 002 */

/* 003 */
extern int findMaxSubSum(int arr[], int start, int end);

/* 004 */
//extern BinaryTree *initTree(int arr[], int len);
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
    BinaryTree *root, *temp;
    root = BinaryTreeToDoubleList(myInitTree());
    temp = root;
    while(temp != NULL)
    {
        printf("%d\n",temp->e);
        temp = temp->pRight;
    }
}

void test002()
{
    MinStack *ms = NULL;
    int max = 50;
    int val = 0, i = 0;
    int arr[] = {2, 9, 1, 5, 4, -1};
    if(1 == init(&ms, max))
        return;
    for(i=0;i<6;i++)
    {
        push(ms, arr[i]);
        min(ms, &val);
        printf("min=%d\n", val);
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

void test005()
{
    int arr[] = {2, 9, 1, 5, 4, 3};
    int i = 0;
    for(i=0;i<5;i++)
    {
        printf("%d ", arr[i]);
    }
    quickSort(arr, 6);
    for(i=0;i<5;i++)
    {
        printf("%d ", arr[i]);
    }
    printf("%d\n", arr[i]);
    siftdown(arr, 1, 6);
    for(i=0;i<5;i++)
    {
        printf("%d ", arr[i]);
    }
    printf("%d\n", arr[i]);
    siftup(arr , 2, 6);
    for(i=0;i<5;i++)
    {
        printf("%d ", arr[i]);
    }
    printf("%d\n", arr[i]);
}

int main()
{
    test005();
    return 0;
}
