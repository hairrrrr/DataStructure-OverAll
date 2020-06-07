#include"heap.h"

void heapCreat(Heap* hp, HPDataType* array, int size)
{
	hp->_array = (HPDataType*)malloc(sizeof(HPDataType) * size);
	memcpy(hp->_array, array, sizeof(HPDataType) * size);
	hp->_size = size;
	hp->_capacity = MAX_HEAP;

	// 从第一个非叶子结点开始调整
	for (int parent = (size - 2) / 2; parent >= 0; parent--)
	{
		shiftDown(hp->_array, hp->_size, parent);
	}
}

void insertHeap(Heap* hp, HPDataType data)
{
	if (hp->_size == hp->_capacity)
	{
		printf("Heap is full\n");
		return;
	}

	hp->_array[hp->_size++] = data;

	shiftUp(hp->_array, hp->_size - 1);
}


// 建堆时采用小堆的向下调整
// parent: 起始调整的位置
void shiftDown(HPDataType* array, int size, int parent)
{
	//左孩子位置
	int child = 2 * parent + 1;

	while (child < size)
	{
		//从左右孩子孩子中选一个最小
		if (child + 1 < size && array[child + 1] < array[child])
			child++;
		
		//和父节点比较
		if (array[child] < array[parent])
		{
			Swap(array, child, parent);
			parent = child;
			child = 2 * parent + 1;
		}
		else
			break;
	}
}

// 插入：小堆向上调整
// child: 插入元素的位置
void shiftUp(HPDataType* array, int child)
{
	int parent = (child - 1) / 2;

	while (child > 0)
	{
		if (array[child] < array[parent])
		{
			Swap(array, child, parent);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
			break;
	}
}

void Swap(HPDataType* array, int idx1, int idx2)
{
	HPDataType tmp = array[idx1];
	array[idx1] = array[idx2];
	array[idx2] = tmp;
}

void heapPrint(Heap* hp)
{
	for (int i = 0; i < hp->_size; i++)
	{
		printf("%d ", hp->_array[i]);
	}

	printf("\n");
}