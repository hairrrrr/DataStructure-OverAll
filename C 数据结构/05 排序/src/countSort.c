#include"sort.h"
#include<stdlib.h>
#include<string.h>
/*******************************************************************
*	计数排序： 只适合小范围数据， 如果范围大，空间复杂度较高:
*		时间复杂度：O(max(n, 范围))
*		空间复杂度：O(范围)
*		稳定：一般教材认为是稳定的(欠妥)
*		数据敏感：不敏感
*******************************************************************/


void countSort(int* array, int size)
{
	int min = array[0], max = array[0];
	int i;

	//统计范围
	for (i = 0; i < size; i++)
	{
		if (array[i] < min)
			min = array[i];
		if (array[i] > max)
			max = array[i];
	}

	int count_num = max - min + 1;
	//开辅助空间，进行计数
	int* count_arr = malloc(sizeof(int) * count_num);
	//初始化为0
	memset(count_arr, 0x0, sizeof(int) * count_num);

	if (!count_arr)
		exit(EXIT_FAILURE);
	
	//统计次数
	for (i = 0; i < size; i++)
	{
		count_arr[array[i] - min]++;
	}

	//恢复数据， 遍历计数数组
	int idx = 0;
	for (i = 0; i < count_num; i++)
	{
		while (count_arr[i]--)
		{
			array[idx++] = i + min;
		}
	}

	free(count_arr);
}