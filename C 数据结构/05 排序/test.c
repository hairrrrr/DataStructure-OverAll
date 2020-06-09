#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"sort.h"


void print(int* array, int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%d ", array[i]);
	}
	printf("\n");
}

int main(void)
{
	int array[] = { 10, 2, 4, 1, 3, 6, 5, 12, 9, 10, 2 };
	int size = sizeof(array) / sizeof(array[0]);

	countSort(array, size);
	print(array, size);

	return 0;
}

