#include "Graph.hpp"
int num = 0;
//用于全局定义
int g[MAX][MAX];
int s, t;
int path[MAX][MAX];
int pathH[MAX];
int cnt,way;
int total;//满足条件的路径条数
int ways[MAX];//路径长度数组
void Graph::deleteDouble(double** map)
{
	int n = this->numVertex + 1;
	for (int i = 0; i < n; i++)
		delete[]map[i];
	delete map;
}
void Graph::DisplayPath(double* dis, int* path, int* mark, int v,int t)
{
	int j, k,d,n=this->numVertex+1;
	int* road = new int[n];

	if (mark[t] == 1 && t != v) {
		string f = node[v].GetName(), end = node[t].GetName();
		cout  << f << "->" << end << "的最短路径:  ";
		d = 1, road[d] = t;
		k = path[t];
		if (k == -1) {
			cout << "不存在路径" << endl;
		}
		else {
			//获得路径
			while (k != v) {
				road[++d] = k;
				k = path[k];
			}
			//输出路径
			road[++d] = v;
			cout << node[road[d]].GetName();
			for (j = d - 1; j > 0; j--) {
				cout <<"->"<< node[road[j]].GetName();
			}
			cout << "\t" << "该路径的长度为：" << dis[t] << "米"<<endl;
		}
	}
	
	delete[]road;
}
void Graph::DisPath(int** path, double** map)
{
	int i, j, k, s, n = this->numVertex + 1;
	int* road = new int[n], d;
	for (i = 1; i < n; i++) {
		for (int j = 1; j < n; j++) {
			if (i != j && map[i][j] != INF) {
				string f = node[i].GetName(), end = node[j].GetName();
				cout << f << "->" << end << "的最短路径:  ";
				k = path[i][j];
				d = 1; road[d]=j;
				while (k != -1 && k != i) {
					road[++d] = k;
					k = path[i][k];
				}
				road[++d] = i;
				cout << node[road[d]].GetName();
				for (s = d - 1; s > 0; s--) {
					cout << "->" << node[road[s]].GetName();
				}
				cout << "\t" << "该路径的长度为：" << map[i][j] << "米" << endl;
			}
		}
	}
	delete[]road;
}
void Graph::getEdges()
{
	int n = this->numVertex + 1;
	double x;
	int cur = 1;
	for (int i = 1; i < n; i++) {
		for (int j = 1; j < n; j++) {
			x = this->matrix[i][j];
			if(x){
				eg[cur].setFrom(i);
				eg[cur].setTo(j);
				eg[cur].setWt(x);
				++cur;
			}
		}
	}
	numEdge = cur-1;
}
bool Graph::readFile(string fileName)
{
	ifstream f;
	int n = this->numVertex + 1;
	double x;
	int num = 0, start, end;
	f.open(fileName, ios::in);
	if (!f.is_open()) {
		cout << "打开失败" << endl;
		return false;
	}
	f.seekg(0);
	if (!f.eof()) {//文件区分无向图还是有向图
		f >> x;
		if (x == 1) {
			flag = 1;
			cout << "无向图" << endl;
		}
		else if (x == 0) {
			flag = 0;
			cout << "有向图" << endl;
		}
			
	}
	//读取领接矩阵
	while (!f.eof())
	{
		f >> x;
		if (num == n * n)
			break;
		start = num / n;
		end = num % n;
		this->matrix[start][end] = x;
		
		num++;
		if (f.fail())break; //解决eof多读一行的问题
	}
	f.close();
	return true;
}
bool Graph::writeFile(string fileName)
{
	ofstream f;
	int n = this->numVertex + 1;
	f.open(fileName, ios::out);
	if (f) {
		f << flag << endl;//标记是无向图还是有向图
		for (int i = 0; i <n;i++) {
			for (int j = 0; j < n; j++) {
				f << this->matrix[i][j] << "\t";
			}
			f << endl;
		}
		f.close();
		return true;
	}
	cout << "file open error!" << endl;
	return false;
}
Graph::Graph(int n,string fileName)
{
	Init(n);
	readFile(fileName);
	getEdges();//初始化边数组
	this->fileName = fileName;
}
Graph::Graph(int n,int flag)
{
	Init(n);
	this->flag = flag;
}
Graph::~Graph()
{	
	if(fileName!="abc")
		writeFile(this->fileName);
	//writeFile("changku.txt");
	delete[]mark;
	delete[]node;
	deleteDouble(this->matrix);
}
void Graph::Init(int n)
{
	int i, n1 = n + 1;
	fileName = "abc";
    numVertex = n;
    numEdge = 0;
    mark = new int[n1];//不使用节点0
	node = new Node[n1];//不使用节点0
    //开始都标记 为未访问
    //memset(mark, UNVISITED, n);
	//添加顶点名称
	for (i = 1; i < n1; i++) {
		node[i].SetNo(i);
		node[i].SetName("V" + to_string(i));
	}

    for (i = 0; i < n1; i++)
        mark[i] = UNVISITED;

    matrix = (double**) new double* [n1];
    for (i = 0; i <n1 ; i++)
        matrix[i] = new double[n1];
    for (i = 0; i <n1; i++)
        for (int j = 0; j <n1; j++)
            matrix[i][j] = 0;
}
void Graph::printMatrix(double **map)
{
	int n = this->numVertex + 1;
	for (int i =1; i <n; i++) {
		for (int j = 1; j <n; j++) {
			cout<< map[i][j] << " ";
		}
		cout<< endl;
	}
	cout << endl;
}
void Graph::printMatrix()
{
	int n = this->numVertex + 1;
	for (int i =1; i <n; i++) {
		for (int j = 1; j <n; j++) {
			cout<< this->matrix[i][j] << " ";
		}
		cout<< endl;
	}
	cout << endl;
}
void Graph::printEdges()
{
	int e = this->numEdge+1;
	cout << "出发  到达  权重" << endl;
	for (int i = 1; i < e; i++) {
		cout << eg[i].getFrom() << " " << eg[i].getTo() << " " << eg[i].getWt() << endl;
	}
}
int Graph::getV()
{
	return this->numVertex;
}
void Graph::setEdge(int v1, int v2, int wt)
{
	if (matrix[v1][v2] == 0) {
		if (flag)
		{
			matrix[v1][v2] = matrix[v2][v1] = wt;
			numEdge += 2;//无向图
		}
		else {
			matrix[v1][v2] = wt;
			numEdge += 1;
		}
	}
	else {
		if (flag)
		{//无向图
			matrix[v1][v2] = matrix[v2][v1] = wt;
		}
		else {
			matrix[v1][v2] = wt;
		}
	}
	
	 //如果没有边，则增加一条
}

