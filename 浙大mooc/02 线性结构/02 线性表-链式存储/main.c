#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef struct List {
	int data;
	struct List* next;
}List;
typedef List* pList;

int Length(pList pL);
pList FindKth(int pst, pList pL);//按序查找
pList Find(int trg, pList pL);// 按值查找
pList Insert(int add_num, int pst, pList pL);// 插入
pList Delete(int pst, pList pL);
void Print(pList pL);// 打印
int main(void) {

	pList pL = (pList)malloc(sizeof(List));
	pList test;
	pL = NULL;//这一步一定要有，如果没有这一步是很可怕的。
	//实际上这个 pL 是不会被使用的，但是如果不写，当 pL 被访问时，pL->next 是不确定的。

	pL = Insert(3, 1, pL);
	pL = Insert(2, 1, pL);
	pL = Insert(1, 1, pL);
	Print(pL);
	if ((test = Find(1, pL)) != NULL) {
		printf("Find(1, pL) = %d\n", test->data);
	}
	pL = Delete(1, pL);
	Print(pL);
	if ((test = FindKth(1, pL)) != NULL) {
		printf("FindKth(1, pL) = %d\n", test->data);
	}

	pL = Delete(1, pL);
	Delete(1, pL);

	return 0;
}


int Length(pList pL) {

	int length = 0;
	pList p = pL;

	assert(pL != NULL);

	while (p) {
		p = p->next;
		length++;
	}

	return length;
}

pList FindKth(int pst, pList pL) {

	int i = 1;
	pList p = pL;

	assert(pL != NULL);

	while (i < pst && p != NULL) {
		i++;
		p = p->next;
	}

	if (i == pst) {
		return p;
	}
	else {
		printf("表中没有序号为 %d 元素\n", pst);
		return NULL;
	}

	////上面的 if else 语句如果写成这样：
	//if (p == NULL)
	//	return NULL;
	//else
	//	return p;
	////这时错误的。
	////如果输入的 pst = -1，这时 i > pst 跳出 while 循环，
	////但是 p！= NULL，然会的是 pL 也就是表头。

}

pList Find(int trg, pList pL) {

	pList p = pL;

	assert(pL != NULL);

	while ((p->data != trg) && (p != NULL)) {
		p = p->next;
	}
	if (p == NULL) {
		printf("表中没有数 %d\n", trg);
		return NULL;
	}

	return p;
}

pList Insert(int add_num, int pst, pList pL) {

	// pst 表示的是链表中第 pst 个节点
	// 如果 pst == 3，表示将节点插入链表的第 3 位，那我们就需要先找到前一个（pst - 1）节点，也就是第二个节点
	// 如果 pst == 1，表示将节点插入链表的第 1 位，但是这时候没有前一个节点了，这时候就需要特殊处理
	pList last, p;

	if (pst == 1) {
		p = (pList)malloc(sizeof(List));
		if (p != NULL) {
			p->data = add_num;
			p->next = pL;
			return p;
		}
		else {
			printf("插入失败！内存申请失败！\n");
			return NULL;
		}
	}

	last = FindKth(pst - 1, pL); // 寻找 pst 上一个节点

	if (last == NULL) {
		printf("插入失败！第 %d 个节点不存在\n", pst - 1);
		return NULL;
	}
	else {
		p = (pList)malloc(sizeof(List));
		if (p != NULL) {
			p->next = last->next;
			p->data = add_num;
			last->next = p;
			return pL;
		}
		else {
			printf("插入失败！内存申请失败！\n");
			return NULL;
		}
	}

}

pList Delete(int pst, pList pL) {

	pList last, Next;

	assert(pL != NULL);

	if (pst == 1) {
		Next = pL->next;
		free(pL);
		return Next;
	}

	last = FindKth(pst, pL);
	if (last == NULL) {
		printf("第 %d 个节点删除失败！第 %d 个节点不存在\n", pst, pst - 1);
		return NULL;
	}
	else if (last->next == NULL) {
		printf("第 %d 个节点删除失败！第 %d 个节点不存在\n", pst, pst);
		return NULL;
	}
	Next = last->next;
	last->next = Next->next;
	free(Next);

	return pL;
}

void Print(pList pL) {

	assert(pL != NULL);

	printf("打印链表：\n");
	pList p = pL;
	while (p != NULL) {
		printf("%d ", p->data);
		p = p->next;
	}
}
