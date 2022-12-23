#pragma once
/*
* 632162010205
* ���ĺ�
*/
#include"headAll.h"
#include"Queue.h"
#include"Node.hpp"
#include"Edges.hpp"
class Graph
{
private:
    int numVertex, numEdge; //����������
    double** matrix;  //�ڽӾ���
    Node* node;//��������
    Edges eg[MAX];//������
    int* mark;  //ָ�������޷��ʸõ������
    string fileName;//�����Ƿ��Լ��������黹�Ǵ��ļ��ж�ȡ
    int flag;//1����ͼ 0����ͼ
    void deleteDouble(double** map);//�ͷŶ�ά����
    void DisplayPath(double *dis, int *path,int* mark,int v,int t);//������Dijkstra����������
    void DisPath(int** path, double** map);//������Floyd����������
    void getEdges();//��ʼ��������
public:
    bool readFile(string fileName);//��ȡ�ļ�
    bool writeFile(string fileName);//д�ļ�
    Graph(int n,string fileName);
    Graph(int n,int flag);
    ~Graph();
    void Init(int n) ; //��ʼ��
    void printMatrix(double **map);//��ӡ�ڽӾ���
    void printMatrix();//��ӡ�ڽӾ���
    void printEdges();//��ӡ������
    int getV();//��ýڵ����
    void setEdge(int from, int to, int wt) ;  //��������֮��ı������Ȩ��
    void delEdge(int v1, int v2) ;  //ɾ������֮��ı�
    double weight(int v1, int v2) ; //ȡȨ��
    void setMark(int v, int val) ; //���б��
    void initMark(); //��ʼ���������
public:
    //����У԰��ͼ
    void Floyd();//�������֮�������·��
    void initNodeInfo(string fileName);//���ļ��ж�ȡУ԰�ڵ���Ϣ�� �ڵ�����
    void Dijkstra(int v,int t);//�������֮�����·��
    string GetNodeInfo(int n);//��ȡ���n ������
    void dbInfo(int from, int to);//�������·��֮�����ʽ
    void addNode(string NodeName);//��ӽ��
    void saveNode(string fileName);//����������
    void deleteNode(int v);//ɾ�����
    //�ֿ�
    void RouteSome();//�涨һЩ;���� �����·�� 
    void initPath();//����Path����
    void dfs(int u); //���·������
    void FindPath(int *match,int n);//�������һЩ�������·�� ���뾭��һЩ��
    void lessNumPath();//������������� ��·��
    void AllPath();//���ȫ��·��
};