void Graph::delEdge(int v1, int v2)
{
	if (matrix[v1][v2] != 0) {
		if (flag)
		{
			numEdge -= 2;//无向图
			matrix[v1][v2] = matrix[v2][v1] = 0;
		}
		else {
			numEdge -= 1;
			matrix[v1][v2] = 0;
		}
	}
	else {
		if (flag)
		{//无向图
			matrix[v1][v2] = matrix[v2][v1] = 0;
		}
		else {
			matrix[v1][v2] = 0;
		}
	}
}

double Graph::weight(int v1, int v2)
{
	return matrix[v1][v2];
}

void Graph::setMark(int v, int val)
{
	mark[v] = val;
}
void Graph::initMark()
{
	int n = this->numVertex + 1;
	for (int i = 0; i < n; i++) mark[i] = UNVISITED;
}
void Graph::dfs(int u)
{
	pathH[cnt++] = u;
	// 如果到达了终点，输出路径
	if (u == t) {
		ways[total] = way;
		for (int j = 0; j < cnt; j++) {
			path[total][j] = pathH[j];
		}
		++total;
	}
	else {
		// 标记为已访问
		mark[u] = VISITED;
		// 搜索所有相邻点
		for (int v = 1; v <= this->numVertex; v++) {
			if (this->matrix[u][v] && !mark[v]) {
				way += this->matrix[u][v];
				dfs(v);
				way -= this->matrix[u][v];
			}
		}
		// 回溯
		mark[u] = UNVISITED;
	}
	// 将当前点从路径中移除
	--cnt;
}
void Graph::FindPath(int *match,int n)
{
	int i, j, num = 0;
	for ( i = 0; i < total; i++) {
		// 计数器，用于记录匹配的数字的数量
		int count = 0;
		// 遍历每一行中的每个元素
		j = 0;
		while (path[i][j] != 0) {
			// 遍历匹配的数字数组
			for (int k = 0; k < n; k++) {
				// 如果发现了匹配的数字，就将计数器加 1
				if (path[i][j] == match[k]) {
					count++;
					// 因为已经找到了匹配的数字，所以可以退出循环
					break;
				}
			}
			j++;
		}
		if (count == n) {
			flag = true;
			for (int k = 0; k < j; k++) {
				if (k< j - 1)
					cout << node[path[i][k]].GetName() << "->";
				else
					cout << node[path[i][k]].GetName();
			}
			cout << "\t" << "路径长度为:" << ways[i] << "米" << endl;
			num++;
		}
	}
	if (!num)cout << "无匹配路径" << endl;
	else cout << "共有" << num << "条路径" << endl;
}

