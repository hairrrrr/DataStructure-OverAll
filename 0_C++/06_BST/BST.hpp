#pragma once
#include<iostream>
#include<queue>

using std::cin;
using std::cout;
using std::endl;

template<class T>
struct BSTNode
{
	T _val;
	BSTNode* _left;
	BSTNode* _right;

	BSTNode(const T val)
		:_val(val)
		,_left(nullptr)
		,_right(nullptr)
	{}
};

template<class T>
class BST
{
	typedef BSTNode<T> Node;
private:
	Node* _tree;
public:
	BST()
		:_tree(nullptr)
	{}
	
	~BST() 
	{ 
		destory(_tree);
	}
	
	// 查找
	Node* search(const T& val)
	{
		// non-const 成员函数复用 const 成员函数
		return const_cast<Node*>(
			static_cast<const BST<T>*>(this)->search(val) );
	}

	const Node* search(const T& val) const
	{
		return Search(_tree, val);
	}

	// 插入
	bool insert(const T& val)
	{
		Node* cur = _tree;
		Node* parent = nullptr;
		while (cur)
		{
			parent = cur;
			if (cur->_val == val)
				return false;
			else if (cur->_val > val)
				cur = cur->_left;
			else
				cur = cur->_right;
		}
		Node* node = new Node(val);
		// 树为空树
		if (parent == nullptr)
			_tree = node;
		else if (parent->_val > val)
			parent->_left = node;
		else
			parent->_right = node;
		return true;
	}

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
				fa->_right = cur->_left;
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
				fa->_right = cur->_left;
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
				fa->_left = cur->_right;
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

	// 优化后的 erase
	//bool erase(const T& val) 
	//{
	//	Node* del = nullptr, *pdel = nullptr;
	//	Node* cur = _tree;
	//	while (cur)
	//	{
	//		if (cur->_val == val)
	//		{
	//			del = cur;
	//			break;
	//		}
	//		else if (cur->_val > val)
	//		{
	//			pdel = cur;
	//			cur = cur->_left;
	//		}
	//		else
	//		{
	//			pdel = cur;
	//			cur = cur->_right;
	//		}
	//	}
	//	
	//	if (del == nullptr) return false;

	//	// 1. del 为叶节点
	//	if (!del->_left && !del->_right)
	//	{
	//		if (pdel == nullptr)
	//			_tree = nullptr;
	//		else
	//		{
	//			if (pdel->_left == del)
	//				pdel->_left = nullptr;
	//			else
	//				pdel->_right = nullptr;
	//		}
	//		delete del;
	//	}
	//	// 2. del 左子树为空
	//	else if (!del->_left)
	//	{
	//		if (pdel == nullptr)
	//			_tree = _tree->_right;
	//		else
	//		{
	//			if (pdel->_left == del)
	//				pdel->_left = del->_right;
	//			else
	//				pdel->_right = del->_right;
	//		}
	//		delete del;
	//	}
	//	// 3. del 右子树为空
	//	else if (!del->_right)
	//	{
	//		if (pdel == nullptr)
	//			_tree = _tree->_left;
	//		else
	//		{
	//			if (pdel->_left == del)
	//				pdel->_left = del->_left;
	//			else
	//				pdel->_right = del->_left;
	//		}
	//		delete del;
	//	}
	//	// 4. del 左右子树都不为空
	//	else
	//	{
	//		// 找到左子树的最右节点
	//		Node* cur = del->_left;
	//		Node* pcur = del;
	//		while (cur->_right)
	//		{
	//			pcur = cur;
	//			cur = cur->_right;
	//		}
	//		del->_val = cur->_val;
	//		if (pcur == del)
	//			pcur->_left = cur->_left;
	//		else
	//			pcur->_right = cur->_left;

	//		delete cur;
	//	}
	//	return true;
	//}

	// 层序遍历展示二叉树
	void show() const
	{
		// delim 指示二叉树当前层结束，此时可以输出换行符
		Node delim(0); //delimiter
		std::queue<Node*> Q;
		
		Q.push(_tree);
		Q.push(&delim);
		while (!Q.empty())
		{
			Node* front = Q.front();
			// 此时队列中仅剩下 delim，二叉树遍历完成，退出循环
			if (front == &delim)
				break;
			Q.pop();
			if (front)
			{
				cout << front->_val << " ";
				Q.push(front->_left);
				Q.push(front->_right);
			}
			else
				cout << "NULL ";
			// 如果此时队头是 delim，当前层结束，删除 delim 并在队尾添加 delim 
			if (Q.front() == &delim)
			{
				cout << endl;
				Q.pop();
				Q.push(&delim);
			}
		}
	}

private:
	const Node* Search(Node* _tree, const T& val) const
	{
		if (_tree == nullptr || _tree->_val == val)
			return _tree;
		else if (_tree->_val > val)
			return Search(_tree->_left, val);
		else
			return Search(_tree->_right, val);
	}

	// 后序遍历删除节点
	void destory(Node* _tree)
	{
		if (_tree)
		{
			destory(_tree->_left);
			destory(_tree->_right);
			delete _tree;
		}
	}

	Node* find(const T& val, Node** father)
	{
		Node* cur = _tree;
		Node* fa = nullptr;
		while (cur)
		{
			if (cur->_val == val)
			{
				// 设置目标节点的的父节点，如果目标节点为根节点，父节点为空
				*father = fa;
				return cur;
			}
			else if (cur->_val > val)
			{
				// 更新父节点
				fa = cur;
				cur = cur->_left;
			}
			else
			{
				fa = cur;
				cur = cur->_right;
			}
		}
		return nullptr;
	}
};
