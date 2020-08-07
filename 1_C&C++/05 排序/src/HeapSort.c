#include"sort.h"

/************************************************************************
*	heapSort:
*		时间复杂度：O(nlogn)
*		空间复杂度：O(1)
*		稳定性：不稳定  --> 调整的过程中相对位置可能会发生变化
*		数据敏感：不敏感
*************************************************************************/

// 建立大堆
void shiftDown(int* array, int size, int parent)
{	
	int child = parent * 2 + 1;
	while (child < size)
	{
		if (child + 1 < size && array[child + 1] > array[child])
			child++;
		
		if (array[child] > array[parent])
		{
			swap(array, child, parent);
			parent = child;
			child = parent * 2 + 1;
		}
		else
			break;
			
	}
}

void heapSort(int* array, int size)
{
	for (int i = (size - 2) / 2; i >= 0; i--)
	{
		shiftDown(array, size, i);
	}

	// 循环 size - 1 次
	while (size > 1)
	{
		swap(array, 0, size - 1);
		size--;
		shiftDown(array, size, 0);
	}
}