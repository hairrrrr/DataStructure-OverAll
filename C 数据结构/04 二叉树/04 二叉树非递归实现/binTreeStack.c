#define _CRT_SECURE_NO_WARNINGS 1

#include"binTreeStack.h"

Stack* stackCreate(int size) {

	Stack* stack = (Stack*)malloc(sizeof(Stack));
	stack->array = (BinTree**)malloc(sizeof(BinTree*) * size);
	stack->top = -1;
	stack->capacity = size;

	return stack;
}

void stackPush(Stack* S, BinTree* BT) {

	if (S->top < S->capacity) {
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
