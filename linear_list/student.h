#pragma once
#include <string>
#include<iostream>
using namespace std;
class student
{
public:
	student();
	student(string name,string Id);
	void setName(string name);
	string getName();
	void setId(string ID);
	string getId();
	~student();
	bool operator==(student s) {
		if (this->getId() == s.getId() && this->getName() == s.getName())
			return true;
		return false;
	}
	friend istream& operator>>(istream& cin, student& c);
	friend ostream& operator<<(ostream& out, student& o);

	
private:
	string name;
	string ID;
};

