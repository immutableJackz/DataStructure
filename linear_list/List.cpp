#include"student.h"
#include"List.h"
template<class T>
Liner<T>::Liner(vector<T> res)
{
	readsome();
	if(this->ListEmpty())
		InitList(res);

}

template<class T>
Liner<T>::~Liner()
{
	DestroyList();
}

template<class T>
void Liner<T>::ListInsertByLocate(int i, T e)
{
	this->len = this->liner.size();
	if (i < 0 || i >= this->len) {
		cout << "请输入正确的下标" << endl;
		return; 
	}
	this->liner.insert(this->liner.begin() + i, e);
}

template<class T>
void Liner<T>::ListInsertBeByVal(int &i, T e, T v)
{
	this->len = this->liner.size();
	int j;
	for (j = 0; j < this->len; j++)
	{
		if (e == this->liner[j]) {
			i = j;
			this->liner.insert(this->liner.begin() + j, v);
			return;
		}
	}
}

template<class T>
void Liner<T>::ListInsertAfByVal(int &i, T e, T v)
{
	this->len = this->liner.size();
	int j;
	for (j = 0; j < this->len; j++)
	{
		if (e == this->liner[j]) {
			i = j;
			this->liner.insert(this->liner.begin() + j+1, v);
			return;
		}
	}
}

template<class T>
void Liner<T>::ListDeleteByVal(int& i, T e)
{
	this->len = this->liner.size();
	int c = 0;
	for (auto res = this->liner.begin(); res != this->liner.end();c++) {
		if (*res == e) {
			res = this->liner.erase(res);
			i = c;
			break;
		}
		else
			res++;
	}
}
template<class T>

bool Liner<T>::ListDeleteByLocation(int i, T& e)
{
	this->len = this->liner.size();
	int c = 0;
	if (i < 0 || i >= this->len)
	{
		cout << "无效的下标:" << i<<endl;
		return false;
	}
	for (auto res = this->liner.begin(); res != this->liner.end(); c++) {
		if (c==i) {
			e = *res;
			res = this->liner.erase(res);
			break;
		}
		else
			res++;
	}
	return true;
}
template<class T>
void Liner<T>::DispList()
{
	for (auto ll : liner) {
		cout << " "<<ll ;
	}
	cout << endl;
}
template<class T>

bool Liner<T>::GetElem(int i, T& e)
{
	this->len = this->liner.size();
	int c = 0;
	if (i < 0 || i >= this->len)
	{
		cout << "无效的下标:" << i<<endl;
		return false;
	}
	for (auto it = this->liner.begin(); it != this->liner.end();c++,it++) {
		if (i == c) {
			e = *it;
			break;
		}
	}
	return true;
}

template<class T>
int Liner<T>::LocateElem(T e)
{
	this->len = this->liner.size();
	int c = 0;
	for (auto it = this->liner.begin(); it != this->liner.end(); it++) {
		if (e==(*it) ) {
			return c;
		}
		c++;
	}
	return -1;
}
template<class T>

void Liner<T>::UpdateList(int i, T e)
{
	this->len = this->liner.size();
	int c = 0;
	if (i < 0 || i >= len)
		cout << "错误的下标" << i << endl;
	for (auto it = this->liner.begin(); it != this->liner.end(); ++it,c++) {
		if (c == i)
			*it = e;
	}
}
template<class T>

void Liner<T>::DestroyList()
{
	save();
}

template<class T>
bool Liner<T>::ListEmpty()
{
	this->len = this->liner.size();
	return len==0;
}

template<class T>
void Liner<T>::InitList(vector<T> res)
{
	this->liner = res;
	this->len = this->liner.size();
}
template<class T>
int Liner<T>::ListLength()
{
	this->len = this->liner.size();
	return len;
}

template <>
inline bool Liner<student>::save()
{
	this->len = this->liner.size();
	ofstream f;
	f.open("student.txt", ios::out);
	if (f) {
		for (student s : this->liner) {
			f << s.getName() << " " << s.getId()<<endl;
		}
		f.close();
		return true;
	}
	cout << "file open error!" << endl;
	return false;
}
template <>
inline bool Liner<int>::save()
{
	this->len = this->liner.size();
	ofstream f;
	f.open("int.txt", ios::out);
	if (f) {
		for (int s : this->liner) {
			f << s << endl;
		}
		f.close();
		return true;
	}
	cout << "file open error!" << endl;
	return false;
}
template <>
inline bool Liner<student>::readsome()
{
	ifstream f;
	f.open("student.txt", ios::in);
	if (!f.is_open()) {
		this->len = this->liner.size();

		return false;

	}
	f.seekg(0);
	string name, id;
	while (!f.eof())
	{
		f >> name >> id;
	
		if (f.fail())break; //解决eof多读一行的问题
		student s(name, id);
		this->liner.push_back(s);
	}
	f.close();
	this->len = this->liner.size();
	return true;
}
template <>
inline bool Liner<int>::readsome()
{
	ifstream f;
	f.open("int.txt", ios::in);
	if (!f.is_open()) {
		this->len = this->liner.size();
		return false;
	}
	f.seekg(0);
	int x;
	while (!f.eof())
	{
		f >> x;
	
		if (f.fail())break; //解决eof多读一行的问题
		
		this->liner.push_back(x);
	}
	f.close();
	this->len = this->liner.size();
	return true;
}
