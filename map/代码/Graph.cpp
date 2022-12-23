#include "Graph.hpp"
int num = 0;
//����ȫ�ֶ���
int g[MAX][MAX];
int s, t;
int path[MAX][MAX];
int pathH[MAX];
int cnt,way;
int total;//����������·������
int ways[MAX];//·����������
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
		cout  << f << "->" << end << "�����·��:  ";
		d = 1, road[d] = t;
		k = path[t];
		if (k == -1) {
			cout << "������·��" << endl;
		}
		else {
			//���·��
			while (k != v) {
				road[++d] = k;
				k = path[k];
			}
			//���·��
			road[++d] = v;
			cout << node[road[d]].GetName();
			for (j = d - 1; j > 0; j--) {
				cout <<"->"<< node[road[j]].GetName();
			}
			cout << "\t" << "��·���ĳ���Ϊ��" << dis[t] << "��"<<endl;
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
				cout << f << "->" << end << "�����·��:  ";
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
				cout << "\t" << "��·���ĳ���Ϊ��" << map[i][j] << "��" << endl;
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
		cout << "��ʧ��" << endl;
		return false;
	}
	f.seekg(0);
	if (!f.eof()) {//�ļ���������ͼ��������ͼ
		f >> x;
		if (x == 1) {
			flag = 1;
			cout << "����ͼ" << endl;
		}
		else if (x == 0) {
			flag = 0;
			cout << "����ͼ" << endl;
		}
			
	}
	//��ȡ��Ӿ���
	while (!f.eof())
	{
		f >> x;
		if (num == n * n)
			break;
		start = num / n;
		end = num % n;
		this->matrix[start][end] = x;
		
		num++;
		if (f.fail())break; //���eof���һ�е�����
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
		f << flag << endl;//���������ͼ��������ͼ
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
	getEdges();//��ʼ��������
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
    mark = new int[n1];//��ʹ�ýڵ�0
	node = new Node[n1];//��ʹ�ýڵ�0
    //��ʼ����� Ϊδ����
    //memset(mark, UNVISITED, n);
	//��Ӷ�������
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
	cout << "����  ����  Ȩ��" << endl;
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
			numEdge += 2;//����ͼ
		}
		else {
			matrix[v1][v2] = wt;
			numEdge += 1;
		}
	}
	else {
		if (flag)
		{//����ͼ
			matrix[v1][v2] = matrix[v2][v1] = wt;
		}
		else {
			matrix[v1][v2] = wt;
		}
	}
	
	 //���û�бߣ�������һ��
}

