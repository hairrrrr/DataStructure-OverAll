#include"sort.h"

/***************************************************************
*	bubbleSort:
*		时间复杂度：最坏O(n^2) 平均O(n^2)  最好O(n)
*		空间复杂度：O(1)
*		稳定性：稳定
*		数据敏感：敏感
***************************************************************/

void bubbleSort(int* array, int size)
{	
	for (int i = 0; i < size - 1; i++)
	{
		int flg = 1;

		for (int j = 0; j < size - 1 - i; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap(array, j, j + 1);
				flg = 0;
			}
				
		}
		if (flg)
			break;
	}
}