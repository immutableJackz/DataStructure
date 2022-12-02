#include"List.h"
#include"List.cpp"
#include"Student.h"
#include"Node.h"
void Forint() {
	int arr[4] = { 0,5,2,3 };
	List<int> l(arr, 4);
	l.Printall();
	if(l.insertBfVal(2, 8))
		l.Printall();
	if(l.insertAfVal(7, 11))
		l.Printall();
	if(l.insertByLoct(7, 15))
		l.Printall();
	if (l.push_back(105))
		l.Printall();
	int a, i;
	if (l.removeByloct(7, a))
	{
		cout << "被删除的元素为：" << a << endl;
		l.Printall();
	}
	if (l.removeByVal(i, 105)) {
		cout << "被删除的元素为第" << i<<"个" << endl;
		l.Printall();
	}
	i = l.Getindex(100);
	if (i != -1){
		cout << "该元素的位置为第" << i << "个" << endl;
	}
	if (l.updateList(15, 222)) {
		l.Printall();
	}
	l.reverseList();
	l.Printall();
}
void ForStudent() {
	student s1("xiaoming", "1111");
	student s2("xiaohu", "7777");
	student s3("xiaohei", "5555");
	student s4("awei", "6666");
	student s5("xiaohong", "8888");
	student s6("xiaolong", "2222");
	student s7("xiaohao", "3333");
	student s8("xiaofei", "0000");
	student s9;
	student arr[3] = {s1,s2,s3};
	List<student> l(arr, 3);
	l.Printall();
	if(l.insertBfVal(s2, s4))
		l.Printall();
	if(l.insertAfVal(s1, s5))
		l.Printall();
	if(l.insertByLoct(5, s6))
		l.Printall();
	if (l.push_back(s6))
		l.Printall();
	int i;
	if (l.removeByloct(7, s9))
	{
		cout << "被删除的元素为：" << s9 << endl;
		l.Printall();
	}
	if (l.removeByVal(i, s2)) {
		cout << "被删除的元素为第：" << i << "个" << endl;
		l.Printall();
	}
	i = l.Getindex(s7);
	if (i != -1) {
		cout << "该元素的位置为第" << i << "个" << endl;
	}
	if (l.updateList(s5, s6)) {
		l.Printall();
	}
	l.reverseList();
	l.Printall();
}
int main() {
	//Forint();
	ForStudent();
	/*string c;*/
	/*c += to_string(1);
	cout << c;*/
}