void Graph::delEdge(int v1, int v2)
{
	if (matrix[v1][v2] != 0) {
		if (flag)
		{
			numEdge -= 2;//����ͼ
			matrix[v1][v2] = matrix[v2][v1] = 0;
		}
		else {
			numEdge -= 1;
			matrix[v1][v2] = 0;
		}
	}
	else {
		if (flag)
		{//����ͼ
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
	// ����������յ㣬���·��
	if (u == t) {
		ways[total] = way;
		for (int j = 0; j < cnt; j++) {
			path[total][j] = pathH[j];
		}
		++total;
	}
	else {
		// ���Ϊ�ѷ���
		mark[u] = VISITED;
		// �����������ڵ�
		for (int v = 1; v <= this->numVertex; v++) {
			if (this->matrix[u][v] && !mark[v]) {
				way += this->matrix[u][v];
				dfs(v);
				way -= this->matrix[u][v];
			}
		}
		// ����
		mark[u] = UNVISITED;
	}
	// ����ǰ���·�����Ƴ�
	--cnt;
}
void Graph::FindPath(int *match,int n)
{
	int i, j, num = 0;
	for ( i = 0; i < total; i++) {
		// �����������ڼ�¼ƥ������ֵ�����
		int count = 0;
		// ����ÿһ���е�ÿ��Ԫ��
		j = 0;
		while (path[i][j] != 0) {
			// ����ƥ�����������
			for (int k = 0; k < n; k++) {
				// ���������ƥ������֣��ͽ��������� 1
				if (path[i][j] == match[k]) {
					count++;
					// ��Ϊ�Ѿ��ҵ���ƥ������֣����Կ����˳�ѭ��
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
			cout << "\t" << "·������Ϊ:" << ways[i] << "��" << endl;
			num++;
		}
	}
	if (!num)cout << "��ƥ��·��" << endl;
	else cout << "����" << num << "��·��" << endl;
}

void Graph::lessNumPath()
{
	int i, j, final,min=INF;
	for (i = 0; i < total; i++) {
		// ����ÿһ���е�ÿ��Ԫ��
		j = 0;
		while (path[i][j] != 0) {
			j++;
		}
		if (j<min) {
			min = j;
			final = i;
		}
	}
	//���
	cout << ";�������ٵ�·�����£�" << endl;
	for (i = 0; i < min; i++) {
		if (i < min - 1)
			cout << node[path[final][i]].GetName() << "->";
		else
			cout << node[path[final][i]].GetName();
	}
	cout << "\t" << "·������Ϊ:" << ways[i] << "��" << endl;
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
	//��ʼ�� map
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
	//���Ĵ���
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
	//���
	DisPath(path, map);
	//�ͷ�ָ��
	deleteDouble(map);
	for (int i = 0; i < n; i++)
		delete[]path[i];
	delete path;
}

void Graph::Dijkstra(int v,int t)
{
	int i, j, pos = 1, n = this->numVertex+1;
	double  min, sum = 0;
	this->initMark();//��ʼ��Ϊ0����ʾ��ʼ��û�߹�
	double* dis = new double[n];
	int* path = new int[n];
	double** map = new double* [n];
	//��ʼ��  map
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
	//��ʼ�� path
	for (int i = 1; i < n; i++) {
		if (map[v][i]!=0&&map[v][i]!=INF) {
			path[i] = v;
		}
		else {
			path[i] = -1;
		}
	}
	//��ʼ�� dis
	for (i = 1; i < n; i++)
	{
		dis[i] = map[v][i];
	}
	this->setMark(v, VISITED);
	dis[v] = 0;
	int T = n - 2;
	//���Ĵ���
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
		mark[pos] = 1;//��ʾ������Ѿ��߹�
		for (j = 1; j < n; j++)
		{
			if (mark[j] == 0 && dis[j] > min + map[pos][j]) {
				//����dis��ֵ
				dis[j] = map[pos][j] + min;
				path[j] = pos;
			}
		}
	}
	DisplayPath(dis, path, mark, v,t);
	this->deleteDouble(map);//�ͷ�mapָ��
	delete[]path;
	delete[]dis;
}

string Graph::GetNodeInfo(int n)
{
	if (n <= this->numVertex && n >= 1)
		return node[n].GetName();
	else
		cout << "��������";
	return "";
}

void Graph::dbInfo(int from, int to)
{
	cout << this->GetNodeInfo(from) << "��" <<
		this->GetNodeInfo(to) << (this->weight(from, to) == 0 ? "��·��" : "·��Ϊ��" + to_string(this->weight(from, to))) << endl;
}

void Graph::addNode(string NodeName)
{
	//��תֵ
	int n = this->numVertex + 1;
	Node* anode = new Node[n+1];//��ʹ��0
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
	cout << "�ɹ����" << NodeName << "\t" << "���Ϊ��" << n << endl;
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
	}cout << "����ɹ�" << endl;
}

void Graph::deleteNode(int v)
{
	//��תֵ
	if (v > this->numVertex||v<1) {
		cout << "������" << endl;
		return;
	}
	string info = node[v].GetName();
	int n = this->numVertex - 1;
	int i, j, k = 1,m;
	Node* anode = new Node[n + 1];//��ʹ��0
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
	cout << "���Ϊ��" << v << "��" << info << "��ɾ��" << endl;
	delete[]anode;
	for (int i = 0; i < n+1; i++)
		delete[]amatrix[i];
}

void Graph::RouteSome()
{
	const int n = 3;
	int match[n] = { 8,7 ,10};//;����
	int i;
	cout << "��" << this->GetNodeInfo(s) << "->" << this->GetNodeInfo(t) << endl << ";�����µ�:" << endl;
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
	this->initMark();//����ȫ����δ����
	//cout << "��������ʼ��-�յ�" << endl;
	//cin >> s >> t;//��ʼ�� �յ� 
	s = 1;//���
	t = 13;//����
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
		cout << "��ʧ��" << endl;
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
		if (f.fail())break; //���eof���һ�е�����
	}
	f.close();
}