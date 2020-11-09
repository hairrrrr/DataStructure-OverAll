#pragma once

#include<iostream>

using std::cin;
using std::cout;
using std::endl;

template<class T>
class Stack
{
public:
	Stack()
		:_capacity(init_size)
		,_size(0)
		,_array(new T[init_size])
	{}

	Stack(size_t capacity)
		:_capacity(capacity)
		, _size(0)
		, _array(new T[capacity])
	{}

	~Stack()
	{
		delete[] _array;
	}

	T& top()
	{
		return _array[_size - 1];
	}

	const T& top() const
	{
		return _array[_size - 1];
	}

	size_t size() const
	{
		return _size;
	}

	void push(const T& val)
	{
		// À©ÈÝ
		if (_size == _capacity)
		{
			T* new_array = new T[_capacity * 2];
			for (int i = 0; i < _capacity; i++)
				new_array[i] = _array[i];
			delete[] _array;
			_array = new_array;
			_capacity *= 2;
		}
		_array[_size] = val;
		++_size;
	}

	void pop()
	{
		_size--;
	}

	bool empty() const
	{
		return _size == 0;
	}

	void show() const
	{
		int i;
		for (i = 0; i < _size; i++)
			cout << _array[i] << " " ;
		cout << endl;
	}
private:
	enum{init_size = 3};
	T* _array;
	size_t _size;
	size_t _capacity;
};
