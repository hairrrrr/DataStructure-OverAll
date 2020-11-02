/**********************************************************************************************
*	heap.c：
*			堆的建立，插入，删除都要牵扯对堆的重构，而最大堆和最小堆的重构方式是不同的。
*			如果我们为最大堆和最小堆都设置同样的接口，会发现，其实很多代码都是重复的。
*			这不符合我们软件设计的思想——重用。
*			
*			因此，经过比较，我发现最大堆和最小堆的区别只是在比较两个节点的值
*			（儿子节点和父节点，左儿子和右儿子），所以我声明了一个函数指针数组，
*			分别指向这两种比较函数，只需要用户输入头文件中定义的宏 MINHEAP 和 MAXHEAP ，
*			即可实现相同的代码完成对堆的不同操作，同时，用户并不清楚内部的实现，也体现了封装的特质。
*			
*			如果你有更好的设计思路，欢迎告诉我，我会加上你的真知灼见。
**********************************************************************************************/

#include"heap.h"

#define PUBLIC 
#define PRIVATE static

// 最小堆的比较函数
int cmp_min(HPDataType data1, HPDataType data2)
{
	return data1 < data2;
}

// 最大堆的比较函数
int cmp_max(HPDataType data1, HPDataType data2)
{
	return data1 > data2;
}

PRIVATE void Swap(HPDataType* array, int child, int parent)
{
	HPDataType tmp = array[child];
	array[child] = array[parent];
	array[parent] = tmp;
}

// 定义了一个函数指针数组，成员为最小堆比较函数和最大堆比较函数
int (*cmp[2])(HPDataType child, HPDataType parent) = {cmp_min, cmp_max};


PRIVATE void shiftDown(HPDataType* array, int size, int parent, int flg)
{
	int child = 2 * parent + 1;

	while (child < size)
	{
		if (child + 1 < size && cmp[flg](array[child + 1], array[child]))
			child++;
		
		// 调用比较函数
		if (cmp[flg](array[child], array[parent]))
		{
			Swap(array, child, parent);
			parent = child;
			child = 2 * parent + 1;
		}
		else
			break;
	}
}

PRIVATE void shiftUp(HPDataType* array, int child, int flg)
{
	int parent = (child - 1) / 2;

	while (child > 0)
	{
		if (cmp[flg](array[child], array[parent]))
		{
			Swap(array, child, parent);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
			break;
	}
}


/************************* 接口函数 *************************/


void heapCreat(Heap* hp, HPDataType* array, int size, int flg)
{
	hp->_array = (HPDataType*)malloc(sizeof(HPDataType) * size);
	memcpy(hp->_array, array, sizeof(HPDataType) * size);
	hp->_size = size;
	hp->_capacity = MAX_HEAP;

	// 从第一个非叶子结点开始调整
	for (int parent = (size - 2) / 2; parent >= 0; parent--)
	{
		shiftDown(hp->_array, hp->_size, parent, flg);
	}
}

void heapPush(Heap* hp, HPDataType data, int flg)
{
	if (hp->_size == hp->_capacity)
	{
		hp->_capacity *= 2;

		HPDataType* new_arr = (HPDataType*)realloc(hp->_array, hp->_capacity * sizeof(HPDataType));
		
		// 直接把 realloc 的返回值赋给 hp->_array，如果 realloc 失败，可能会造成内存泄漏
		if (new_arr == NULL) 
		{
			printf("realloc failed in %s : %s %d\n", __func__, __FILE__, __LINE__);
			free(hp->_array);
			exit(EXIT_FAILURE);
		}
		hp->_array = new_arr;
	}

	hp->_array[hp->_size++] = data;

	shiftUp(hp->_array, hp->_size - 1, flg);
}


HPDataType heapPop(Heap* hp, int flg) {
	
	if (hp->_size <= 0)
	{
		printf("%s failed: heap is empty\n", __func__);
		exit(EXIT_FAILURE);
	}

	HPDataType ret = hp->_array[0];
	hp->_array[0] = hp->_array[--hp->_size];

	shiftDown(hp->_array, hp->_size, 0, flg);

	return ret;
}

void heapPrint(Heap* hp)
{
	for (int i = 0; i < hp->_size; i++)
	{
		printf("%d ", hp->_array[i]);
	}

	printf("\n");
}

