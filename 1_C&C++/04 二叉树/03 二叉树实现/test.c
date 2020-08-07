#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include "BinTree.h"
#define ARR_TREE 20


int main(void) {
	int idx = 0;
	BTDataType str[ARR_TREE];

	scanf("%s", str);

	BinTree* T = BinaryTreeCreate(str, &idx);

	printf("%d\n", BinaryTreeSize(T));
	printf("%d\n", BinaryTreeLeafSize(T));
	printf("%d\n", BinaryTreeLevelKSize(T, 2));

	return 0;
}
