#define _CRT_SECURE_NO_WARNINGS 1

//问题描述：请用一个数组实现两个堆栈，要求最大的利用数组空间，使得数组只要有空间入栈操作就可以成功。

//思路：两个堆栈分别从数组两端开始向数组中间生长，当两个堆栈的栈顶对应的数组下标之差为 1 时，表示两个堆栈栈顶相遇，堆栈满。

#include<stdio.h>

#define MAXSIZE 100
#define ERROR NULL;

typedef int ElementType;

typedef struct TNode {
	ElementType Data[MAXSIZE];
	int Top1; // 栈1 的栈顶数组元素的下表，空栈时 Top == -1
	int Top2; // 栈2 空栈时 Top == MAXSIZE  
}TNode;

typedef struct TNode* TStack;

void Push(TStack PtrS, ElementType item, int Tag);// 压栈
ElementType Pop(TStack PtrS);// 出栈

int main(void) {
	
	return 0;
}

void Push(TStack PtrS, ElementType item, int Tag) {

	// 判断栈是否满
	if (PtrS->Top2 - PtrS->Top1 == 1) {
		printf("堆栈满\n");
		return;
	}
	// Tag == 1 表示存放在 栈1 
	if (Tag == 1) {
		PtrS->Data[++(PtrS->Top1)] = item;
	}
	else {
		PtrS->Data[--(PtrS->Top2)] = item;
	}
}

ElementType Pop(TStack PtrS, int Tag) {
	
	if (Tag == 1) {
		if (PtrS->Top1 == -1) {
			printf("堆栈空!");
			return ERROR;
		}
		else {
			return PtrS->Data[(PtrS->Top1)--];
		}
	}
	else {
		if (PtrS->Top1 == MAXSIZE) {
			printf("堆栈空!");
			return ERROR;
		}
		else {
			return PtrS->Data[(PtrS->Top1)++];
		}
	}
}