void Graph::lessNumPath()
{
	int i, j, final,min=INF;
	for (i = 0; i < total; i++) {
		// 遍历每一行中的每个元素
		j = 0;
		while (path[i][j] != 0) {
			j++;
		}
		if (j<min) {
			min = j;
			final = i;
		}
	}
	//输出
	cout << "途径点最少的路径如下：" << endl;
	for (i = 0; i < min; i++) {
		if (i < min - 1)
			cout << node[path[final][i]].GetName() << "->";
		else
			cout << node[path[final][i]].GetName();
	}
	cout << "\t" << "路径长度为:" << ways[i] << "米" << endl;
}

void Graph::AllPath()
{
	FindPath(0, 0);
}

void Graph::Floyd()
{
	int n = this->numVertex+1;
	int i, j, k;
	double** map = new double* [n];
	int** path = new int* [n];
	//初始化 map
	for ( i = 0; i < n; i++) {
		map[i] = new double[n];
		path[i] = new int[n];
		for (j = 0; j < n; j++) {
			if (i == j) {
				map[i][j] = 0;
				path[i][j] = -1;
			}
			else if (this->matrix[i][j] == 0) {
				map[i][j] = INF;
				path[i][j] = -1;
			}
			else {
				map[i][j] = this->matrix[i][j];
				path[i][j] = i;
			}
		}
	}
	//核心代码
	for (k = 1; k < n; k++) {
		for (i = 1; i < n; i++) {
			for (j = 1; j < n; j++) {
				if (map[i][j] > map[i][k] + map[k][j]) {
					map[i][j] = map[i][k] + map[k][j];
					path[i][j] = path[k][j];
				}
			}
		}
	}
	//输出
	DisPath(path, map);
	//释放指针
	deleteDouble(map);
	for (int i = 0; i < n; i++)
		delete[]path[i];
	delete path;
}

void Graph::Dijkstra(int v,int t)
{
	int i, j, pos = 1, n = this->numVertex+1;
	double  min, sum = 0;
	this->initMark();//初始化为0，表示开始都没走过
	double* dis = new double[n];
	int* path = new int[n];
	double** map = new double* [n];
	//初始化  map
	for (int i = 0; i < n; i++) {
		map[i] = new double[n];
		for (int j = 0; j < n; j++) {
			if (i == j) {
				map[i][j] = 0;
			}
			else if (this->matrix[i][j] == 0) {
				map[i][j] = INF;
			}
			else {
				map[i][j] = this->matrix[i][j];
			}
		}
	}
	//初始化 path
	for (int i = 1; i < n; i++) {
		if (map[v][i]!=0&&map[v][i]!=INF) {
			path[i] = v;
		}
		else {
			path[i] = -1;
		}
	}
	//初始化 dis
	for (i = 1; i < n; i++)
	{
		dis[i] = map[v][i];
	}
	this->setMark(v, VISITED);
	dis[v] = 0;
	int T = n - 2;
	//核心代码
	while (T--)
	{
		min = INF;
		for (j = 1; j < n; j++)
		{
			if (mark[j] == 0 && min > dis[j])
			{
				min = dis[j];
				pos = j;
			}
		}
		mark[pos] = 1;//表示这个点已经走过
		for (j = 1; j < n; j++)
		{
			if (mark[j] == 0 && dis[j] > min + map[pos][j]) {
				//更新dis的值
				dis[j] = map[pos][j] + min;
				path[j] = pos;
			}
		}
	}
	DisplayPath(dis, path, mark, v,t);
	this->deleteDouble(map);//释放map指针
	delete[]path;
	delete[]dis;
}

string Graph::GetNodeInfo(int n)
{
	if (n <= this->numVertex && n >= 1)
		return node[n].GetName();
	else
		cout << "输入有误";
	return "";
}

