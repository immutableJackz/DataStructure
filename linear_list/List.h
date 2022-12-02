#pragma once
#include<iostream>
using namespace std;
#include<vector>
#include <fstream>
template<class T>
class Liner
{
public:
	Liner(vector<T> res);
	~Liner();
	void ListInsertByLocate(int i, T e);//ָ��λ�ò���
	void ListInsertBeByVal(int &i, T e,T v);//ָ��Ԫ�ص�ǰ��,�����±�
	void ListInsertAfByVal(int &i, T e, T v);//ָ��Ԫ�صĺ��,�����±�

	void ListDeleteByVal(int& i, T e);//ͨ��ָ����ֵɾ���������±ꡢ��ֻɾ����һ��(ֻɾ����һ�����ϵ�)
	bool ListDeleteByLocation(int i, T& e);//ͨ��ָ��λ��ɾ������������ֵ

	void DispList();//��ʾ����

	bool GetElem(int i, T& e);//ͨ���±��������

	int LocateElem(T e);//��λ�������±ꡢֻ���ص�һ�����ϵ��±�

	void UpdateList(int i, T e);//����ָ���±������

	bool ListEmpty();//�п�
	int ListLength();//���ر�ĳ���

	bool save();//�����ļ�,ר�Ŵ���student��

	bool readsome();

private:
	void InitList(vector<T> res);//��ʼ����
	void DestroyList();//�ݻٱ�

private:
	vector<T> liner;
	int len;//��ĳ���
};


