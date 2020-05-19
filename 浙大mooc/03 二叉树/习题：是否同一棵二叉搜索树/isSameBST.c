#define _CRT_SECURE_NO_WARNINGS 1

//### 输入样例
//:
//4 2
//3 1 4 2
//3 4 1 2
//3 2 4 1
//2 1
//2 1
//1 2 0
//### 输出样例
//	:
//Yes
//No
//No


#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>


typedef int ElementType;

typedef struct {
	ElementType data;
	BSTree* Left;
	BSTree* Right;
	bool isVisit; // 判断结点是否出现
}BSTree;

BSTree* makeTree(int N);
BSTree* newNode(ElementType val);
BSTree* insertNode(BSTree* T, ElementType val);
bool isSameTree(BSTree* T, int N);
bool checkNode(BSTree* T, ElementType val);
void resetTree(BSTree* T);
void freeTree(BSTree* T);

int main(void) {

	int N, L, i;
	BSTree* T;

	scanf("%d", &N);

	while (N) {
		scanf("%d", &L);
		T = makeTree(N);
		for (i = 0; i < L; i++) {
			if (isSameTree(T, N)) printf("Yes\n");
			else printf("No");
			resetTree(T); // 清除 T 中的记录 isVisit
		}
		freeTree(T);
		scanf("%d", &N); // 如果 N 为 0 退出
	}

	return 0;
}

// create BST
BSTree* makeTree(int N) {

	ElementType val;
	int i;

	scanf("%d", &val);
	BSTree* T = newNode(val);

	for (i = 1; i < N; i++) {
		scanf("%d", &val);
		T = insertNode(T, val);
	}
	
	return T;
}

// create node
BSTree* newNode(ElementType val) {

	BSTree* new_node = (BSTree*)malloc(sizeof(BSTree));
	
	new_node->data = val;
	new_node->isVisit = false;
	new_node->Left = new_node->Right = NULL;
}


BSTree* insertNode(BSTree* T, ElementType val) {

	if (!T)
		T = newNode(val);

	else {
		if (val > T->data)
			T->Right = insertNode(T->Right, val);
		else
			T->Left = insertNode(T->Left, val);
	}
	
	return T;
}


bool isSameTree(BSTree* T, int N) {

	int i;
	ElementType val;
	bool flg = true; // 记录此次输入是否与原始的树相同

	scanf("%d", &val);

	// 根不一样肯定不是相同树
	if (T->data != val) 
		return false;
	
	for (i = 1; i < N; i++) {
		scanf("%d", &val);
		// 当 flg 为真且当前输入的结点在树中位置不符时，flg 置为 false
		// 此时我们不应该 break，应该继续读入到此行输入结束
		if (flg && !checkNode(T, val))
			flg = false;
	}


	(flg == true) ? true : false;
}


bool checkNode(BSTree* T, ElementType val) {
	
	if (T->isVisit) {
		if (val < T->data)
			return checkNode(T->Left, val);
		else if (val > T->data)
			return checkNode(T->Right, val);
		// 结点值重复，不是相同树
		else
			return false;
	}
	// 该结点没有被访问
	else {
		if (val == T->data) {
			T->isVisit = true;
			return true;
		}
		// 目标值与树中不同，且该结点没有被访问
		else
			return false;
	}
}

void resetTree(BSTree* T);
void freeTree(BSTree* T);


