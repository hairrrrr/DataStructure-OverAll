#define _CRT_SECURE_NO_WARNINGS 1

//顺序表实现栈

#include"stack.h"
#include <stdlib.h>
#include <stdio.h>


void stackInit(Stack* s, size_t n) {

	s->array = (DataType*)malloc(sizeof(DataType) * n);

	if (s->array == NULL) {
		printf("malloc failed in %s\n", __func__);
		exit(EXIT_FAILURE);
	}

	s->size = 0;
	s->capacity = n;
}

void stackPush(Stack* s, DataType data) {
	
	//if (stackIsFull(s) == true) {
	//	printf("push failed in %s, stack is full\n", __func__);
	//	exit(EXIT_FAILURE);
	//}

	// 提供错误消息是可行的，但是如果提供了解决方法可能会让用户体验更好，我们可以在栈满的时候提供扩容
	if (stackIsFull(s) == true) {
		s->capacity *= 2;
		s->array = (DataType*)realloc(s->array, s->capacity * sizeof(DataType));
	}

	s->array[s->size++] = data;
}

DataType stackPop(Stack* s) {

	if (stackIsEmpty(s) == true) {
		printf("pop failed in %s, stack is empty\n", __func__);
		exit(EXIT_FAILURE);
	}

	return s->array[--s->size];
}

size_t stackSize(Stack* s) {

	return s->size;
}

bool stackIsEmpty(Stack* s) {
	if (s->size == 0)
		return true;
	return false;
}

bool stackIsFull(Stack* s) {
	if (s->size == s->size)
		return true;
	return false;
}

void stackDestory(Stack* s) {

	free(s->array);
	s->array = NULL;
	s->capacity = s->size = 0;
}
