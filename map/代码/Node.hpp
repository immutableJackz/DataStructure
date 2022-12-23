#pragma once
#include"headAll.h"
class Node
{
private:
	int No; //顶点的编号
	string Name; //顶点的名称
public:
	Node() { No = -1; Name = "无顶点"; };
	Node(int No, string Name) :No(No), Name(Name){}
	string GetName() { return this->Name; }
	int GetNo() { return this->No; }
	void SetName(string name) {
		this->Name = name;
	}
	void SetNo(int no) {
		this->No = no;
	}
};

