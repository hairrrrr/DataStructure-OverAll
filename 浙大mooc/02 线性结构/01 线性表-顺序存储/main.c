#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 200

typedef struct List {
	
	int data[MAXSIZE];
	int last;//最后一个元素的下标
}List;

typedef List* pList;

pList MakeEmpty();//初始化
void Input(pList pL);// 输入元素
int Find(int trg, pList pL);//查找第一次出现的位置
void Insert(int pst, int add_num, pList pL);//插入
void Delete(int pst, pList pL);//删除
int FindKth(int pst, pList pL);//根据位序 pst 查找元素
int Length(pList pL);// 表长
void Print(pList pL);// 打印表

int main(void) {

	pList pL;
	int index;

	if ((pL = MakeEmpty()) != NULL) {
		Input(pL);
		index = Find(3, pL);
		if(index != -1)
			printf("Find(3, pL) = %d\n", pL->data[index]);
		index = Find(0, pL);
		if (index != -1)
			printf("Find(0, pL) = %d\n", pL->data[index]);
		Insert(1, 0, pL);
		Print(pL);
		Delete(4, pL);
		Print(pL);
		index = FindKth(2, pL);
		if (index != -1)
			printf("FindKth(2, pL) = %d\n", pL->data[index]);
		Print(pL);
		printf("Length is %d\n", Length(pL));
	}

	return 0;
}

pList MakeEmpty() {
	pList pL;
	pL = (pList)malloc(sizeof(List));
	//不要忘记 malloc 可能失败的情况
	if (pL) 
		pL->last = -1;
	else {
		printf("创建表失败\n");
		return NULL;
	}
	return pL;
}

void Input(pList pL) {

	int choice;
	int input;

	if (pL->last != -1) {
		printf("此表已经含有数据，是否清零重新输入？输入 1 继续，输入其他退出\n");
		scanf("%d", &choice);
		if (choice != 1)
			return;
	}
	printf("开始读入数据，输入-1退出\n");
	do {
		scanf("%d", &input);
		if (input != -1) {
			pL->last++;
			pL->data[pL->last] = input;
		}
	} while (input != -1);
}

int Find(int trg, pList pL) {
	int i = 0;
	while (pL->data[i] != trg && i <= pL->last)
		i++;
	//退出循环有两种可能
	if (i > pL->last) {
		printf("没有找到 %d\n", trg);
		return -1;//数组遍历完没有找到返回 -1
	}
	else
		return i;//找到 target 返回下标
}

void Insert(int pst, int add_num, pList pL) {

	int i;

	if (pL->last == MAXSIZE - 1) {
		printf("表满\n");
		return;
	}
	// pst 指的不是数组下标。比如 a[3] = {1,2}
	//我想将 0 插入到 第1位上（数字1所在位置），那么输入的 pst 应该是 1 ，而不是 0
	//我们要做的操作是将数组从要插入的位置开始，将后面的数组元素依次（从最后一个元素开始）向后移动一位
	//开始的位置对应的数组下标就是 pst - 1。pL->last + 1 代表数组最后一个元素实际的位置
	//last + 2 就代表最后一个数组元素的后一位，也就是插在数组最后面 

	if (pst < 1 || pst > pL->last + 2) {
		printf("位置不合法\n");
		return;
	}

	for (i = pL->last; i >= pst - 1; i--) {
		pL->data[i + 1] = pL->data[i];
	}
	pL->data[pst - 1] = add_num;
	pL->last++;
}

void Delete(int pst, pList pL) {

	int i;

	if (pL->last == -1) {
		printf("这已经是一个空表了\n");
		return;
	}

	if (pst < 1 || pst > pL->last + 1) {
		printf("位置不合法\n");
		return;
	}
	// 如果表内只有一个元素
	if (pL->last == 0) {
		pL->last = -1;
	}

	for (i = pst; i <= pL->last; i++)
		pL->data[i - 1] = pL->data[i];

	pL->last--;
}

int FindKth(int pst, pList pL) {

	if (pst < 1 || pst > pL->last + 1) {
		printf("不合法的位序\n");
		return -1;
	}
	return pL->data[pst - 1];
}

int Length(pList pL) {

	return  pL->last + 1;
}

void Print(pList pL) {

	int i;
	printf("打印数据：\n");
	for (i = 0; i <= pL->last; i++) {
		printf("%d ", pL->data[i]);
	}
	printf("\n");
}




