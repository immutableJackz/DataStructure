#include "List.h"
#include<math.h>
#include <fstream>


template<typename T>
List<T>::List(T* arr, int s)
{
    Init_Sqlist();
    readsome();
    if (Empty())
        Init_Sqlist(arr, s);
    else
        cout << "已从文件中读取到了数据" << endl;
}

template <typename T>
bool List<T>::Init_Sqlist() {
    head = new Node<T>();
    this->size = 0;
    tail = head;
    if (!head)
    {
        cout << "内存分配失败";
        return false;
    }
    return true;
}
template <typename T>
inline bool List<T>::Init_Sqlist(T* arr, int s) {
    head = new Node<T>();
    tail = head;
    if (!head) {
        cout << "内存分配失败" << endl;
        return false;
    }
    for (int i = 0; i < s; i++) {
        push_back(arr[i]);
    }
    return true;
}

template<typename T>
void List<T>::reverseList()
{
    Node<T>* prev = head;
    tail = head->next;//确定尾指针
    Node<T>* cur = this->head->next;
    while (cur)
    {
        Node<T>* next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    this->head = new Node<T>();
    this->head->next = prev;
    tail->next = nullptr;
}

template <typename T>
inline int List<T>::GetSize() {
    return this->size;
}

template <typename T>
inline bool List<T>::Empty() {
    return this->size == 0;
}

// 用与获取 第一个 相似元素的 位置 
template <typename T>
int List<T>::Getindex(T val) {
    Node<T>* p = head->next;
    int n = 1;
    while (p)
    {
        if (p->val == val) {
            cout << "找到该元素" << endl;
            return n;
        }
        p = p->next;
        n++;
    }
    cout << "没有该元素存在" << endl;
    return -1;
}

template<typename T>
bool List<T>::updateList(T elem, T val)//elem :传入元素 val:更改元素
{//更新功能
    Node<T>* p = head->next;
    while (p)
    {
        if (p->val == elem) {
            p->val = val;
            return true;
        }
        p = p->next;
    }
    cout << "没有该元素存在" << endl;
    return false;
}
template <typename T>
void List<T>::Printall() {//打印操作
    Node<T>* p = head->next;
    while (p)
    {
        cout << p->val << " ";
        p = p->next;
    }
    cout << endl;
    cout << "链表中元素个数为：" << this->size << endl;
    cout <<"尾指针所指的："<< tail->val << endl;
    cout << endl;
}

// 用与在链表  指定的元素  前  添加元素 
template<typename T>
bool List<T>::insertBfVal(T val, T elem)
{
    Node<T>* pre = head,* p = pre->next;
    bool flag = false;
    while (p)
    {
        if (p->val == val) {
            flag = true;
            break;
        }
        pre = p;
        p = p->next;
    }
    if (flag)
    {
        Node<T>* s = new Node<T>(elem);
        s->next = p;
        pre->next = s;
        cout << "前插成功" << endl;
        this->size++;

        return true;
    }
    cout << "不存在该元素" << endl;
    return false;
        
}
// 用与在链表  指定的元素  后  添加元素 
template<typename T>
bool List<T>::insertAfVal(T val, T elem)
{
    Node<T> * p = head->next;
    bool flag = false;
    while (p)
    {
        if (p->val == val) {
            flag = true;
            break;
        }
        p = p->next;
    }
    if (flag)
    {
        Node<T>* s = new Node<T>(elem);
        s->next = p->next;
        p->next = s;
        cout << "后插成功" << endl;
        this->size++;
        if(!s->next)
            tail = s;
        return true;
    }
    cout << "不存在该元素" << endl;
    return false;
}
//用与在链表  指定的位置  添加元素
template <typename T>
bool List<T>::insertByLoct(int idx, T elem) {
    if (idx<1 || idx>this->size+1) {
        cout << "插入位置有误" << endl;
        return false;
    }
    Node<T>* p = head->next,*pre=head;
    int i = 1;
    while (p)
    {
        if (i == idx)
            break;
        pre = p;
        p = p->next;
        i++;
    }
    if (i == this->size+1) {
        push_back(elem);
        return true;
    }
    Node<T>* s = new Node<T>(elem);
    s->next = p;
    pre->next = s;
    cout << "按位置插入成功" << endl;
    this->size++;
    return true;
}
//尾插法
template<typename T>
bool List<T>::push_back(T val)
{
    Node<T>* s = new Node<T>(val);
    if (!s)
        return false;
    tail->next = s;
    tail = tail->next;
    this->size++;
    return true;
}


// 用于在链表的   指定位置  删除元素 并通过引用的方式返回该元素的值
template <typename T>
bool List<T>::removeByloct(int idx, T& elem) {
    if (idx<1 || idx>this->size)
    {
        cout << "传入下标有误" << endl;
        return false;
    }
    Node<T>* p = head->next,*pre=head;
    int i = 1;
    while (p) {
        if (i == idx) {
            break;
        }
        pre = p;
        p = p->next;
        i++;
    }
    if (i == this->size)
        tail = pre;
    pre->next = p->next;
    elem = p->val;
    delete p;
    p = nullptr;
    this->size--;
    return true;
}
// 用于删除指定元素 并通过引用的方式返回该元素的下标 
template<typename T>
bool List<T>::removeByVal(int& idx, T  elem)
{
    Node<T>* p = head->next, * pre = head;
    int i = 1;
    bool flag = false;
    while (p) {
        if (p->val == elem) {
            flag = true;
            break;
        }
        pre = p;
        p = p->next;
        i++;
    }
    if (flag) {
        pre->next = p->next;
        idx = i;
        if (i == this->size)
            tail = pre;
        delete p;
        p = nullptr;
        this->size--;
        return true;
    }
    cout << "要删除的元素不存在" << endl;
    delete p;
    p = nullptr;
    return false;
}

template <typename T>
List<T>::~List() {
    save();
    Node<T>* currentNode = head;
    while (currentNode != NULL)
    {
        Node<T>* temp = currentNode->next;
        delete currentNode;
        currentNode = temp;
    }
}



//保存文件,使用模板特例化
template <>
inline bool List<student>::save()
{
    ofstream f;
    f.open("student.txt", ios::out);
    Node<student>* p = head->next;
    if (f) {
        while(p) {
            f << p->val.getName() << " " << p->val.getId() << endl;
            p = p->next;
        }
        f.close();
        return true;
    }
    cout << "file open error!" << endl;
    return false;

}
template <>
inline bool List<int>::save()
{
    ofstream f;
    f.open("int.txt", ios::out);
    Node<int>* p = head->next;
    if (f) {
        while(p) {
            f << p->val << endl;
            p = p->next;
        }
        f.close();
        return true;
    }
    cout << "file open error!" << endl;
    return false;
}
//读取文件内容至该类数据指针中，使用模板特例化
template <>
inline bool List<student>::readsome()
{
    ifstream f;
    f.open("student.txt", ios::in);
    if (!f.is_open()) {
        return false;
    }
    f.seekg(0);
    string name, id;
    while (!f.eof())
    {
        f >> name >> id;
        if (f.fail())break; //解决eof多读一行的问题
        student s(name, id);
        push_back(s);
    }
    f.close();
    return true;
}
template <>
inline bool List<int>::readsome()
{
    ifstream f;
    f.open("int.txt", ios::in);
    if (!f.is_open()) {
        return false;
    }
    f.seekg(0);
    int x;
    while (!f.eof())
    {
        f >> x;
        if (f.fail())break; //解决eof多读一行的问题
        push_back(x);
    }
    f.close();
    return true;
}
