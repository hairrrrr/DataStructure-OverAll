void Swap(int* array, int left, int right)
{
	int tmp = array[left];
	array[left] = array[right];
	array[right] = tmp;
}

void shiftDown(int* array, int size, int parent)
{

	int child = 2 * parent + 1;
	while (child < size)
	{

		if (child + 1 < size && array[child + 1] > array[child])
			++child;

		if (array[child] > array[parent])
		{
			Swap(array, child, parent);
			parent = child;
			child = 2 * parent + 1;
		}
		else
			break;
	}
}

// 堆排序
void heapSort(int* array, int size)
{
	// 建堆
	for (int parent = (size - 2) / 2; parent >= 0; parent--)
	{
		shiftDown(array, parent, size);
	}
	

	while (size > 1)
	{	
		// 删除最大项（头删），然后将最后的元素补到根节点
		Swap(array, 0, size - 1);
		// 将总的大小减小，相当于是将最大的元素留在已排序好的区域
		size--;
		// 向下调整，将堆再次调整为最大堆
		shiftDown(array, 0, size);

	}
}