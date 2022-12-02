#pragma once
template<class T>
class Stack
{
public:
	Stack();
	T getTop();
	bool empty();
	void Push(T val);
	void Pop();
private:
	int size;//栈元素个数
	int cur;//栈顶元素指针
	T val[100];//储存元素数组
};

