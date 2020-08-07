#define _CRT_SECURE_NO_WARNINGS 1

// 带头+双向+循环链表增删查改实现

#include<stdio.h>
#include<stdlib.h>

typedef int DataType;

// 结点类型
typedef struct ListNode
{
	DataType data;
	struct ListNode* next;
	struct ListNode* prev;
}ListNode;

// 表头
typedef struct ListHead {
	ListNode* head;
}ListHead;


// 接口
void ListCreate(ListHead* plist);

void ListDestory(ListHead* plist);

void ListPrint(ListHead* plist);

void ListPushBack(ListHead* plist, DataType data);

void ListPopBack(ListHead* plist);

void ListPushFront(ListHead* plist, DataType data);

void ListPopFront(ListHead* plist);

ListNode* ListFind(ListHead* plist, DataType data);

void ListInsert(ListNode* pos, DataType data);

void ListErase(ListNode* pos);


int main(void) {
	
	ListHead plist;

	ListCreate(&plist);

	ListPushBack(&plist, 1);
	ListPushBack(&plist, 2);

	ListPopBack(&plist);
	ListPopBack(&plist);
	//ListPopBack(&plist);

	ListPushFront(&plist, 1);
	ListPushFront(&plist, 2);

	ListPopFront(&plist);
	ListPopFront(&plist);
	//ListPopFront(&plist);

	ListPushFront(&plist, 1);
	ListInsert(ListFind(&plist, 1), 0);
	ListErase(ListFind(&plist, 1));

	ListPrint(&plist);
	
	ListDestory(&plist);

	return 0;
}

ListNode* CreateNode(DataType data) {

	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	
	if (node == NULL) {
		printf("malloc failed in %s\n", __func__);
		exit(EXIT_FAILURE);
	}

	node->data = data;
	node->next = node->prev = NULL;

	return node;
}


// 创建返回链表的头结点.
void ListCreate(ListHead* plist) {
	
	// 创建表头结点
	plist->head = CreateNode(-1);
	// 使表头结点循环
	plist->head->next = plist->head;
	plist->head->prev = plist->head;
}


// 双向链表尾插
void ListPushBack(ListHead* plist, DataType data) {

	//ListNode* head = plist->head; //链表头结点
	//ListNode* last = plist->head->prev; // 链表尾结点
	//ListNode* new_node = CreateNode(data);

	//new_node->next = head;
	//new_node->prev = last;

	//head->prev = new_node;
	//last->next = new_node;

	ListInsert(plist->head, data);
}


// 双向链表尾删
void ListPopBack(ListHead* plist) {

	//ListNode* remove_node = plist->head->prev;

	//// 空链表
	//if (remove_node == plist->head) {
	//	printf("Empty list exception in %s.\n", __func__);
	//	exit(EXIT_FAILURE);
	//}
	//	
	//ListNode* prev = remove_node->prev;

	//prev->next = plist->head; // 让倒数第二个结点指向头节点
	//plist->head->prev = prev; // 让头结点指向倒数第二个结点

	//free(remove_node);

	ListErase(plist->head->prev);
}


// 双向链表头插
void ListPushFront(ListHead* plist, DataType data) {

	//ListNode* head = plist->head->next; // 链表第一个结点
	//ListNode* new_node = CreateNode(data);

	//new_node->prev = plist->head;
	//new_node->next = head;

	//plist->head->next = new_node;
	//head->prev = new_node;

	ListInsert(plist->head->next, data);
}


// 双向链表头删
void ListPopFront(ListHead* plist) {
	
	//ListNode* remove_node = plist->head->next; // 删除第一个结点

	//if (remove_node == plist->head) {
	//	printf("Empty list exception in %s.\n", __func__);
	//	exit(EXIT_FAILURE);
	//}

	//ListNode* new_head = remove_node->next;

	//plist->head->next = new_head;
	//new_head->prev = plist->head;
	//
	//free(remove_node);

	ListErase(plist->head->next);
}


// 双向链表查找
ListNode* ListFind(ListHead* plist, DataType data) {

	ListNode* cur = plist->head->next;

	for (; cur != plist->head; cur = cur->next)
		if (cur->data == data)
			break;

	return cur;
}


// 双向链表在pos的前面进行插入
void ListInsert(ListNode* pos, DataType data) {

	if (pos == NULL) {
		printf("nullptr exception in %s.\n", __func__);
		exit(EXIT_FAILURE);
	}

	ListNode* new_node = CreateNode(data);
	ListNode* pos_prev = pos->prev;

	new_node->next = pos;
	new_node->prev = pos_prev;

	pos_prev->next = new_node;
	pos->prev = new_node;
}


// 双向链表删除pos位置的节点
void ListErase(ListNode* pos) {
	
	if (pos == NULL) {
		printf("nullptr exception in %s.\n", __func__);
		exit(EXIT_FAILURE);
	}

	// 空表不能删除
	if (pos->next == pos) {
		printf("Empty list exception in %s.\n", __func__);
		exit(EXIT_FAILURE);
	}

	pos->prev->next = pos->next;
	pos->next->prev = pos->prev;

	free(pos);
}


// 双向链表销毁
void ListDestory(ListHead* plist) {

	ListNode* cur = plist->head->next;
	ListNode* cur_next;

	for (; cur != plist->head; cur = cur_next) {
		cur_next = cur->next;
		free(cur);
	}

	free(plist->head);
	plist->head = NULL;
}


// 双向链表打印
void ListPrint(ListHead* plist) {

	ListNode* cur = plist->head->next;

	for (; cur != plist->head; cur = cur->next)
		printf("%d ", cur->data);
}
