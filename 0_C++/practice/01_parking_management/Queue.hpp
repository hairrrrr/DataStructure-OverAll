#pragma once

#include<iostream>

using std::cin;
using std::cout;
using std::endl;

/*
 * List 是一个双向循环链表
 */
template<class T>
struct List
{
	T _val;
	List* _next;
	List* _prev;
	
	List() = default;

	List(const T& val)
		:_val(val)
		,_next(nullptr)
		,_prev(nullptr)
	{}
};

template<class T>
class Queue
{
private:
	List<T> _head;
	size_t _size;
	typedef List<T> List;
public:
	Queue()
		:_size(0)
	{
		_head._next = _head._prev = &_head;
	}

	~Queue() = default;

	bool empty() const
	{
		return _size == 0;
	}

	size_t size() const
	{
		return _size;
	}

	T& front()
	{
		Assert();
		return _head._next->_val;
	}

	const T& front() const
	{
		Assert();
		return _head._next->_val;
	}

	T& back()
	{
		Assert();
		return _head._prev->_val;
	}

	const T& back() const 
	{
		Assert();
		return _head._prev->_val;
	}

	void push(const T& val)
	{
		List* node = MakeNode(val);
		
		node->_next = &_head;
		node->_prev = _head._prev;
		_head._prev->_next = node;
		_head._prev = node;
	
		_size++;
	}

	void pop()
	{
		if (empty())
			Assert();
		List* del = _head._next;
		_head._next = del->_next;
		del->_next->_prev = &_head;
		
		delete del;

		_size--;
	}

private:
	List* MakeNode(const T& val)
	{
		List* node = new List(val);
		return node;
	}

	void Assert() const
	{
		if (empty())
		{
			cout << "非法操作，Queue 为空" << endl;
			exit(EXIT_FAILURE);
		}
	}
};
