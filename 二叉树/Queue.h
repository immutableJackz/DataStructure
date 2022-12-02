#pragma once
template<class T>
#define MAXSIZE 100
class Queue
{
private:
	T data[MAXSIZE];//��������
	int front, rear;//front ��ͷָ�� rear��βָ��
public:
	Queue();
	bool empty();
	void Push(T e);
	void Pop();
	T getFront();
};

