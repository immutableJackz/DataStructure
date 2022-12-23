#pragma once
/*
* 632162010205
* 周文浩
*/
#include"headAll.h"
#include"Queue.h"
#include"Node.hpp"
#include"Edges.hpp"
class Graph
{
private:
    int numVertex, numEdge; //点数、边数
    double** matrix;  //邻接矩阵
    Node* node;//顶点数组
    Edges eg[MAX];//边数组
    int* mark;  //指向存放有无访问该点的数组
    string fileName;//区分是否自己创建数组还是从文件中读取
    int flag;//1无向图 0有向图
    void deleteDouble(double** map);//释放二维数组
    void DisplayPath(double *dis, int *path,int* mark,int v,int t);//适用于Dijkstra进行输出结果
    void DisPath(int** path, double** map);//适用于Floyd进行输出结果
    void getEdges();//初始化边数组
public:
    bool readFile(string fileName);//读取文件
    bool writeFile(string fileName);//写文件
    Graph(int n,string fileName);
    Graph(int n,int flag);
    ~Graph();
    void Init(int n) ; //初始化
    void printMatrix(double **map);//打印邻接矩阵
    void printMatrix();//打印邻接矩阵
    void printEdges();//打印边数组
    int getV();//获得节点个数
    void setEdge(int from, int to, int wt) ;  //给两个点之间的边来设计权重
    void delEdge(int v1, int v2) ;  //删掉两点之间的边
    double weight(int v1, int v2) ; //取权重
    void setMark(int v, int val) ; //进行标记
    void initMark(); //初始化标记数组
public:
    //测试校园地图
    void Floyd();//输出两点之间的所有路径
    void initNodeInfo(string fileName);//从文件中读取校园节点信息进 节点数组
    void Dijkstra(int v,int t);//输出两点之间最短路径
    string GetNodeInfo(int n);//获取结点n 的名称
    void dbInfo(int from, int to);//输出两点路径之间的形式
    void addNode(string NodeName);//添加结点
    void saveNode(string fileName);//保存结点名称
    void deleteNode(int v);//删除结点
    //仓库
    void RouteSome();//规定一些途径点 并输出路径 
    void initPath();//更新Path数组
    void dfs(int u); //获得路径数组
    void FindPath(int *match,int n);//输出根据一些条件输出路径 必须经过一些点
    void lessNumPath();//输出经过点最少 的路径
    void AllPath();//输出全部路径
};

