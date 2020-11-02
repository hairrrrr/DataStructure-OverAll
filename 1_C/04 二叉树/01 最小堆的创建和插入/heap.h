#ifndef _HEAP_H_
#define _HEAP_H_

#include<stdlib.h>
#include <memory.h>
#include<stdio.h>

#define MAX_HEAP 100

typedef int HPDataType;

typedef struct Heap
{
	HPDataType* _array;
	int _size;
	int _capacity;
}Heap;


void heapCreat(Heap* hp, HPDataType* array, int size);

void insertHeap(Heap* hp, HPDataType data);

void shiftDown(HPDataType* array, int size, int parent);

void shiftUp(HPDataType* array, int child);

void Swap(HPDataType* array, int idx1, int idx2);

void heapPrint(Heap* hp);

#endif 