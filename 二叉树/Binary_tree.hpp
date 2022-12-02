#pragma once
#include"Node.hpp"
#include"Stack.hpp"
#include"Stack.cpp"
#include"Queue.h"
#include"Queue.cpp"
#include<iostream>
using namespace std;
template<class T>
class Binary_tree
{
public:
	Binary_tree() :root(NULL), cnt(0){};
	Binary_tree(T* a, int n);//�������ʼ��������
    Binary_tree(Binary_tree<T>& bt);//�������캯��
    void getLevel(Node<T>*p);//����ڵ����ڲ��
    void getNodeNum();//�������
    void getYeNodeNum();//Ҷ�������
    void getHeight(); //��������߶�
    void getNodeDu(Node<T>* p);//��������Ķ� ���Ⱥ����
    void getParent(Node<T>* p);//��˫��
    void getChild(Node<T>* p);//����Ů

    void preOrder();///ǰ�����������
    void inOrder();///�������������
    void postOrder();///�������������(�ݹ鷽��)
    void preOrder1();///ǰ�����������(ʹ��ջ�ķǵݹ鷽��)
    void inOrder1();///�������������(ʹ��ջ�ķǵݹ鷽��)
    void postOrder1();///�������������(ʹ��ջ�ķǵݹ鷽��)
    void levelOrder();///�������������
    void TreePrint();//������νṹ
    void Exchage();//������������
    void co_b_tree();//�Ƿ�Ϊ��ȫ������
private:
	void CreateBiTree(Node<T> *&root,T* a, int n,int &i);
    int get_Level(Node<T>* t, Node<T>* p);//p ����Ԫ��
    void get_YeNodeNum(Node<T>* t,int &num);
    int get_height(Node<T>* t);
    void get_NodeDu(Node<T>* t,Node<T>*p, int &cd, int &rd);//cd���� rd���
    //par ˫�� biaoji �����ӻ����Һ��� ��1��0
    void get_parent(Node<T>* t, Node<T>* p, Node<T>*& par, int &biaoji);
    void get_child(Node<T>* t, Node<T>* p, Node<T>*& lchild, Node<T>*& rchild );
    void pre_Order(Node<T>* t);
    void in_Order(Node<T>* t);
    void post_Order(Node<T>* t);
    void copy(Node<T>*& new_root, Node<T>* src);//���ƺ���
    void Tree_Print(Node<T>* T, int arr[100][3], int& i, int level);
    void sort_arr(int arr[100][3],int i);
    void Exchagechild(Node<T>* root);
    bool isCo_b_tree(Node<T>* root);//�Ƿ�Ϊ��ȫ������
private:
	Node<T>* root;//���ڵ�
	int cnt;//�ڵ���Ŀ
};

