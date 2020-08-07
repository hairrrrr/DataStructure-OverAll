#define MAXSIZE 10 // 数组S的最大长度

typedef int ElementType;

typedef struct {
	ElementType Data;
	int Parent;
}SetType;


/* 在数组S中查找值为X的元素所属的集合 */
int setFind(SetType S[], ElementType X) {
	
	int i;

	for (i = 0; i < MAXSIZE && S[i].Data != X; i++)
		;

	/* 未找到X，返回-1 */
	if (i >= MAXSIZE) return -1; 

	// 如果 i 下标对应的数组元素不是根节点， 将当前结点的父节点的下标赋给 i
	for (; S[i].Parent >= 0; i = S[i].Parent) 
		;

	return i;
}

void Union(SetType S[], ElementType X1, ElementType X2) {

	int root1, root2;

	root1 = setFind(S, X1);
	root2 = setFind(S, X2);

	if (root1 == root2) return;

	S[root1].Parent = root2;
}
