#include"sort.h"

/************************************************************************
*	quickSort:
*		时间复杂度：最坏：O(n^2) 平均：O(nlogn) 最好：O(nlogn)
*		空间复杂度：O(logn) 最坏：O(n^2) 一般不会出现
*		稳定性：不稳定
*		数据敏感：敏感
*************************************************************************/

// hoare 法
int partion1(int* array, int begin, int end)
{
	// 设置基准值
	int key = array[begin];
	int start = begin;

	while (begin < end)
	{	
		// 必须先从后向前找

		// 从后往前找第一个比 key 小的元素
		while (begin < end && array[end] >= key)
			end--;

		// 从前向后找到第一个比 key 大的元素
		while (begin < end && array[begin] <= key)
			begin++;
		
		swap(array, begin, end);
	}

	// 交换基准位置和相遇位置的元素
	swap(array, start, begin);

	return begin;
}

// 挖坑法
int partion2(int* array, int begin, int end)
{
	int key = array[begin];

	while (begin < end)
	{
		// 从后向前找小的
		while (begin < end && array[end] >= key)
			end--;
		array[begin] = array[end];

		// 从前向后找大的
		while (begin < end && array[begin] <= key)
			begin++;
		array[end] = array[begin];
	}

	// 填最后一个坑，从循环出来，begin 和 end 是相等的
	array[begin] = key; 

	return begin;
}

int partion3(int* array, int begin, int end)
{
	int prev = begin;
	int cur = begin + 1;
	int key = array[begin];

	while (cur <= end)
	{
		if (array[cur] < key && ++prev != cur)
		{
			swap(array, prev, cur);
		}
		++cur;
	}
	// 将最后一个交换后的比基准值小的元素与基准值交换，基准值前的都是比基准值小的元素
	swap(array, prev, begin);

	return prev;
}

int getMid(int* array, int begin, int end)
{
	int mid = begin + (end - begin) / 2;
	
	if (array[mid] < array[begin])
	{	
		//mid < begin

		// begin < end
		if (array[begin] < array[end])
			return begin;
		// begin >= end
		else
		{	
			// mid < end
			if (array[mid] < array[end])
				return end;
			else
				return mid;
		}
	}
	// mid >= begin
	else
	{
		if (array[mid] < array[end])
			return mid;
		else
		{
			if (array[end] > array[begin])
				return end;
			else
				return begin;
		}
	}
}


// 为了解决最坏时间复杂度为 O(n^2) ，我们在选取基准的时候，可以大概的找到一个中间值
int partion(int* array, int begin, int end)
{	
	int mid = getMid(array, begin, end);

	// 将找到的数组中的 mid 下标的元素和 begin 交换 
	swap(array, mid, begin);

	// 设置基准值
	int key = array[begin];
	int start = begin;

	while (begin < end)
	{
		// 必须先从后向前找

		// 从后往前找第一个比 key 小的元素
		while (begin < end && array[end] >= key)
			end--;

		// 从前向后找到第一个比 key 大的元素
		while (begin < end && array[begin] <= key)
			begin++;

		swap(array, begin, end);
	}

	// 交换基准位置和相遇位置的元素
	swap(array, start, begin);

	return begin;
}

void quickSort(int* array, int begin, int end)
{
	if (begin >= end)
		return;

	int key_pos = partion(array, begin, end);
	
	// 划分子区间
	quickSort(array, begin, key_pos - 1);
	quickSort(array, key_pos + 1, end);
}



