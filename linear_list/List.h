#pragma once
#include<iostream>
using namespace std;
#include<vector>
#include <fstream>
template<class T>
class Liner
{
public:
	Liner(vector<T> res);
	~Liner();
	void ListInsertByLocate(int i, T e);//指定位置插入
	void ListInsertBeByVal(int &i, T e,T v);//指定元素的前插,返回下标
	void ListInsertAfByVal(int &i, T e, T v);//指定元素的后插,返回下标

	void ListDeleteByVal(int& i, T e);//通过指定数值删除，返回下标、、只删除第一个(只删除第一个符合的)
	bool ListDeleteByLocation(int i, T& e);//通过指定位置删除，并返回数值

	void DispList();//显示数据

	bool GetElem(int i, T& e);//通过下标查找数据

	int LocateElem(T e);//定位，返回下标、只返回第一个符合的下标

	void UpdateList(int i, T e);//更新指定下标的数据

	bool ListEmpty();//判空
	int ListLength();//返回表的长度

	bool save();//保存文件,专门处理student类

	bool readsome();

private:
	void InitList(vector<T> res);//初始化表
	void DestroyList();//摧毁表

private:
	vector<T> liner;
	int len;//表的长度
};


