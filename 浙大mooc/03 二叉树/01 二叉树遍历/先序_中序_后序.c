#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define MaxSize 100

typedef int ElementType;

typedef struct {
	ElementType data;
	BinTree* Left; // 左子树
	BinTree* Right; // 右子树
}BinTree;


typedef struct {
	BinTree** array;
	int top;
	int capacity;
}Stack;

Stack* stackCreate(int size) {

	Stack* stack = (Stack*)malloc(sizeof(Stack));
	stack->array = (BinTree**)malloc(sizeof(BinTree*) * size);
	stack->top = -1;
	stack->capacity = size;

	return stack;
}

void stackPush(Stack* S, BinTree* BT) {

	if (S->top < MaxSize) {
		S->array[++S->top] = BT;
	}
}

BinTree* stackPop(Stack* S) {

	if (!stackIsEmpty(S)) {
		return S->array[S->top--];
	}

	return NULL;
}

bool stackIsEmpty(Stack* S) {

	if (S->top + 1 == S->capacity)
		return true;

	return false;
}



void PreOrderTraversal(BinTree* BT) {

	BinTree* T = BT;
	Stack* S = stackCreate(MaxSize);

	while (T || !stackIsEmpty(S)) {
		while (T) {
			stackPush(S, T);
			printf("%d ", T->data);
			T = T->Left;
		}
		if (!stackIsEmpty(S)) {
			T = stackPop(S);
			T = T->Right;
		}
	}
}

void InOrderTraversal(BinTree* BT) {

	BinTree* T = BT;
	Stack* S = stackCreate(MaxSize);

	while (T || !stackIsEmpty(S)) {
		while (T) {
			stackPush(S, T);
			T = T->Left;
		}
		if (!stackIsEmpty(S)) {
			T = stackPop(S);
			printf("%d ", T->data);
			T = T->Right;
		}
	}
}

void PostOrderTraversal(BinTree* BT) {

	BinTree* T = BT, *prev_pop;
	Stack* S = stackCreate(MaxSize);

	while (T || !stackIsEmpty(S)) {
		while (T) {
			stackPush(S, T);
			T = T->Left;
		}
		if (!stackIsEmpty(S)) {
			T = stackPop(S);

			// 后序遍历应该在第三次遇到该结点时（左右子树都遍历完成）再输出该数据
			// 第二次遇到该结点不应该让其出栈
			// 判断是否是第三次的条件：左子树指针为空左子树等于上一个出栈的元素
			if (T->Right == NULL || T->Right == prev_pop) {
				printf("%d ", T->data);
				prev_pop = T;
				T = NULL;
			}
			else {
				stackPush(S, T);
				T = T->Right;
			}

		}
	}
}
