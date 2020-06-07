#include"heap.h"

void test1()
{	
	printf("******************* Min Heap *******************\n");

	HPDataType array[] = { 100, 50, 30, 20, 25, 18, 10, 5, 15, 21, 23 };
	Heap hp;

	heapCreat(&hp, array, sizeof(array) / sizeof(array[0]), MINHEAP);
	heapPrint(&hp);

	heapPush(&hp, 1, MINHEAP);
	heapPrint(&hp);

	printf("%d\n", heapPop(&hp, MINHEAP));
	heapPrint(&hp);
}

void test2()
{
	printf("******************* Min Heap *******************\n");

	HPDataType array[] = { 100, 50, 30, 20, 25, 18, 10, 5, 15, 21, 23 };
	Heap hp;

	heapCreat(&hp, array, sizeof(array) / sizeof(array[0]), MAXHEAP);
	heapPrint(&hp);

	heapPush(&hp, 1, MAXHEAP);
	heapPrint(&hp);

	printf("%d\n", heapPop(&hp, MAXHEAP));
	heapPrint(&hp);
}

void test3()
{

}

int main(void)
{

	test1();
	test2();
	test3();
}
