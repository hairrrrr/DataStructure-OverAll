#include"sort.h"

/************************************************************************
*	希尔排序:
*			时间复杂度：最坏O(n^1.3) 平均O(n^1.3)  最好O(n)
*			空间复杂度：O(1)
*			稳定性：不稳定  ---> 分组时相同值的元素不一定可以分到同一组，
					预排序是可能导致相对位置发生变化
*			数据敏感：敏感
*************************************************************************/

void shellSort(int* array, int size)
{
	//gap: 步长
	int gap = size;
	// 如果 size <= 1 就不需要进行排序了
	//多轮插入排序
	while (gap > 1)
	{
		// gap 3 倍减小，加 1 是为了防止除法运算后 gap 变成 0 
		gap = gap / 3 + 1;

		//一轮插入排序
		for (int i = 0; i < size - gap; i++)
		{
			//通过步长gap进行逻辑分组
			//组内进行插入排序
			//不同组的元素交替进行排序

			int end = i;
			int key = array[end + gap];

			while (end >= 0 && array[end] > key)
			{
				array[end + gap] = array[end];
				end -= gap;
			}
			array[end + gap] = key;
		}
	}

}