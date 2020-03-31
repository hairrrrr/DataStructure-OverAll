#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>

typedef int Type;

typedef struct Node
{
	struct Node* _next;
	Type _data;
}Node;

//实现不带头单向非循环链表
typedef struct SingleList
{
	Node* _head; // head: 表示链表真正的头结点，即第一个有效的数据的位置
}SingleList;


void singleListInit(SingleList* sl); 

Node* creatNode(Type data); 

void singleListPushBack(SingleList* sl, Type data);

void singleListPopBack(SingleList* sl);

void singleListPushFront(SingleList* sl, Type data);

void singleListPopFront(SingleList* sl);

void singleListInsertAfter(Node* pos, Type data);

void singleListEraseAfter(Node* pos);

Node* find(SingleList* sl, Type data);

void singleListPrint(SingleList* sl);

void singleListDestroy(SingleList* sl);


int main(void) {
	
	SingleList s;
	SingleList* sl = &s;

	singleListInit(sl);

	singleListPushBack(sl, 1);
	
	// 1
	
	singleListPushFront(sl, 0);
	
	// 0 1
	
	singleListPopFront(sl);

	// 1

	singleListPopBack(sl);

	// 

	singleListPushBack(sl, 1);
	singleListPushBack(sl, 3);
	singleListPushBack(sl, 5);
	singleListPushBack(sl, 5);

	singleListInsertAfter(find(sl, 1), 2);
	singleListInsertAfter(find(sl, 3), 4);

	singleListEraseAfter(find(sl, 5));

	// 1 2 3 4 5

	singleListDestroy(sl);

	//
	
	singleListPrint(sl);

	return 0;
}



void singleListInit(SingleList* sl) {
	
	sl->_head = NULL;
}


Node* creatNode(Type data) {

	Node* newNode = (Node*)malloc(sizeof(Node));
	
	if (newNode != NULL) {
		newNode->_data = data;
		newNode->_next = NULL;

		return newNode;
	}
	else {
		return NULL;
	}
}

void singleListPrint(SingleList* sl) {
	
	if (sl->_head == NULL) {
		return;
	}

	Node* cur = sl->_head;

	while (cur != NULL) {
		printf("%d ", cur->_data);
		cur = cur->_next;
	}
	printf("\n");
}

void singleListPushBack(SingleList* sl, Type data) {
	
	Node* newNode = creatNode(data);

	if (sl->_head == NULL) {
		sl->_head = newNode;
	}
	else {

		Node* cur = sl->_head;

		while (cur->_next != NULL) {
			cur = cur->_next;
		}

		cur->_next = newNode;
	}
}

void singleListPopBack(SingleList* sl) {
	
	if (sl->_head == NULL) {
		return;
	}

	Node* cur = sl->_head;
	
	// 只有一个结点
	if (cur->_next == NULL) {
		free(cur);
		sl->_head = NULL;
		return;
	}

	while (cur->_next != NULL && cur->_next->_next != NULL) {
		cur = cur->_next;
	}
	
	free(cur->_next);

	cur->_next = NULL;
	
}

void singleListPushFront(SingleList* sl, Type data) {

	Node* newNode = creatNode(data);

	if (sl->_head == NULL) {
		sl->_head = newNode;
	}

	Node* first = sl->_head;

	newNode->_next = first;
	sl->_head = newNode;
}

void singleListPopFront(SingleList* sl) {

	if (sl->_head == NULL) {
		printf("PopFront 空指针异常!");
		return;
	}

	Node* del = sl->_head;

	sl->_head = del->_next;

	free(del);

}


void singleListInsertAfter(Node* pos, Type data) {

	Node* newNode = creatNode(0);

	newNode->_data = data;

	newNode->_next = pos->_next;

	pos->_next = newNode;
}


void singleListEraseAfter(Node* pos) {
	
	if (pos == NULL || pos->_next == NULL) {
		printf("空指针异常！");
		return;
	}

	Node* erase = pos->_next;

	pos->_next = erase->_next;

	free(erase);
}


Node* find(SingleList* sl, Type data) {

	if (sl->_head == NULL) {
		return NULL;
	}

	Node* cur = sl->_head;

	/*while (cur != NULL) {
		if (cur->_data == data) {
			return cur;
		}
		cur = cur->_next;
	}*/

	while (cur != NULL && cur->_data != data) {
		cur = cur->_next;
	}

	return cur;
}



void singleListDestroy(SingleList* sl) {

	if (sl->_head == NULL) {
		return;
	}

	Node* cur = sl->_head;

	while (cur != NULL) {
		Node* Next = cur->_next;
		free(cur);
		cur = Next;
	}

	sl->_head = NULL;
}

