#include"heap.h"

int main(void)
{
	HPDataType array[] = { 100, 50, 30, 20, 25, 18, 10, 5, 15, 21, 23 };
	Heap hp;

	heapCreat(&hp, array, sizeof(array) / sizeof(array[0]));
	heapPrint(&hp);

	insertHeap(&hp, 1);
	heapPrint(&hp);
}
