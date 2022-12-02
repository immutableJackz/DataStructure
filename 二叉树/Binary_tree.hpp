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
	Binary_tree(T* a, int n);//按数组初始化二叉树
    Binary_tree(Binary_tree<T>& bt);//拷贝构造函数
    void getLevel(Node<T>*p);//计算节点所在层次
    void getNodeNum();//结点数量
    void getYeNodeNum();//叶结点数量
    void getHeight(); //求二叉树高度
    void getNodeDu(Node<T>* p);//求二叉树的度 出度和入度
    void getParent(Node<T>* p);//求双亲
    void getChild(Node<T>* p);//求子女

    void preOrder();///前序遍历二叉树
    void inOrder();///中序遍历二叉树
    void postOrder();///后序遍历二叉树(递归方法)
    void preOrder1();///前序遍历二叉树(使用栈的非递归方法)
    void inOrder1();///中序遍历二叉树(使用栈的非递归方法)
    void postOrder1();///后序遍历二叉树(使用栈的非递归方法)
    void levelOrder();///层序遍历二叉树
    void TreePrint();//输出树形结构
    void Exchage();//交换左右子树
    void co_b_tree();//是否为完全二叉树
private:
	void CreateBiTree(Node<T> *&root,T* a, int n,int &i);
    int get_Level(Node<T>* t, Node<T>* p);//p 查找元素
    void get_YeNodeNum(Node<T>* t,int &num);
    int get_height(Node<T>* t);
    void get_NodeDu(Node<T>* t,Node<T>*p, int &cd, int &rd);//cd出度 rd入度
    //par 双亲 biaoji 是左孩子还是右孩子 左1右0
    void get_parent(Node<T>* t, Node<T>* p, Node<T>*& par, int &biaoji);
    void get_child(Node<T>* t, Node<T>* p, Node<T>*& lchild, Node<T>*& rchild );
    void pre_Order(Node<T>* t);
    void in_Order(Node<T>* t);
    void post_Order(Node<T>* t);
    void copy(Node<T>*& new_root, Node<T>* src);//复制函数
    void Tree_Print(Node<T>* T, int arr[100][3], int& i, int level);
    void sort_arr(int arr[100][3],int i);
    void Exchagechild(Node<T>* root);
    bool isCo_b_tree(Node<T>* root);//是否为完全二叉树
private:
	Node<T>* root;//根节点
	int cnt;//节点数目
};

