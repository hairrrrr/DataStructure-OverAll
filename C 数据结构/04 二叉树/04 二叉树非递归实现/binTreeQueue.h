#ifndef _BINTREE_QUEUE_
#define _BINTREE_QUEUE_

#include<stdbool.h>
#include<stdlib.h>
#include"BinTree.h"


typedef struct {
	BinTree* node;
	BinTree* next;
}Node;

typedef struct Queue
{
	Node* front;
	Node* rear;
	int size;
}Queue;


Queue* createQueue();
Node* createNode(BinTree* BT);
void queuePush(Queue* Q, BinTree* BT);
BinTree* queuePop(Queue* Q);
bool queueIsEmpty(Queue* Q);

#endif