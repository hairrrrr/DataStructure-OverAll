#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

#define MAXSIZE 100
#define ERROR NULL;

typedef int ElementType;

typedef struct SNode {
	ElementType Data[MAXSIZE];
	int Top; // 当前栈存放的数组的最大下标
}SNode;

typedef struct SNode* Stack;

void Push(Stack PtrS, ElementType item);// 压栈
ElementType Pop(Stack PtrS);// 出栈

int main(void) {

	

	return 0;
}

void Push(Stack PtrS, ElementType item) {

	// 满的堆栈 Top == MAXSIZE - 1
	// 判断栈是否满
	if (PtrS->Top == MAXSIZE - 1) {
		printf("堆栈满\n");
		return;
	}
	else {
		PtrS->Data[++(PtrS->Top)] = item;
		return;
	}
}

ElementType Pop(Stack PtrS) {
	
	// 空的的堆栈 Top == -1
	// 出栈需要判断 堆栈是否为空
	if (PtrS->Top == - 1) {
		printf("堆栈空\n");
		return ERROR;// ERROR 是 ElementType 的特殊值，标志错误
	}
	else {
		return PtrS->Data[(PtrS->Top)--];
	}
}

