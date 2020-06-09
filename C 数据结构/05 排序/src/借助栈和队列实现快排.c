#include"sort.h"
#include"queue.h"
#include"stack.h"

int Partion(int* array, int begin, int end)
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
	swap(array, prev, begin);

	return prev;
}

void stackQuickSort(int* array, int size)
{
	Stack S;

	stackInit(&S, 20);

	if (size > 1)
	{
		// 先放右端点
		stackPush(&S, size - 1);
		stackPush(&S, 0);
	}

	while (!stackIsEmpty(&S))
	{
		int begin = stackPop(&S);
		int end = stackPop(&S);

		int keyPos = Partion(array, begin, end);

		// 先入右区间，再入左区间：保证先递归左侧
		// 区间至少存在两个元素才入栈
		if (keyPos + 1 < end)
		{
			stackPush(&S, end);
			stackPush(&S, keyPos + 1);
		}
		if (begin < keyPos - 1)
		{
			stackPush(&S, keyPos - 1);
			stackPush(&S, begin);
		}
	}

}

void queueQuickSort(int* array, int size)
{
	Queue Q;

	queueInit(&Q);

	if (size > 1)
	{
		// 先放左端点
		queuePush(&Q, 0);
		queuePush(&Q, size - 1);
	}

	while (!queueIsEmpty(&Q))
	{
		int begin = queuePop(&Q);
		int end = queuePop(&Q);

		int keyPos = Partion(array, begin, end);

		// 先入左区间，再入右区间：保证先递归左侧
		// 区间至少存在两个元素才入栈
		if (begin < keyPos - 1)
		{
			queuePush(&Q, begin);
			queuePush(&Q, keyPos - 1);			
		}
		if (keyPos + 1 < end)
		{
			queuePush(&Q, keyPos + 1);
			queuePush(&Q, end);
		}
	
	}
}