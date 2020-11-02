#include"sort.h"

/***************************************
*	mergeSort:
*		时间复杂度：O(nlogn)
*		空间复杂度：O(n)
*		稳定：稳定
*		数据敏感：不敏感
****************************************/

#include<stdlib.h>
#include<string.h>

void merge(int* array, int* tmp, int begin, int mid, int end)
{
	int begin1 = begin;
	int end1 = mid;
	int begin2 = mid + 1;
	int end2 = end;
	int idx = begin;

	while (begin1 <= end1 && begin2 <= end2)
	{
		if (array[begin1] <= array[begin2])
			tmp[idx++] = array[begin1++];
		else
			tmp[idx++] = array[begin2++];
	}
	//查看是否有剩余元素
	if (begin1 <= end1)
		memcpy(tmp + idx, array + begin1, sizeof(int) * (end1 - begin1 + 1));
	if(begin2 <= end2)
		memcpy(tmp + idx, array + begin2, sizeof(int) * (end2 - begin2 + 1));
	//拷贝到原始空间
	memcpy(array + begin, tmp + begin, sizeof(int) * (end - begin + 1));
}

void divideR(int* array, int* tmp, int begin, int end)
{
	if (begin >= end)
		return;

	int mid = begin + (end - begin) / 2;

	// 分：首先保证子区间有序，首先子区间的排序
	divideR(array, tmp, begin, mid);
	divideR(array, tmp, mid + 1, end);
	
	// 治：合并有序子区间
	merge(array, tmp, begin, mid, end);
}

void divideNoR(int* array, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	//待合并区间的元素个数
	int k = 1;
	//多轮的归并
	while (k < n)
	{
		//一轮归并
		for (int i = 0; i < n; i += 2 * k)
		{
			//[begin, mid]  [mid + 1, end]
			int begin = i;

			int mid = i + k - 1;
			//判断mid是否越界
			if (mid >= n - 1)
				continue;

			int end = i + 2 * k - 1;
			//判断end是否越界
			if (end >= n)
				end = n - 1;
			merge(array, begin, mid, end, tmp);
		}
		k *= 2;
	}
}

void mergeSort(int* array, int size)
{
	int* tmp = (int*)malloc(sizeof(int) * size);
	divideR(array, tmp, 0, size - 1);
	free(tmp);
}