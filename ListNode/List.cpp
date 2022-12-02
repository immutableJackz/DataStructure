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
        cout << "�Ѵ��ļ��ж�ȡ��������" << endl;
}

template <typename T>
bool List<T>::Init_Sqlist() {
    head = new Node<T>();
    this->size = 0;
    tail = head;
    if (!head)
    {
        cout << "�ڴ����ʧ��";
        return false;
    }
    return true;
}
template <typename T>
inline bool List<T>::Init_Sqlist(T* arr, int s) {
    head = new Node<T>();
    tail = head;
    if (!head) {
        cout << "�ڴ����ʧ��" << endl;
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
    tail = head->next;//ȷ��βָ��
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

// �����ȡ ��һ�� ����Ԫ�ص� λ�� 
template <typename T>
int List<T>::Getindex(T val) {
    Node<T>* p = head->next;
    int n = 1;
    while (p)
    {
        if (p->val == val) {
            cout << "�ҵ���Ԫ��" << endl;
            return n;
        }
        p = p->next;
        n++;
    }
    cout << "û�и�Ԫ�ش���" << endl;
    return -1;
}

template<typename T>
bool List<T>::updateList(T elem, T val)//elem :����Ԫ�� val:����Ԫ��
{//���¹���
    Node<T>* p = head->next;
    while (p)
    {
        if (p->val == elem) {
            p->val = val;
            return true;
        }
        p = p->next;
    }
    cout << "û�и�Ԫ�ش���" << endl;
    return false;
}
template <typename T>
void List<T>::Printall() {//��ӡ����
    Node<T>* p = head->next;
    while (p)
    {
        cout << p->val << " ";
        p = p->next;
    }
    cout << endl;
    cout << "������Ԫ�ظ���Ϊ��" << this->size << endl;
    cout <<"βָ����ָ�ģ�"<< tail->val << endl;
    cout << endl;
}

// ����������  ָ����Ԫ��  ǰ  ���Ԫ�� 
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
        cout << "ǰ��ɹ�" << endl;
        this->size++;

        return true;
    }
    cout << "�����ڸ�Ԫ��" << endl;
    return false;
        
}
// ����������  ָ����Ԫ��  ��  ���Ԫ�� 
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
        cout << "���ɹ�" << endl;
        this->size++;
        if(!s->next)
            tail = s;
        return true;
    }
    cout << "�����ڸ�Ԫ��" << endl;
    return false;
}
//����������  ָ����λ��  ���Ԫ��
template <typename T>
bool List<T>::insertByLoct(int idx, T elem) {
    if (idx<1 || idx>this->size+1) {
        cout << "����λ������" << endl;
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
    cout << "��λ�ò���ɹ�" << endl;
    this->size++;
    return true;
}
//β�巨
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


// �����������   ָ��λ��  ɾ��Ԫ�� ��ͨ�����õķ�ʽ���ظ�Ԫ�ص�ֵ
template <typename T>
bool List<T>::removeByloct(int idx, T& elem) {
    if (idx<1 || idx>this->size)
    {
        cout << "�����±�����" << endl;
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
// ����ɾ��ָ��Ԫ�� ��ͨ�����õķ�ʽ���ظ�Ԫ�ص��±� 
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
    cout << "Ҫɾ����Ԫ�ز�����" << endl;
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



//�����ļ�,ʹ��ģ��������
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
//��ȡ�ļ���������������ָ���У�ʹ��ģ��������
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
        if (f.fail())break; //���eof���һ�е�����
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
        if (f.fail())break; //���eof���һ�е�����
        push_back(x);
    }
    f.close();
    return true;
}
