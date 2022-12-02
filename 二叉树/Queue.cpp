#include "Queue.h"
template<class T>
Queue<T>::Queue() {
	this->front = this->rear = -1;
}

template<class T>
bool Queue<T>::empty()
{
	return this->rear==this->front;
}

template<class T>
void Queue<T>::Push(T e)
{
	if (this->rear == MAXSIZE - 1)
		return;
	this->data[++this->rear] = e;
}

template<class T>
void Queue<T>::Pop()
{
	if (empty())
		return;
	this->front++;
}

template<class T>
T Queue<T>::getFront()
{
	if (!empty())return this->data[this->front + 1];
}
