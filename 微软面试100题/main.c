#include <stdio.h>
#include <stdlib.h>

#include "tree.h"

/* 003 */
extern int findMaxSubSum(int arr[], int start, int end);

extern BinaryTree *initTree(int arr[], int len);
extern void printPaths(BinaryTree *root, int sum);

void test003()
{
    int arr[6] = {-4,-6,-5,-2,-1,-3};
    printf("max=%d\n",findMaxSubSum(arr, 0, 6));
}

void test004()
{
    BinaryTree *root;
    int sum = 18;
    int len = 6;
    ElementType arr[TREE_NODES] = {7,5,11,4,6,2};
    root = initTree(arr, len);
    printPaths(root, sum);
}

int main()
{
    test003();
    return 0;
}
