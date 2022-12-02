#pragma once
#define INIT_SIZE 100
#define EXPANSIONSIZE 20
#include<iostream>
#include"Student.h"
#include"Node.h"
#include <sstream>
using namespace std;
template <typename T>
class List
{
private:
	Node<T>* head;
	Node<T>* tail;
	int size; // ��ǰ��Ĵ�С
public:
	List()=default;//Ĭ�Ϲ���
	List(T* arr,int s);//�����鹹��
	bool Init_Sqlist(); // ��ʼ��������Ҫ�ǿ��ٿռ䣬��ʼ������������赱ǰ����Ϊ0
	bool Init_Sqlist(T * arr, int s); // ��ʼ������,��������,�ͳ��ȣ���Ҫ���ڴ��ļ�δ�ܶ�ȡ����ʱ����ʼ������
	//����
	bool insertBfVal(T val, T elem); // ����������  ָ����Ԫ��  ǰ  ���Ԫ�� 
	bool insertAfVal(T val, T elem); // ����������  ָ����Ԫ��  ��  ���Ԫ�� 
	bool insertByLoct(int idx, T elem); //����������  ָ����λ��  ���Ԫ�� 
	bool push_back(T val); // �����������  ���  ���Ԫ�� 
	//ɾ��
	bool removeByloct(int idx, T & elem); // �����������   ָ��λ��  ɾ��Ԫ�� ��ͨ�����õķ�ʽ���ظ�Ԫ�ص�ֵ
	bool removeByVal(int& idx, T elem); // ����ɾ��ָ��Ԫ�� ��ͨ�����õķ�ʽ���ظ�Ԫ�ص��±� 
	//��ʾ����
	void Printall(); // ������ӡÿ���ڵ��Ԫ��
	//��λ
	int Getindex(T val); // �����ȡ ��һ�� ����Ԫ�ص� λ�� 
	//����
	bool updateList(T elem, T val);//elem :���� �ȶ�Ԫ�� val:�����Ԫ��
	//�ļ��Ķ�д����
	bool save();//�����ļ�,ʹ��ģ��������
	bool readsome();//��ȡ�ļ���������������ָ���У�ʹ��ģ��������

	//��ת����
	void reverseList();//�����ķ�ʽ��ת����

	int GetSize(); // ��ȡ����Ĵ洢����
	bool Empty(); //�жϱ��Ƿ�Ϊ��

	~List(); // ��д�������������
};


