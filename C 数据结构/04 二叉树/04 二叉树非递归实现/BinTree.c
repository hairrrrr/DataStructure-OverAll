#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include"BinTree.h"
#include"binTreeStack.h"
#include"binTreeQueue.h"


BinTree* BinaryTreeCreate(BTDataType* str, int* idx) {
	
	// str 应为前序遍历的输出
	// '#'表示 NULL
	// 比如树 
	//    1
	//  2   3
	//4
	// 应表示为 124##3##

	if (str[*idx] != '#') {
		BinTree* root = (BinTree*)malloc(sizeof(BinTree));
		root->Val = str[*idx];
		(*idx)++;
		root->Left = BinaryTreeCreate(str, idx);
		(*idx)++;
		root->Right = BinaryTreeCreate(str, idx);

		return root;
	}
	else
		return NULL;
}


// 二叉树销毁
// 因为我们想释放结点的同时将结点置为 NULL，避免野指针的情况
// 所以我们要修改堆上空间，应该传递二级指针
void BinaryTreeDestory(BinTree** root) {

	// 二级指针转化为一级指针
	BinTree* cur = *root;
	if (cur) {
		// 不能先释放根节点，应该显先释放叶节点，采用后序遍历
		
		BinaryTreeDestory(&cur->Left);
		BinaryTreeDestory(&cur->Right);
		free(cur);
		cur = NULL;
	}
}


// 二叉树节点个数
int BinaryTreeSize(BinTree* root) {
	
	if (root) {
		return BinaryTreeSize(root->Left) +
			BinaryTreeSize(root->Right) + 1;
	}
	else
		return 0;
}


// 非递归实现：
int BinaryTreeSize2(BinTree* root, int* num) {
	if (root) {
		(*num)++;
		BinaryTreeSize2(root->Left, num);
		BinaryTreeSize2(root->Right, num);
	}
}


// 二叉树叶子节点个数
int BinaryTreeLeafSize(BinTree* root) {
	
	// 非空树
	if (root) {
		// 左右子树为空
		if (!root->Left && !root->Right) {
			return 1;
		}

		return   BinaryTreeLeafSize(root->Left)
		+ BinaryTreeLeafSize(root->Right);
	}

	return 0;
}


// 二叉树第k层节点个数
int BinaryTreeLevelKSize(BinTree* root, int k) {

	// 二叉树的根节点为第一层
	// 二叉树的第三层对于第一层来说是第三层，对于第二层来说是第二层，对于第三层来说就是第一层
	// 因此，可以使用递归解决这个问题

	if (root && k >= 1) {
		if (k == 1)
			return 1;

		return BinaryTreeLevelKSize(root->Left, k - 1) +
			BinaryTreeLevelKSize(root->Right, k - 1);
	}

	return 0;
}


// 二叉树查找值为x的节点
BinTree* BinaryTreeFind(BinTree* root, BTDataType x) {

	if (root == NULL)
		return NULL;
	
	if (root->Val = x)
		return root;

	BinTree* T = BinaryTreeFind(root->Left, x);
	if (T)
		return T;//在左子树中找到
	return BinaryTreeFind(root->Right, x);//返回右子树的结果
}


// 二叉树前序非递归遍历 

void BinaryTreePrevOrderNoR(BinTree* root) {

	Stack* S = (Stack*)malloc(sizeof(Stack));
	stackCreate(S, 100);
	
	BinTree* cur = root;
	while ( cur || !stackIsEmpty(S) ) {
		
		while (cur) {
			// 前序遍历
			printf("%c", cur->Val);
			// 当前结点入栈
			stackPush(S, cur);
			cur = cur->Left;
		}
		// 获取栈顶元素
		cur = stackPop(S);

		// 访问右子树
		cur = cur->Right;
	}

}


// 二叉树前序递归遍历
// 借助栈实现
void BinaryTreePrevOrder(BinTree* root) {

	if (root) {
		printf("%c ", root->Val);
		BinaryTreePrevOrder(root->Left);
		BinaryTreePrevOrder(root->Right);
	}
}


// 二叉树中序非递归遍历
// 借助栈实现
void BinaryTreeInOrderNoR(BinTree* root) {
	
	Stack* S = (Stack*)malloc(sizeof(Stack));
	stackCreate(S, 100);

	BinTree* cur = root;
	while (cur || !stackIsEmpty(S)) {

		while (cur) {
			// 当前结点入栈
			stackPush(S, cur);
			cur = cur->Left;
		}
		// 获取栈顶元素
		cur = stackPop(S);
		
		// 中序遍历
		printf("%c ", cur->Val);

		// 访问右子树
		cur = cur->Right;
	}

}

// 二叉树中序遍历
void BinaryTreeInOrder(BinTree* root) {
	
	if (root) {
		BinaryTreePrevOrder(root->Left);
		printf("%c ", root->Val);
		BinaryTreePrevOrder(root->Right);
	}
}


// 二叉树后序非递归遍历
// 借助栈实现
void BinaryTreePostOrder(BinTree* root) {

	Stack* S = (Stack*)malloc(sizeof(Stack));
	stackCreate(S, 100);

	BinTree* cur = root;
	BinTree* prev_pop;

	while (cur || !stackIsEmpty(S)) {

		while (cur) {
			// 当前结点入栈
			stackPush(S, cur);
			cur = cur->Left;
		}
		// 获取栈顶元素
		cur = stackPop(S);

		// 左子树为空或左子树已经被抛出
		if (cur->Right == NULL || cur->Right == prev_pop) {
			// 后序遍历
			printf("%c ", cur->Val);
			prev_pop = cur; // 迭代
			cur = NULL; // 继续让下一个元素出栈（而非继续让右子树入栈）
		}
		// 左子树还未被遍历，将根结点继续压栈
		else {
			stackPush(S, cur);
			cur = cur->Right;
		}

		// 访问右子树
		cur = cur->Right;
	}

}

// 二叉树后序遍历
void BinaryTreePostOrder(BinTree* root) {
	if (root) {
		BinaryTreePrevOrder(root->Left);
		BinaryTreePrevOrder(root->Right);
		printf("%c ", root->Val);
	}
}



// 层序遍历
// 队列实现
void BinaryTreeLevelOrder(BinTree* root) {

	Queue* Q = createQueue();
	BinTree* T;
	
	// 先让根入队
	queuePush(Q, root);

	if (!queueIsEmpty(Q)) {
		
		T = queuePop(Q);
		printf("%c ", T->Val);

		// 左右子节点非空则入队
		if (T->Left)
			queuePush(Q, T->Left);
		if (T->Right)
			queuePush(Q, T->Right);
	}
}


// 判断二叉树是否是完全二叉树
// 通过层序遍历，如果是完全二叉树则空结点都在最后找到；如果不是，那么空结点和非空结点会夹杂在一起
bool BinaryTreeComplete(BinTree* root) {

	Queue* Q = createQueue();
	BinTree* T;

	if (root)
		queuePush(Q, root);

	while(!queueIsEmpty(Q)) {
		
		T = queuePop(Q);
		// 当前结点非空，将左右子节点入队
		if (T) {
			queuePush(Q, T->Left);
			queuePush(Q, T->Right);
		}
		// 当前结点为空，停止入队
		else
			break;
	}
	
	while (!queueIsEmpty(Q)) {
		T = queuePop(Q);
		
		// 出现非空结点，不是完全二叉树
		if (T)
			return false;
	}

	// 根节点为空或者队列剩余的元素都为空
	return true;
}
