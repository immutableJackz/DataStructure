#pragma once
using namespace std;
template <typename T>
#include"Student.h"
class Node {//½Úµã
public:
	T val; //ÖµÓò
	Node<T>* next;
	Node();
	Node(T val) :val(val), next(nullptr){}
	Node(T val,Node<T> next) :val(val), next(next){}
	~Node() {
	
	}
};

template<>
inline Node<int>::Node()
	:val(-1),next(nullptr)
{
}
template<>
inline Node<student>::Node()
	:val(student("jiade","-1")), next(nullptr)
{
}
