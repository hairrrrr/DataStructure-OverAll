#define MAX_SET 10

typedef int ElementType;
typedef int SetName; /* 默认用根结点的下标作为集合名称 */
// SetType 类型为 ElementType[MAX_SET]
typedef ElementType SetType[MAX_SET]; /* 假设集合元素下标从0开始 */

// 上面的循环可以用递归来实现
SetName setFind(SetType S, ElementType X) {
	
	if (S[X] < 0)
		return X;
	else
		setFind(S, S[X]);
}

void Union(SetType S, SetName root1, SetName root2) {
	// 默认 root1 和 root2 是两个集合的根节点
	
	// 集合 root1 子节点多于 root2  
	if (S[root1] < S[root2]) {
		S[root1] += S[root2]; // 集合 2 并入集合 1
		S[root2] = root1; 
	}
	else {
		S[root2] += S[root1]; // 集合 1 并入集合 2
		S[root1] = root2;
	}
}
