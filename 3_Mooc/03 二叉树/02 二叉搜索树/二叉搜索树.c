#define _CRT_SECURE_NO_WARNINGS 1

#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>

//
//typedef int ElementType;
//
//typedef struct {
//	ElementType data;
//	BinTree* Left; // 左子树
//	BinTree* Right; // 右子树
//}BinTree;
//
//
//// 递归实现
////BinTree* Find(ElementType x, BinTree* BST) {
////
////	if (!BST)
////		return NULL;
////
////	if (x < BST->data)
////		return Find(x, BST->Left);
////
////	else if (x > BST->data)
////		return Find(x, BST->Right);
////
////	else
////		return BST;
////}
//
//
//// 循环实现
//BinTree* Find(ElementType x, BinTree* BST) {
//
//	while (BST) {
//
//		if (x < BST->data)
//			BST = BST->Left;
//		else if (x > BST->data)
//			BST = BST->Right;
//		else
//			return BST;
//	}
//
//	return NULL;
//}
//
//// 递归
//BinTree* findMax(BinTree* BST) {
//
//	if (!BST) return NULL;
//	else if (!BST->Right)
//		return BST;
//	else
//		findMax(BST->Right);
//}
//
////循环
//BinTree* FindMax(BinTree* BST) {
//
//	if (BST)
//		while (BST->Right)
//			BST = BST->Right;
//
//	return BST;
//}
//
//
//BinTree* insert(ElementType x, BinTree* BST) {
//
//	if (!BST) {
//		BST = (BinTree*)malloc(sizeof(BinTree));
//		BST->data = x;
//		BST->Left = BST->Right = NULL;
//	}
//	else {
//		if (x > BST->data)
//			BST->Right = insert(x, BST->Right);
//		else if (x < BST->data)
//			BST->Left = insert(x, BST->Left);
//	}
//
//	return BST;
//}
//
//BinTree* delete(ElementType x, BinTree* BST) {
//
//	BinTree* tmp;
//
//	if (x < BST->data)
//		BST->Left = delete(x, BST);
//	else if (x > BST->data)
//		BST->Right = delete(x, BST);
//	else {
//		// BST 左右子树都有
//		if (BST->Left && BST->Right) {
//			tmp = findMax(BST->Left);
//			BST->data = tmp->data;
//			delete(BST->data, BST->Left);
//		}
//		// BST 只有一个子树或者没有子树
//		else {
//			tmp = BST;
//			// 如果 BST 没有子树，一样会进入第一个 if，此时 BST 右子树为 NULL
//			if (!BST->Left)
//				BST = BST->Right;
//			else
//				BST = BST->Right;
//			free(tmp);
//		}
//	}
//
//	return BST;
//}


// 讨论  搜索树比较序列的判别
#include<limits.h>

int main(void) {

	int target, min = INT_MIN, max = INT_MAX, bound;

	printf("search: ");
	scanf("%d", &target);

	while (1) {
		printf("bound : ");
		scanf("%d", &bound);

		// 为了不让在给边界赋输入的值之前结束程序，我们将 max 和 min 分别赋予 int类型 的最大值和最小值
		if (bound > max || bound < min) {
			printf("illegal bound\n");
			exit(EXIT_FAILURE);
		}

		bound > target ? (max = bound) : (min = bound);
		
	}

	return 0;
}
