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
	int size;//ջԪ�ظ���
	int cur;//ջ��Ԫ��ָ��
	T val[100];//����Ԫ������
};

