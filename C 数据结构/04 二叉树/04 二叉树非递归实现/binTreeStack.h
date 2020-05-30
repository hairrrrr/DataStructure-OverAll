#ifndef _BINTREE_STACK_
#define _BINTREE_STACK_

#include"BinTree.h"
#include<stdbool.h>
#include<stdlib.h>

typedef struct {
	BinTree** array;
	int top;
	int capacity;
}Stack;

Stack* stackCreate(int size);
void stackPush(Stack* S, BinTree* BT);
BinTree* stackPop(Stack* S);
bool stackIsEmpty(Stack* S);

#endif 