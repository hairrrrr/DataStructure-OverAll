#ifndef _BINTREE_H_
#define _BINTREE_H_

#include<stdbool.h>

typedef char BTDataType;

typedef struct BinTree{
	BTDataType Val;
	struct BinTree* Left;
	struct BinTree* Right;
}BinTree;

/******************* 二叉树实现 ************************/

BinTree* BinaryTreeCreate(BTDataType* str, int* idx);

// 二叉树销毁
void BinaryTreeDestory(BinTree** root);

// 二叉树节点个数
int BinaryTreeSize(BinTree* root);

void BianryTreeSize2(BinTree* root, int* num);

// 二叉树叶子节点个数
int BinaryTreeLeafSize(BinTree* root);

// 二叉树第k层节点个数
int BinaryTreeLevelKSize(BinTree* root, int k);

// 二叉树查找值为x的节点
BinTree* BinaryTreeFind(BinTree* root, BTDataType x);

/******************* 二叉树遍历 ************************/

// 二叉树前序非递归遍历
void BinaryTreePrevOrderNoR(BinTree* root);

// 二叉树前序遍历
void BinaryTreePrevOrder(BinTree* root);



// 二叉树中序非递归遍历
void BinaryTreeInOrderNoR(BinTree* root);

// 二叉树中序遍历
void BinaryTreeInOrder(BinTree* root);



// 二叉树后序非递归遍历
void BinaryTreePostOrderNoR(BinTree* root);

// 二叉树后序遍历
void BinaryTreePostOrder(BinTree* root);


// 层序遍历
void BinaryTreeLevelOrder(BinTree* root);


// 判断二叉树是否是完全二叉树
bool BinaryTreeComplete(BinTree* root);

#endif 

