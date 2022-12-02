#include "student.h"

student::student()
{
}

student::student(string name, string Id)
{
    this->ID = Id;
    this->name = name;
}

void student::setName(string name)
{
    this->name = name;
}

string student::getName()
{
    return name;
}

void student::setId(string ID)
{
    this->ID = ID;
}

string student::getId()
{
    return ID;
}

student::~student()
{

}

istream& operator>>(istream& in, student& c)
{
    cout << "请输入姓名与id:";
    in >> c.name >> c.ID;
    return cin;
}

ostream& operator<<(ostream& out, student& o)
{
    out << "姓名：" << o.getName()<<"\t" << "学号：" << o.getId() << endl;
    return out;
}
