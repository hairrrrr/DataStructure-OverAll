#define _CRT_SECURE_NO_WARNINGS 1

/*
 *	Data: 2023/3/27
 *  User: hairrrrr
 *  Description: Sequence list implementation.
 *
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef int DataType;

typedef struct SeqList {

	DataType* array; // 指向动态开辟的数组
	size_t size; // 有效数据个数
	size_t capacity; // 数组大小
	
	// size_t 就是 unsigned int 类型，size，capacity 都是正整数

}SeqList;

typedef SeqList* plist;

void SeqListPushBack(plist sl, DataType data); // 尾插
void SeqListPushFront(plist sl, DataType data); // 头插

void SeqListPopBack(plist sl); // 尾删
void SeqListPopFront(plist sl); // 头删

void SeqListInsert(plist sl, size_t pos, DataType data); // pos 位插入 x
void SeqListRemove(plist sl, size_t pos); // pos 位删除

void SeqListInit(plist sl, size_t capacity); // 初始化
void SeqListDestory(plist sl); // 销毁

void SeqListPrint(plist sl); // 打印
void SeqListCheckCapacity(plist sl); // 检查空间是否已经满，如果满了，就扩容

int main(void) {

	SeqList s;
	plist sl = &s;

	SeqListInit(sl, 5);

	SeqListPushFront(sl, 1);
	SeqListPushBack(sl, 2);
	SeqListPushBack(sl, 3);
	SeqListPushBack(sl, 4);
	SeqListPushFront(sl, 0);
	
	SeqListPushFront(sl, -1);
	SeqListPushBack(sl, 5);
	// -1 0 1 2 3 4 5

	SeqListPopBack(sl);
	SeqListPopFront(sl);

	// 0 1 2 3 4

	SeqListInsert(sl, 2, 2);
	SeqListInsert(sl, 0, 0);
	SeqListInsert(sl, sl->size, 4);

	// 0 0 1 2 2 3 4 4

	SeqListRemove(sl, 0);
	SeqListRemove(sl, sl->size - 1);
	SeqListRemove(sl, 2);

	// 0 1 2 3 4

	SeqListDestory(sl);

	SeqListPrint(sl);



	return 0;
}

void SeqListInit(plist sl, size_t capacity) {

	sl->array = (DataType*)malloc(sizeof(DataType) * capacity);
	sl->capacity = capacity;
	sl->size = 0;
}

void SeqListPushBack(plist sl, DataType data) {
	
	SeqListInsert(sl, sl->size, data);
}


void SeqListPushFront(plist sl, DataType data) {

	SeqListInsert(sl, 0, data);
}

void SeqListPopBack(plist sl) {

	SeqListRemove(sl, sl->size - 1);
}

void SeqListPopFront(plist sl) {
	
	SeqListRemove(sl, 0);
}


void SeqListInsert(plist sl, size_t pos, DataType data) {

	if (pos < 0 || pos > sl->size) {
		printf("非法的下标！");
		return;
	}
	
	SeqListCheckCapacity(sl);

	// 从数组最后一个元素开始向后移动
	size_t end = sl->size;
	
	// end 是 unsigned int 类型，判断条件不能是 "= 0" 因为这样写会让程序进入死循环，
	// 当 end == 0 时， end-- 不会让 end 小于 0 只会让 end 变成 unsigned int 可以表示的最大值
	while (end > pos) {
		sl->array[end] = sl->array[end - 1];// 不要把顺序写反了，把前面的值给后面
		end--;
	}

	sl->array[pos] = data;

	++sl->size;
}

void SeqListRemove(plist sl, size_t pos) {

	if (pos >= sl->size || pos < 0) {
		printf("非法的下标!");
		return;
	}
	
	// 从数组第 pos + 1 元素开始向前移动

	size_t start = pos + 1;
	
	while (start < sl->size) {
		sl->array[start - 1] = sl->array[start];
		start++;
	}
	--sl->size;
}

void SeqListCheckCapacity(plist sl) {

	if (sl->capacity <= sl->size) {
		// 2 倍扩容
		DataType* newarr = (DataType*)malloc(sizeof(DataType) * 2 * sl->capacity);
		if (newarr != NULL) {
			memcpy(newarr, sl->array, sl->capacity * sizeof(DataType));
			free(sl->array);
			sl->array = newarr;
			sl->capacity *= 2;
		}
		else {
			printf("数组已满，扩容失败！");
			return;
		}
		
	}
	
}

void SeqListDestory(plist sl) {

	free(sl->array);
	sl->capacity = 0;
	sl->size = 0;
}

void SeqListPrint(plist sl) {
	
	for (size_t i = 0; i < sl->size; i++) {
		printf("%d ", sl->array[i]);
	}
}
