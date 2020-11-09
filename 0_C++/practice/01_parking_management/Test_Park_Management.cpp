#include"Park_Management.hpp"
#include<stack>
#include<Windows.h>

using std::stack;

int main(void)
{
	Park p;
	srand(time(NULL));

	p.park(1);
	// 程序执行比较快，每次停车后程序暂停一段时间
	Sleep(rand() % 5000);
	p.park(2);
	Sleep(rand() % 5000);
	p.park(3);
	Sleep(rand() % 5000);
	p.park(4);
	Sleep(rand() % 5000);
	p.unpark(4);
	p.park(5);
	Sleep(rand() % 5000);
	p.park(6);
	Sleep(rand() % 5000);
	p.park(7);
	Sleep(rand() % 5000);

	p.unpark(7);
	p.unpark(1);
	p.unpark(7);

	return 0;
}

//int main(void)
//{
//	Queue<int> q;
//
//	q.push(1);
//	q.push(2);
//	q.push(3);
//
//	cout << q.front() << " " << q.back() << endl;
//
//	q.pop();
//
//	cout << q.front() << " " << q.back() << endl;
//
//	q.pop();
//
//	cout << q.front() << " " << q.back() << endl;
//
//	q.pop();
//
//	cout << q.front() << " " << q.back() << endl;
//
//	q.pop();
//
//	cout << q.front() << " " << q.back() << endl;
//
//	return 0;
//}

// test Stack.hpp
//int main(void)
//{
//	Stack<int> s;
//	s.push(1);
//	s.push(2);
//	s.push(3);
//
//	s.show();
//
//	cout << s.top() << endl;
//	s.pop();
//
//	s.show();
//
//}