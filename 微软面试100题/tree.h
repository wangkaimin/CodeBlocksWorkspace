#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED

#define TREE_DEPTH 10
#define TREE_NODES 100

typedef int ElementType;


typedef struct tagBinaryTree
{
    ElementType e;
    struct tagBinaryTree *pLeft;
    struct tagBinaryTree *pRight;
} BinaryTree;

#endif // TREE_H_INCLUDED
