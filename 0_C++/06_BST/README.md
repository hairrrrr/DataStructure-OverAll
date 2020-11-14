## 二叉搜索树实现



![](https://hairrrrr.github.io/assets/2020-11-14-1.jpg)



优化前的代码如下：

```cpp
bool erase(const T& val)
	{
		Node* father;
		Node* del = find(val, &father);
		if (!del)
		{
			cout << "值为 " << val << " 的节点不存在，删除失败" << endl;
			return false;
		}

		// cur 为替换删除节点的节点，fa 为其父节点
		Node* fa = del, * cur;
		// 1. 如果待删除节点左右子树都存在，左子树的最右节点或右子树的最左节点都可以替换此节点
		// 选择找左子树的最右节点
		if (del->_left && del->_right)
		{
			// cur 走到左子树
			cur = del->_left;
			while (cur->_right)
			{
				fa = cur;
				cur = cur->_right;
			}
			// 替换节点不是待删除节点的左节点时
			if (cur != del->_left)
			{
				fa->_right = nullptr;
				cur->_left = del->_left;
			}

			cur->_right = del->_right;
		}
		// 2. 只有左子树
		else if (del->_left)
		{
			cur = del->_left;
			while (cur->_right)
			{
				fa = cur;
				cur = cur->_right;
			}
			// 替换节点不是待删除节点的左节点时
			if (cur != del->_left)
			{
				fa->_right = nullptr;
				cur->_left = del->_left;
			}

		}
		// 3. 只有右子树
		else if (del->_right)
		{
			cur = del->_right;
			while (cur->_left)
			{
				fa = cur;
				cur = cur->_left;
			}
			// 替换节点不是待删除节点的右节点时
			if (cur != del->_right)
			{
				fa->_left = nullptr;
				cur->_right = del->_right;
			}
		}
		// 待删除节点为叶节点
		else
			cur = nullptr;
		
		// father 是空指针，被删除的节点是树的根节点
		if (!father)
			_tree = cur;
		else
		{
			if (father->_left == del)
				father->_left = cur;
			else
				father->_right = cur;
		}
		delete del;
	}
```

上面的程序有一个 bug:

![](https://hairrrrr.github.io/assets/2020-11-14-2.jpg)

程序输出为：

```
9
7 11
3 NULL NULL NULL
2 5
NULL NULL 4 NULL
NULL NULL

9
5 11
3 NULL NULL NULL
2 NULL
NULL NULL
```