void Graph::dbInfo(int from, int to)
{
	cout << this->GetNodeInfo(from) << "到" <<
		this->GetNodeInfo(to) << (this->weight(from, to) == 0 ? "无路径" : "路径为：" + to_string(this->weight(from, to))) << endl;
}

void Graph::addNode(string NodeName)
{
	//中转值
	int n = this->numVertex + 1;
	Node* anode = new Node[n+1];//不使用0
	double** amatrix = new double* [n + 1];
	this->numVertex++;
	mark = new int[n + 1];
	this->initMark();
	for (int i = 1; i < n; i++) {
		anode[i] = node[i];
	}
	for (int i = 0; i < n; i++) {
		amatrix[i] = new double[n];
		for (int j = 0; j < n; j++) {
			amatrix[i][j] = this->matrix[i][j];
		}
	}
	node = new Node[n + 1];
	matrix = new double* [n + 1];
	for (int i = 1; i < n; i++)
		node[i] = anode[i];
	node[n].SetName(NodeName);
	node[n].SetNo(n);
	for (int i = 0; i < n+1; i++) {
		matrix[i] = new double[n + 1];
		for (int j = 0; j < n+1; j++) {
			if (i < n && j < n)
				this->matrix[i][j] = amatrix[i][j];
			else
				this->matrix[i][j] = 0;
		}
	}
	cout << "成功添加" << NodeName << "\t" << "编号为：" << n << endl;
	delete[]anode;
	for (int i = 0; i < n; i++)
		delete[]amatrix[i];
	delete amatrix;
}

void Graph::saveNode(string fileName)
{
	ofstream f;
	int n = this->numVertex + 1;
	f.open(fileName, ios::out);
	if (f) {
		for (int i = 1; i < n; i++)f << node[i].GetName() << endl;
		f.close();
	}cout << "保存成功" << endl;
}

void Graph::deleteNode(int v)
{
	//中转值
	if (v > this->numVertex||v<1) {
		cout << "不存在" << endl;
		return;
	}
	string info = node[v].GetName();
	int n = this->numVertex - 1;
	int i, j, k = 1,m;
	Node* anode = new Node[n + 1];//不使用0
	double** amatrix = new double* [n + 1];
	this->numVertex = n;
	mark = new int[n + 1];
	this->initMark();
	for (i = 1; i < n + 2;i++) {
		if (i == v)continue;
		anode[k++] = node[i];
	}
	k = 0;
	for (int i = 0; i < n+2; i++) {
		amatrix[i] = new double[n+1];
		if (i == v)continue;
		m = 0;
		for (int j = 0; j < n+2; j++) {
			if (j == v)continue;
			amatrix[k][m++] = this->matrix[i][j];
		}
		k++;
	}
	node = new Node[n + 1];
	matrix = new double* [n + 1];
	for (int i = 1; i < n+1; i++)
		node[i] = anode[i];
	for (int i = 0; i < n + 1; i++) {
		matrix[i] = new double[n + 1];
		for (int j = 0; j < n + 1; j++) {
			this->matrix[i][j] = amatrix[i][j];
		}
	}
	cout << "编号为：" << v << "的" << info << "被删除" << endl;
	delete[]anode;
	for (int i = 0; i < n+1; i++)
		delete[]amatrix[i];
}

void Graph::RouteSome()
{
	const int n = 3;
	int match[n] = { 8,7 ,10};//途经点
	int i;
	cout << "从" << this->GetNodeInfo(s) << "->" << this->GetNodeInfo(t) << endl << "途径以下点:" << endl;
	for (i = 0; i < n; i++) {
		cout << this->GetNodeInfo(match[i]) << " ";
	}
	cout << endl;
	FindPath(match, n);
}

void Graph::initPath()
{
	total = 0;
	memset(ways, 0, sizeof ways);
	this->initMark();//设置全部点未访问
	//cout << "请输入起始点-终点" << endl;
	//cin >> s >> t;//起始点 终点 
	s = 1;//入口
	t = 13;//出口
	dfs(s);
}

void Graph::initNodeInfo(string filename)
{
	ifstream f;
	int n = this->numVertex + 1;
	string x;
	int num = 1;
	f.open(filename, ios::in);
	if (!f.is_open()) {
		cout << "打开失败" << endl;
	}
	f.seekg(0);
	while (!f.eof())
	{
		f >> x;
		if (num == n)
			break;
		node[num].SetName(x);
		node[num].SetNo(num);
		num++;
		if (f.fail())break; //解决eof多读一行的问题
	}
	f.close();
}