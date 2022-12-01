#pragma once
#define INIT_SIZE 100
#define EXPANSIONSIZE 20
#include<iostream>
#include"Student.h"
#include <sstream>
using namespace std;
template <typename T>
class List {
private:
	T* elem; // 存储空间基址
	int size; // 当前顺序表的存储容量
	int length; // 当前顺序表的长度
public:
	List() = default;//默认构造
	List(T *arr,int s); //构造函数
	bool Init_Sqlist(); // 初始化顺序表，主要是开辟空间，初始化最大容量和设当前长度为0
	bool Init_Sqlist(T* arr, int s); // 初始化顺序表,传入数组,和长度，主要用于从文件未能读取数据时，初始化顺序表
	//插入
	bool insertBfVal(T val, T elem); // 用与在顺序表  指定的元素  前  添加元素 
	bool insertAfVal(T val, T elem); // 用与在顺序表  指定的元素  后  添加元素 
	bool insertByLoct(int idx, T elem); //用与在顺序表  指定的位置  添加元素 
	bool push_back(T elem); // 用于在顺序表的  最后  添加元素 
	//删除
	bool removeByloct(int idx, T& elem); // 用于在顺序表的   指定位置  删除元素 并通过引用的方式返回该元素的值
	bool removeByVal(int& idx, T elem); // 用于删除指定元素 并通过引用的方式返回该元素的下标 
	//显示数据
	void traverse(void (*print)(T& elem)); // 用于采用函数指针的方式打印顺序表中的元素，在print中打印一个元素
	//定位
	bool Getindex(int idx, T& elem); // 用于获取相应下标的 元素
	int Getindex(T elem, bool (*compare)(T, T)); // 用与获取 第一个 相似元素的 位置 
	//更新
	bool updateList(T elem, T val);//elem :传入 比对元素 val:想更改元素
	//文件的读写操作
	bool save();//保存文件,使用模板特例化
	bool readsome();//读取文件内容至该类数据指针中，使用模板特例化

	//排序
	void quick_sort(int l,int r);//快速排序之升序排序
	long stringTOlong(string str);//string 转long
	string longTOstring(long x);//long 转 string 

	int GetSize(); // 获取顺序表的存储容量
	int Getlen(); // 获取顺序表的长度
	void Clear(); // 重置顺序表
	bool Empty(); //判断表是否为空




	


	T operator[](int idx); // 重载下标运算符
	~List(); // 重写顺序表的析构函数

};



