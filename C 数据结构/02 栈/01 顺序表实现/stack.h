#ifndef _STACK_H_
#define _STACK_H_

#include<stdbool.h>

typedef int DataType;

typedef struct Stack
{
	DataType* array;
	size_t size;
	size_t capacity;
}Stack;

void stackInit(Stack* s, size_t n);

void stackPush(Stack* s, DataType data);

DataType stackPop(Stack* s);

size_t stackSize(Stack* s);

bool stackIsEmpty(Stack* s);

bool stackIsFull(Stack* s);

void stackDestory(Stack* s);

#endif 