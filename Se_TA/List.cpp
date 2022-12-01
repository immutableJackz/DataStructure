#include "List.h"
#include<math.h>
#include <fstream>

template<typename T>
List<T>::List(T* arr, int s)
{
    Init_Sqlist();
    readsome();
    if (this->Empty())
        this->Init_Sqlist(arr, s);
    else
        cout << "�ļ��к���Ԫ��" << endl;
}

template <typename T>

bool List<T>::Init_Sqlist() {
    this->elem = new T[INIT_SIZE];
    if (!this->elem) {
        cerr << "Init Wrong!" << endl;
        return false;
    }
    this->size = INIT_SIZE;
    this->length = 0;
    return true;

}
template <typename T>
inline bool List<T>::Init_Sqlist(T*arr,int s) {
    this->elem = new T[INIT_SIZE];
    if (!this->elem) {
        cerr << "Init Wrong!" << endl;
        return false;
    }
    this->size = INIT_SIZE;
    this->length = s;
    for (int i = 0; i < this->length; ++i) {
        this->elem[i] = arr[i];
    }
    return true;
}
//��������֮int
template<>
inline void List<int>::quick_sort(int l,int r)
{
    if (l < r)
    {
        int i = l, j = r, x = this->elem[l];
        while (i < j)
        {
            while (i < j && this->elem[j] >= x) // ���������ҵ�һ��С��x����
                j--;
            if (i < j)
                this->elem[i++] = this->elem[j];

            while (i < j && this->elem[i] < x) // ���������ҵ�һ�����ڵ���x����
                i++;
            if (i < j)
                this->elem[j--] = this->elem[i];
        }
        this->elem[i] = x;
        quick_sort( l, i - 1); // �ݹ���� 
        quick_sort( i + 1, r);
    }
}
//long ת string 
template<typename T>
string List<T>::longTOstring(long l)
{
    ostringstream os;
    os << l;
    string result;
    istringstream is(os.str());
    is >> result;
    return result;

}
//string תlong
template<typename T>
long List<T>::stringTOlong(string str)
{
    int sum = 0;
    for (int i = 0; i < str.length(); ++i) {
        sum += (str.at(i)-'0') * pow(10, i);
    }
    return sum;
}
//��������֮student
template<>
inline void List<student>::quick_sort(int l,int r)
{
    if (l < r)
    {
        int i = l, j = r;
        student x = this->elem[l];
        while (i < j)
        {
            // ���������ҵ�һ��С��x����
            while (i < j && stringTOlong( this->elem[j].getId()) >= stringTOlong(x.getId())) 
                j--;
            if (i < j)
                this->elem[i++] = this->elem[j];
            // ���������ҵ�һ�����ڵ���x����
            while (i < j && stringTOlong(this->elem[i].getId()) < stringTOlong(x.getId())) 
                i++;
            if (i < j)
                this->elem[j--] = this->elem[i];
        }
        this->elem[i] = x;
        quick_sort( l, i - 1); // �ݹ���� 
        quick_sort( i + 1, r);
    }
    
}

template <typename T>
inline int List<T>::GetSize() {
    return this->size;
}

template <typename T>
inline int List<T>::Getlen() {
    return this->length;
}

template <typename T>
inline void List<T>::Clear() {
    this->length = 0;
}

template <typename T>
inline bool List<T>::Empty() {
    if (this->length == 0) {
        return true;
    }
    return false;
}
// ���ڻ�ȡ��Ӧ�±�� Ԫ��
template <typename T>
bool List<T>::Getindex(int idx, T& elem) {
    if (idx < 1 || idx > this->length) {
        return false;
    }
    elem = this->elem[idx - 1];
    return true;
}
// �����ȡ ��һ�� ����Ԫ�ص� λ�� 
template <typename T>
int List<T>::Getindex(T elem, bool (*compare)(T, T)) {
    for (int i = 0; i != this->length; i++) {
        if (compare(elem, (this->elem)[i])) {
            return i;
        }
    }
    return -1;
}

template<typename T>
bool List<T>::updateList(T elem, T val)//elem :����Ԫ�� val:����Ԫ��
{
    int i = 0;
    while (i < this->length) {
        if (val == this->elem[i]) {
            break;
        }
        i++;
    }
    if (i == this->length && val != this->elem[i]) {
        cout << "���µ�Ԫ�ز�����" << endl;
        return false;
    }
    this->elem[i] = elem;
    return true;
}
// ���ڲ��ú���ָ��ķ�ʽ��ӡ˳����е�Ԫ�أ���print�д�ӡһ��Ԫ��
template <typename T>
void List<T>::traverse(void (*print)(T& elem)) {
    for (int i = 0; i != this->length; i++) {
        /* code */
        print((this->elem)[i]);
    }
    cout << endl;
}

