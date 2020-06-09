#define _CRT_SECURE_NO_WARNINGS 1

#include"queue.h"

#include<stdlib.h>
#include<stdio.h>


int main(void) {

	Queue q;

	queueInit(&q);

	queuePush(&q, 1);
	queuePush(&q, 2);
	
	printf("%d\n", queuePop(&q));
	printf("%d\n", queuePop(&q));

	return 0;
}

void queueInit(Queue* q) {

	// 初始化空队列
	q->front = q->rear = NULL;
	q->size = 0;
}


Node* creatNode(DataType data) {

	Node* new_node = (Node*)malloc(sizeof(Node));

	if (new_node == NULL) {
		printf("malloc failed in %s\n", __func__);
		exit(EXIT_FAILURE);
	}

	new_node->data = data;
	new_node->next = NULL;

	return new_node;
}


void queuePush(Queue* q, DataType data) {
	
	Node* new_node = creatNode(data);

	if (queueIsEmpty(q) == true) {
		q->front = q->rear = new_node;
	}
	else {
		q->rear->next = new_node;
		q->rear = new_node;
	}
	q->size++;
}


DataType queuePop(Queue* q) {

	DataType ret;
	Node* ele_pop;

	if (queueIsEmpty(q) == true) {
		printf("pop failed in %s, the queue is empty\n", __func__);
		exit(EXIT_FAILURE);
	}

	ele_pop = q->front;
	ret = ele_pop->data;
	q->front = ele_pop->next;
	free(ele_pop);

	if (queueIsEmpty(q) == true) {
		q->rear = NULL;
	}

	q->size--;

	return ret;
}


bool queueIsEmpty(Queue* q) {

	if (q->front == NULL)
		return true;
	return false;
}


void queueDestory(Queue* q) {

	Node* cur = q->front;

	for (; cur != NULL; cur = q->front) {
		q->front = cur->next;
		free(cur);
	}

	q->front = q->rear = NULL;
	q->size == 0;
}
