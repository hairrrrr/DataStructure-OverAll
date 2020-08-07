#define _CRT_SECURE_NO_WARNINGS 1

typedef struct {
	HuffmanTree* Element[100]; 
	//堆的结点的数据结构是数组方便我们实现，但是因为这些结点以后会变成哈夫曼树的一部分，
	//所以，数组的元素需要是 HuffmanTree 的指针类型（他们是由我们 malloc 得来的）
	// 以前数组元素的值 Element[i] 存放到 Element[i]->Weight 中
	int size;
	int capacity;
}MinHeap;


typedef struct {
	int Weight;
	HuffmanTree *Left, *Right;
}HuffmanTree;



HuffmanTree* huffman(MinHeap* H) {
	int i;
	HuffmanTree* T;
	buildMinHeap(H);// 按照权值创建最小堆

	// 只需要多创建 H->size - 1 结点即可
	for (i = 1; i < H->size; i++) {
		T = malloc(sizeof(HuffmanTree));
		T->Left = deleteHeap(H);
		T->Right = deleteHeap(H);
		T->Weight = T->Left->Weight + T->Right->Weight;

		Insert(H, T); // 将新的结点插入到最小堆中
	}

	// 经过 size - 1 次循环，最小堆中只剩一个元素，就是树头

	T = deleteHeap(H);
	return T;
}