// ������˳���  ָ����Ԫ��  ǰ  ���Ԫ�� 
template<typename T>
bool List<T>::insertBfVal(T val, T elem)
{
    int idx = 0;
    if (this->length == this->size) {
        T* newelem = (T*)realloc(this->elem, (this->size + EXPANSIONSIZE) * sizeof(T));
        if (!newelem) {
            cerr << "Error allocating memory!" << endl;
            return false;
        }
        this->size += EXPANSIONSIZE;
        this->elem = newelem;
    }
    for (int j = 0; j < this->length; j++) {
        if (val == this->elem[j]) {
            idx++;
            break;
        }
        idx++;
    }
    if (val != this->elem[idx-1])
    {
        cout << "����Ԫ�ز�����" << endl;
        return false;
    }
    for (int i = this->length; i >= idx; i--) {
        (this->elem)[i] = (this->elem)[i - 1];
    }
    (this->elem)[idx - 1] = elem;
    this->length += 1;
    return true;
}
// ������˳���  ָ����Ԫ��  ��  ���Ԫ�� 
template<typename T>
bool List<T>::insertAfVal(T val, T elem)
{
    int idx = 0;
    if (this->length == this->size) {
        T* newelem = (T*)realloc(this->elem, (this->size + EXPANSIONSIZE) * sizeof(T));
        if (!newelem) {
            cerr << "Error allocating memory!" << endl;
            return false;
        }
        this->size += EXPANSIONSIZE;
        this->elem = newelem;
    }
    for (int j = 0; j < this->length; j++) {
        if (val == this->elem[j]) {
            idx++;
            break;
        }
        idx++;
    }
    if (val != this->elem[idx-1])
    {
        cout << "����Ԫ�ز�����" << endl;
        return false;
    }
    for (int i = this->length; i >= idx+1; i--) {//�ƶ�ָ��Ԫ�غ��Ԫ��
        (this->elem)[i] = (this->elem)[i - 1];
    }
    (this->elem)[idx] = elem;//��ָ��Ԫ�غ����Ԫ��
    this->length += 1;
    return true;
}
//������˳���  ָ����λ��  ���Ԫ��
template <typename T>
bool List<T>::insertByLoct(int idx, T elem) {
    if (idx < 1 || idx > this->length + 1) {
        cout << "��������" << endl;
        return false;
    }
    if (this->length == this->size) {
        T* newelem = (T*)realloc(this->elem, (this->size + EXPANSIONSIZE) * sizeof(T));
        if (!newelem) {
            cerr << "Error allocating memory!" << endl;
            return false;
        }
        this->size += EXPANSIONSIZE;
        this->elem = newelem;
    }
    for (int i = this->length; i >= idx; i--) {
        (this->elem)[i] = (this->elem)[i - 1];
    }
    (this->elem)[idx - 1] = elem;
    this->length += 1;
    return true;
}


// ������˳����   ָ��λ��  ɾ��Ԫ�� ��ͨ�����õķ�ʽ���ظ�Ԫ�ص�ֵ
template <typename T>
bool List<T>::removeByloct(int idx, T& elem) {
    if (this->length == 0) {
        return false;
    }
    if (idx < 1 || idx > this->length) {
        cout << "�����±�����" << endl;
        return false;
    }
    elem = (this->elem)[idx - 1];
    for (int i = idx - 1; i < this->length - 1; i++) {
        (this->elem)[i] = (this->elem)[i + 1];
    }
    this->length--;

    return true;
}
// ����ɾ��ָ��Ԫ�� ��ͨ�����õķ�ʽ���ظ�Ԫ�ص��±� 
template<typename T>
bool List<T>::removeByVal(int &idx, T  elem)
{
    int i=0;
    while (i < this->length) {
        if (elem == this->elem[i]) {
            idx = i;
            break;
        }
        i++;
    }
    if (i == this->length && elem != this->elem[i]) {
        cout << "���ҵ�Ԫ�ز�����" << endl;
        return false;
    }
    for (int j = i; j < this->length-1; j++)
        this->elem[j] = this->elem[j + 1];
    this->length -= 1;
    return true;
}

template <typename T>
T List<T>::operator[](int idx) {
    if (idx < 1 || idx > this->length) {
        cerr << "subscript wrong!" << endl;

    }
    return this->elem[idx - 1];
}
template <typename T>
bool List<T>::push_back(T elem) {
    if (this->length == this->size) {
        T* newelem = (T*)realloc(this->elem, (this->size + EXPANSIONSIZE) * sizeof(T));
        if (!newelem) {
            cerr << "Error allocating memory!" << endl;
            return false;
        }
        this->size += EXPANSIONSIZE;
        this->elem = newelem;
    }
    (this->elem)[this->length] = elem;
    this->length += 1;
    return true;
}

template <typename T>
List<T>::~List() {
    /*free(this->elem);
    this->elem = nullptr;
    this->size = 0;
    this->length = 0;*/
    save();
}



/*
    ����ʵ�ַǳ�Ա�����Ķ���
 */
template <typename T>
void print(T& elem) {
    cout << elem << " ";
}

template <typename T>
bool compare(T t1, T t2) {
    /* ����T������������� */
    if (t1 == t2) {
        return true;
    }
    return false;
}
//�����ļ�,ʹ��ģ��������
template <>
inline bool List<student>::save()
{
    ofstream f;
    f.open("student.txt", ios::out);
    if (f) {
        for (int i = 0; i < this->length; ++i) {
            f << this->elem[i].getName() << " " << this->elem[i].getId() << endl;
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
    if (f) {
        for (int i = 0; i < this->length; ++i) {
            f << this->elem[i] << endl;
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
