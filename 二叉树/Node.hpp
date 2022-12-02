#pragma once
#include<iostream>
template<class T>
class Node
{
public:
	T val;//节点值
	Node<T>* lchid, *rchid;//节点左右孩子指针
	Node<T>(T val) :val(val), lchid(NULL), rchid(NULL){};
	bool operator==(Node<T>* p) {
		return this->val == p->val;
	}
};

