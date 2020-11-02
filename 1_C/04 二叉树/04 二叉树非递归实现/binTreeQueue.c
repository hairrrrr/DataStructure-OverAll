#define _CRT_SECURE_NO_WARNINGS 1

#include"binTreeQueue.h"


Queue* createQueue() {

	Queue* queue = (Queue*)malloc(sizeof(Queue));

	queue->front = queue->rear = NULL;
	queue->size = 0;

	return queue;
}

Node* createNode(BinTree* BT) {

	Node* new_node = (Node*)malloc(sizeof(Node));
	new_node->node = BT;
	new_node->next = NULL;

	return new_node;
}

void queuePush(Queue* Q, BinTree* BT) {

	Node* new_node = createNode(BT);

	if (queueIsEmpty(Q)) {
		Q->front = Q->rear = new_node;
	}
	else {
		Q->rear->next = new_node;
		Q->rear = new_node;
	}

	Q->size++;
}

BinTree* queuePop(Queue* Q) {

	if (!queueIsEmpty(Q)) {
		Node* node_pop = Q->front;
		BinTree* ret = node_pop->node;

		Q->front = Q->front->next;
		free(node_pop);

		if (Q->front == NULL)
			Q->rear = NULL;

		Q->size--;

		return ret;
	}

	return NULL;
}

bool queueIsEmpty(Queue* Q) {

	return Q->size == 0;
}
