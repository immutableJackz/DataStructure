#include "Stack.hpp"
template<class T>
Stack<T>::Stack() {
	this->cur = -1;
	this->size = 0;
}

template<class T>
T Stack<T>::getTop()
{
	if(!empty())
		return val[cur];
}

template<class T>
bool Stack<T>::empty()
{
	return cur==-1;
}

template<class T>
void Stack<T>::Push(T val)
{
	this->val[++cur] = val;
	this->size++;
}

template<class T>
void Stack<T>::Pop()
{
	cur--, size--;
}
