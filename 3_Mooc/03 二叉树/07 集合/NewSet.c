#define MAXN 1000                  /* 集合最大元素个数 */
typedef int ElementType;           /* 默认元素可以用非负整数表示 */
typedef int SetName;               /* 默认用根结点的下标作为集合名称 */
typedef ElementType SetType[MAXN]; /* 假设集合元素下标从0开始 */
 
void Union(SetType S, SetName root1, SetName root2) {
    
	S[root1] = root2; 
}


SetName setFind(SetType S, ElementType X) {
    
	for (; S[X] >= 0; X = S[X])
		;

	return X;
}
