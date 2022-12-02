#pragma once
#include<string>
#include<iostream>
using namespace std;
class student
{
public:
	student() = default;
	student(string name, string Id);
	void setName(string name);
	string getName();
	void setId(string ID);
	string getId();
	~student();
	bool operator==(student s);
	bool operator!=(student s);
	friend istream& operator>>(istream& cin, student& c);
	friend ostream& operator<<(ostream& out, student& o);
	student operator=(student s);
	student& operator[](int x);
	string name;
	string ID;
};

