#pragma once
#include"headAll.h"
class Node
{
private:
	int No; //����ı��
	string Name; //���������
public:
	Node() { No = -1; Name = "�޶���"; };
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

