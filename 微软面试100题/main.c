#include <stdio.h>
#include <stdlib.h>

#include "tree.h"

extern BinaryTree *initTree(int arr[], int len);
extern void printPaths(BinaryTree *root, int sum);

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
    test004();
    return 0;
}
