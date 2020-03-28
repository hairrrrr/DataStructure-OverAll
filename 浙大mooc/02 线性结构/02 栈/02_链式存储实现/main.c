#define _CRT_SECURE_NO_WARNINGS 1

// 链式存储的核心就是 Push 和 Pop 操作应该从链表的那一端进行
// 无论是从简化程序方面还是 堆栈的“先入后出”规则方面考虑我们都应该选择从表头进行

#include<stdio.h>
#include<stdlib.h>

#define ERROR NULL;

typedef int ElementType;

typedef struct Node {
	ElementType Data;
	struct Node* Next;
}Node;

typedef Node* Stack;

int isEmpty(Stack S);
Stack CreatStack();
void Push(Stack S, ElementType item);
ElementType Pop(Stack S) {
	
	ElementType elem;

	if (isEmpty(S)) {
		printf("堆栈空！\n");
		return ERROR;
	}
	else {
		// 类似于删除头节点的操作
		Stack pop = S->Next;
		elem = pop->Data;
		S->Next = pop->Next;
		free(pop);
		return elem;
	}
}

int main(void) {

	return 0;
}

int isEmpty(Stack S) {
	// 是空表返回 1，不是返回 0
	return (S->Next == NULL);
}

Stack CreatStack() {

	Stack S = (Stack)malloc(sizeof(Node));
	S->Next = NULL;// 切记不要忘了这一步！
	return S;
}

void Push(Stack S, ElementType item) {
	
	//链表无序判断堆栈是否会满

	Stack new = (Stack)malloc(sizeof(Node));
	new->Next = S->Next;
	new->Data = item;
	S->Next = new;
}

