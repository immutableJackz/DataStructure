#pragma once
#include<iostream>
template<class T>
class Node
{
public:
	T val;//�ڵ�ֵ
	Node<T>* lchid, *rchid;//�ڵ����Һ���ָ��
	Node<T>(T val) :val(val), lchid(NULL), rchid(NULL){};
	bool operator==(Node<T>* p) {
		return this->val == p->val;
	}
};

