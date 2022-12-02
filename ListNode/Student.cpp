#include "Student.h"

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



bool student::operator==(student s)
{
    if (this->getId() == s.getId() && this->getName() == s.getName())
        return true;
    return false;
}

bool student::operator!=(student s)
{
    if (this->getId() != s.getId() || this->getName() != s.getName())
        return true;
    return false;
}

student student::operator=(student s)
{
    this->setName(s.getName());
    this->setId(s.getId());
    return *this;
}

student& student::operator[](int x)
{
    return *this;
}

istream& operator>>(istream& in, student& c)
{
    cout << "������������id:";
    in >> c.name >> c.ID;
    return cin;
}

ostream& operator<<(ostream& out, student& o)
{
    out << "������" << o.getName() << "  " << "ѧ�ţ�" << o.getId();
    return out;
}













student::~student()
{

}