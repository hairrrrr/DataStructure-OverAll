#pragma once
#include<iostream>

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
};
