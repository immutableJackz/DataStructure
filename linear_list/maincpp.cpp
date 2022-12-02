#include"List.cpp"
#include"student.h"
#include<algorithm>
using namespace std;
void ForInt();
void ForStudent(); 
int main() {
	//ForInt();
	ForStudent();
}

void ForInt() {
	vector<int> source;
	source.push_back(1);
	source.push_back(2);
	source.push_back(4);
	source.push_back(3);
	Liner<int>* l = new Liner<int>(source);
	l->DispList();
	l->DispList();
	l->ListInsertByLocate(-1, 5);
	l->DispList();
	int i = -1, j = -1;
	l->ListInsertBeByVal(i, 1, 2);
	cout << "插入元素位置：" << i << endl;
	l->DispList();
	l->ListInsertAfByVal(j, 3, 10);
	cout << "插入元素位置：" << j << endl;
	l->DispList();
	int d = -1;
	l->ListDeleteByVal(d, 3);
	cout << "删除元素位置：" << d << endl;
	l->DispList();
	int v;
	bool flag=l->ListDeleteByLocation(2, v);
	if(flag) cout << "删除的元素为：" << v << endl;
	l->DispList();
	l->ListInsertByLocate(2, 2);
	int a = l->LocateElem(5);
	l->DispList();
	cout << "元素位置：" << a << endl;
	int e;
	bool f=l->GetElem(2, e);
	if(f)
		cout << "获取的元素：" << e << endl;
	l->DispList();

	l->UpdateList(2, 100);
	l->DispList();
	delete l;
}

void ForStudent() {
	vector<student> c;
	student s ("xiaoming", "123456");
	student s1("xiaozhou", "4567");
	student s2("xiaohei", "777");
	c.push_back(s);
	c.push_back(s1);
	c.push_back(s2);
    Liner<student> *l=	new Liner<student>(c);	
	l->DispList();
	auto s3 = student("xiaohong", "111");
	l->ListInsertByLocate(2, s3);
	l->DispList();
	int i;
	auto s4 = student("xiaowen", "222");
	l->ListInsertBeByVal(i,s3,s4 );
	l->DispList();
	cout <<"插入元素下标："<< i << endl;
	int j = -1;
	auto s5 = student("xiaobai", "555");
	auto s6 = student("xiaoming", "12345");
	l->ListInsertAfByVal(i,s6 , s5);
	l->DispList();
	if (j != -1)
		cout << "插入元素下标：" << j << endl;
	else
		cout << "无学生信息为：" << s6<< endl;
	int a = -1;
	auto s7 = student("xiaoQ", "4444");
	l->ListDeleteByVal(a, s3);
	if (a == -1)
		cout << "无学生信息为：" << s7 << endl;
	else
		l->DispList();
	student s8;
	bool flag=l->ListDeleteByLocation(4, s8);
	//cout << endl;
	if (flag) cout << s8<<endl;
	student s9;
	bool f=l->GetElem(8, s9);
	if (f)cout << s9<<endl;
	cout<<l->LocateElem(s4)<<endl;
	cout << !l->ListEmpty() << endl;
	cout << l->ListLength() << endl;
	student s10;
	cin >> s10;
	l->UpdateList(2, s10);
	l->DispList();
	delete l;
}