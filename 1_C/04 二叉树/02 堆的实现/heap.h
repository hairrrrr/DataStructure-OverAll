/************************************************************************************
*	heap.h：
*		主要包含堆的类型定义，一些宏，和四个接口函数
*		（如果你想进一步封装，可以使用不完全类型，将堆的类型定义应该放在，heap.c 中）
************************************************************************************/

#ifndef _HEAP_H_
#define _HEAP_H_

#include<stdlib.h>
#include <memory.h>
#include<stdio.h>

#define MAX_HEAP 100 // 堆的最大容量
#define MINHEAP 0 // 最小堆的标记
#define MAXHEAP 1 // 最大堆的标记


typedef int HPDataType;

typedef struct Heap
{
	HPDataType* _array;
	int _size;
	int _capacity;
}Heap;



/******************** 接口函数 *******************/

void heapCreat(Heap* hp, HPDataType* array, int size, int flg);

void heapPush(Heap* hp, HPDataType data, int flg);

HPDataType heapPop(Heap* hp, int flg);

void heapPrint(Heap* hp);


#endif 