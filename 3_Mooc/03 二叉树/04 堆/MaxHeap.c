#define _CRT_SECURE_NO_WARNINGS 1

#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>

#define MAXDATA 1000 /* 该值应根据具体情况定义为大于堆中所有可能元素的值 */
#define ERROR -1 // 提示调用失败

typedef int ElementType;

typedef struct {
	ElementType* Data;
	int Size; // 堆中当前元素个数
	int Capacity; // 堆的最大容量
}Heap;

typedef Heap MaxHeap; // 最大堆



MaxHeap* createHeap(int size);
void buildMaxHeap(MaxHeap* H);
void percDown(MaxHeap* H, int i);
bool heapIsFull(MaxHeap* H);
bool heapIsEmpty(MaxHeap* H);
bool heapInsert(MaxHeap* H, ElementType X);
ElementType heapDelete(MaxHeap* H);

int main(void) {
	
	int i, two_power = 2;

	MaxHeap* H = createHeap(12);

	for (i = 1; i <= H->Capacity; i++) {
		scanf("%d", &H->Data[i]);
		H->Size++;
	}

	buildMaxHeap(H);

	for (i = 1; i <= H->Capacity; i++) {
		printf("%d ", H->Data[i]);
		if (i == two_power - 1) {
			two_power *= 2;
			printf("\n");
		}
	}


	return 0;
}


MaxHeap* createHeap(int size) {
	
	MaxHeap* heap = (MaxHeap*)malloc(sizeof(MaxHeap));
	
	heap->Data = (ElementType*)malloc(sizeof(ElementType) * (size + 1));
	heap->Size = 0;
	heap->Capacity = size;
	heap->Data[0] = MAXDATA;

	return heap;
}

bool heapIsFull(MaxHeap* H) {

	return H->Size == H->Capacity;
}

bool heapIsEmpty(MaxHeap* H) {

	return H->Size == 0;
}

/* 将元素X插入最大堆H，其中H->Data[0]已经定义为哨兵 */
bool heapInsert(MaxHeap* H, ElementType X) {

	int i;

	if (heapIsFull(H)) {
		printf("Heap is full\n");
		return false;
	}

	i = ++H->Size;

	// 因为 X 不可能大于 Data[0]，所以 i 的最小值为 1 
	for (; H->Data[i / 2] < X; i /= 2)
		H->Data[i] = H->Data[i / 2]; // 上滤（父节点下沉）
	
	H->Data[i] = X; // 插入 x

	return true;
}

/* 从最大堆H中取出键值为最大的元素，并删除一个结点 */
ElementType heapDelete(MaxHeap* H) {
	
	int Parent, Child;
	ElementType maxItem, lastItem;

	if (heapIsEmpty(H)) {
		printf("heap is empty\n");
		return ERROR;
	}

	maxItem = H->Data[1]; /* 取出根结点存放的最大值 */
	
	lastItem = H->Data[H->Size--];  /* 注意当前堆的规模要减小 */

	for (Parent = 1; Parent * 2 <= H->Size; Parent = Child) {

		Child = 2 * Parent;
		if ((Child != H->Size) && (H->Data[Child] < H->Data[Child + 1]))
			Child++;  /* Child指向左右子结点的较大者 */

		if (H->Data[Child] < maxItem)
			break;

		else
			H->Data[Parent] = H->Data[Child]; // 下滤
	}

	H->Data[Parent] = lastItem;

	return maxItem;
	
}

void percDown(MaxHeap* H, int index_root) {

	int Parent, Child;
	ElementType val_root;

	val_root = H->Data[index_root];

	for (Parent = index_root; Parent * 2 <= H->Size; Parent = Child) {

		Child = 2 * Parent;
		if ((Child != H->Size) && (H->Data[Child] < H->Data[Child + 1]))
			Child++; 
		if (val_root > H->Data[Child]) // 如果父节点的值大于两个子结点，退出
			break;

		else
			H->Data[Parent] = H->Data[Child]; // 下滤
	}

	H->Data[Parent] = val_root;
}


void buildMaxHeap(MaxHeap* H) {

	for (int i = H->Size / 2; i > 0; i--)
		percDown(H, i);
}

