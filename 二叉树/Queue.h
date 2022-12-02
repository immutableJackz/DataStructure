#pragma once
template<class T>
#define MAXSIZE 100
class Queue
{
private:
	T data[MAXSIZE];//储存数组
	int front, rear;//front 队头指针 rear队尾指针
public:
	Queue();
	bool empty();
	void Push(T e);
	void Pop();
	T getFront();
};

