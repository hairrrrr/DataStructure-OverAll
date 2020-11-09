#pragma once
#include<iostream>
#include<ctime>
#include"Queue.hpp"
#include"Stack.hpp"

using std::cin;
using std::cout;
using std::endl;

struct Bus
{
	size_t num;
	time_t in_time;
	
	Bus() = default;

	Bus(size_t _num)
		:num(_num)
	{}

	bool operator==(Bus& bus)
	{
		this->num == bus.num;
	}
};

class Park
{
private:
	// 计费规则：3 秒 15 元，不满 3 秒按 3 秒算
	enum {FEE = 15, PARK_CAPACITY = 5};
	Stack<Bus> _in;
	Stack<Bus> _out;
	Queue<Bus> _wait;

public:
	Park()
		:_in(PARK_CAPACITY)
		,_out(PARK_CAPACITY)
	{}

	// 停车
	void park(size_t num)
	{
		// 停车场满
		Bus bus;
		bus.num = num;
		if (_in.size() == PARK_CAPACITY)
		{
			_wait.push(bus);
		}
		else
		{
			bus.in_time = time(NULL);
			_in.push(bus);
		}
	}

	// 取车并计费
	void unpark(size_t num)
	{
		// 1. 取车
		Bus cur;
		while (!_in.empty())
		{
			cur = _in.top();
			_in.pop();
			if (num == cur.num)
				break;
			_out.push(cur);
		}
		// 2. 计费
		if (num == cur.num)
		{
			time_t all_time = time(NULL) - cur.in_time;
			int fee;
			if (all_time % 3 == 0)
				fee = all_time / 3 * FEE;
			else
				// 不满 3 秒按 3 秒算
				fee = (all_time / 3 + 1) * FEE;
			cout << "编号为 " << cur.num << " 的车停车 "
				<< all_time << " 秒，" << "收费 "
				<< fee << " 元" << endl;
		}
		else
			cout << "编号为 " << num << " 的车不存在" << endl;

		// 3. 后面的车重新进入停车场
		while (!_out.empty())
		{
			_in.push(_out.top());
			_out.pop();
		}

		// 4. 外面等待的车进入停车场
		if (!_wait.empty())
		{
			cur = _wait.front();
			_wait.pop();
			park(cur.num);
		}
	}

};


