#pragma once
#define INIT_SIZE 100
#define EXPANSIONSIZE 20
#include<iostream>
#include"Student.h"
#include"Node.h"
#include <sstream>
using namespace std;
template <typename T>
class List
{
private:
	Node<T>* head;
	Node<T>* tail;
	int size; // 当前表的大小
public:
	List()=default;//默认构造
	List(T* arr,int s);//按数组构造
	bool Init_Sqlist(); // 初始化链表，主要是开辟空间，初始化最大容量和设当前长度为0
	bool Init_Sqlist(T * arr, int s); // 初始化链表,传入数组,和长度，主要用于从文件未能读取数据时，初始化链表
	//插入
	bool insertBfVal(T val, T elem); // 用与在链表  指定的元素  前  添加元素 
	bool insertAfVal(T val, T elem); // 用与在链表  指定的元素  后  添加元素 
	bool insertByLoct(int idx, T elem); //用与在链表  指定的位置  添加元素 
	bool push_back(T val); // 用于在链表的  最后  添加元素 
	//删除
	bool removeByloct(int idx, T & elem); // 用于在链表的   指定位置  删除元素 并通过引用的方式返回该元素的值
	bool removeByVal(int& idx, T elem); // 用于删除指定元素 并通过引用的方式返回该元素的下标 
	//显示数据
	void Printall(); // 遍历打印每个节点的元素
	//定位
	int Getindex(T val); // 用与获取 第一个 相似元素的 位置 
	//更新
	bool updateList(T elem, T val);//elem :传入 比对元素 val:想更改元素
	//文件的读写操作
	bool save();//保存文件,使用模板特例化
	bool readsome();//读取文件内容至该类数据指针中，使用模板特例化

	//翻转链表
	void reverseList();//迭代的方式翻转链表

	int GetSize(); // 获取链表的存储容量
	bool Empty(); //判断表是否为空

	~List(); // 重写链表的析构函数
};


