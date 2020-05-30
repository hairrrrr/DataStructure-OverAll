#ifndef _BINTREE_H_
#define _BINTREE_H_

typedef char BTDataType;

typedef struct BinTree {
	BTDataType Val;
	struct BinTree* Left;
	struct BinTree* Right;
}BinTree;


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

#endif