#ifndef _SORT_H_
#define _SORT_H_

void swap(int* array, int idx1, int idx2); // 交换数组中两个下表的元素

void insertSort(int* array, int size);

void shellSort(int* array, int size);

void selectSort(int* array, int size);
void selectSortOp(int* array, int size);

void bubbleSort(int* array, int size);

void shiftDown(int* array, int size, int parent);
void heapSort(int* array, int size);

void quickSort(int* array, int size, int parent);
void stackQuickSort(int* array, int size);
void queueQuickSort(int* array, int size);

void mergeSort(int* array, int size);

void countSort(int* array, int size);

#endif 