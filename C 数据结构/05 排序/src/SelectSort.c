
/************************************************************************
*	直接选择排序:
*			时间复杂度：最坏O(n^2) 平均O(n^2)  最好O(n^2)
*			空间复杂度：O(1)
*			稳定性：稳定
*			数据敏感：不敏感
*************************************************************************/

void selectSort(int* array, int size)
{	
	// 不管对于冒泡排序还是插入排序来说，size 为 n 的数组，只需要走 n - 1 趟即可
	// 因为最后一趟排序只剩下一个数在未排序的数组中了
	for (int i = 0; i < size - 1; i++)
	{
		// 取出未排序区域中的第一个元素
		int start = i;
		// 先将该元素假设为未排序区域的最小值
		int min = start;

		for (int j = start + 1; j < size; j++)
		{
			min = array[j] < array[min] ? j : min;
		}

		if (min != start)
		{
			swap(array, start, min);
		}
	}
}


// 优化的选择排序
void selectSortOp(int* array, int size)
{
	int begin = 0, end = size - 1;

	while (begin < end)
	{
		int min = begin, max = begin;
		
		for (int i = begin + 1; i <= end; i++)
		{
			if (array[i] < array[min])
			{
				min = i;
			}
			
			// 不加等于好会导致排序不稳定，因为如果 begin 是最大的，那它会换到最后，
			// 而 begin 和 end 之间可能有与 begin 大小相同的元素
			if (array[i] >= array[max])
			{
				max = i;
			}
		}

		swap(array, begin, min);
		// 如果最大元素下表为 begin，那么第一个 swap 将原本的最大值换到了数组 min 下表的位置上
		if (max == begin)
		{
			max = min;
		}
		swap(array, end, max);

		begin++, end--;
	}
}