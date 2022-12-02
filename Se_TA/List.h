#pragma once
#define INIT_SIZE 100
#define EXPANSIONSIZE 20
#include<iostream>
#include"Student.h"
#include <sstream>
using namespace std;
template <typename T>
class List {
private:
	T* elem; // �洢�ռ��ַ
	int size; // ��ǰ˳���Ĵ洢����
	int length; // ��ǰ˳���ĳ���
public:
	List() = default;//Ĭ�Ϲ���
	List(T *arr,int s); //���캯��
	bool Init_Sqlist(); // ��ʼ��˳�����Ҫ�ǿ��ٿռ䣬��ʼ������������赱ǰ����Ϊ0
	bool Init_Sqlist(T* arr, int s); // ��ʼ��˳���,��������,�ͳ��ȣ���Ҫ���ڴ��ļ�δ�ܶ�ȡ����ʱ����ʼ��˳���
	//����
	bool insertBfVal(T val, T elem); // ������˳���  ָ����Ԫ��  ǰ  ���Ԫ�� 
	bool insertAfVal(T val, T elem); // ������˳���  ָ����Ԫ��  ��  ���Ԫ�� 
	bool insertByLoct(int idx, T elem); //������˳���  ָ����λ��  ���Ԫ�� 
	bool push_back(T elem); // ������˳����  ���  ���Ԫ�� 
	//ɾ��
	bool removeByloct(int idx, T& elem); // ������˳����   ָ��λ��  ɾ��Ԫ�� ��ͨ�����õķ�ʽ���ظ�Ԫ�ص�ֵ
	bool removeByVal(int& idx, T elem); // ����ɾ��ָ��Ԫ�� ��ͨ�����õķ�ʽ���ظ�Ԫ�ص��±� 
	//��ʾ����
	void traverse(void (*print)(T& elem)); // ���ڲ��ú���ָ��ķ�ʽ��ӡ˳����е�Ԫ�أ���print�д�ӡһ��Ԫ��
	//��λ
	bool Getindex(int idx, T& elem); // ���ڻ�ȡ��Ӧ�±�� Ԫ��
	int Getindex(T elem, bool (*compare)(T, T)); // �����ȡ ��һ�� ����Ԫ�ص� λ�� 
	//����
	bool updateList(T elem, T val);//elem :���� �ȶ�Ԫ�� val:�����Ԫ��
	//�ļ��Ķ�д����
	bool save();//�����ļ�,ʹ��ģ��������
	bool readsome();//��ȡ�ļ���������������ָ���У�ʹ��ģ��������

	//����
	void quick_sort(int l,int r);//��������֮��������
	long stringTOlong(string str);//string תlong
	string longTOstring(long x);//long ת string 

	int GetSize(); // ��ȡ˳���Ĵ洢����
	int Getlen(); // ��ȡ˳���ĳ���
	void Clear(); // ����˳���
	bool Empty(); //�жϱ��Ƿ�Ϊ��




	


	T operator[](int idx); // �����±������
	~List(); // ��д˳������������

};



