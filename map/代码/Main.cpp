#include"Graph.hpp"
void test3() {//无向图 求校园最短路径
	using namespace chrono;
	duration<double> diff;
	Graph g(11, "xiaoyuan.txt");//从xiaoyuan.txt文件中读取数据领接矩阵
	auto starttime = system_clock::now();
	g.initNodeInfo("xiaoyuanNodeInfo.txt");//从记录校园结点名称xiaoyuanNodeInfo.txt文件中读取结点名称
	auto end = system_clock::now();
	diff = end - starttime;
	cout << "读入节点信息耗时" << diff.count() << "s" << endl;

	starttime = system_clock::now();
	g.Dijkstra(1,2);//获得某点到某点的最短路径
	end = system_clock::now();
	diff = end - starttime;
	cout << "计算两点最短路径信息耗时" << diff.count() << "s" << endl;

	starttime = system_clock::now();
	cout << g.GetNodeInfo(12) << endl;//获得某点的信息
	g.Floyd();//任意两点的最短路径
	end = system_clock::now();
	diff = end - starttime;
	cout << "计算任意两点最短路径信息耗时" << diff.count() << "s" << endl;
	
	//单独对边点进行测试
	int from, to, n;
	from = 2; to = 4;
	//对边进行修改或删除 前后对比
	g.dbInfo(from, to);
	g.setEdge(from, to, 70);//修改 2到4 路径权重
	cout << "修改后：" << endl;
	g.dbInfo(from, to);
	cout << "------------------" << endl;
	g.delEdge(from, to);//删除 2到4 的路径权重
	cout << "删除后：" << endl;
	g.dbInfo(from, to);
	cout << "------------------" << endl;
	//对点进行添加或删除 前后对比
	g.addNode("超市");
	n = g.getV();
	cout << g.GetNodeInfo(n) << endl;//添加结点至结点数组尾部
	cout << "------------------" << endl;
	g.deleteNode(12); //删除结点
	cout << g.GetNodeInfo(n) << endl;
	cout << "------------------" << endl;


	//添加点 并为其附上边 查看 添加前后的路径变化
	//未修改边和点 
	starttime = system_clock::now();
	g.Dijkstra(11, 4);//获得某点到某点的最短路径
	end = system_clock::now();
	diff = end - starttime;
	cout << "计算两点最短路径信息耗时" << diff.count() << "s" << endl;
	g.addNode("致远楼");
	n = g.getV();
	g.setEdge(n, 11,80);
	g.setEdge(n, 4, 150);
	starttime = system_clock::now();
	g.Dijkstra(11, 4);//获得某点到某点的最短路径
	end = system_clock::now();
	diff = end - starttime;
	cout << "计算两点最短路径信息耗时" << diff.count() << "s" << endl;

	cout << "是否保存(保存 y)";
	string s;cin >> s;
	if (s == "y")g.saveNode("xiaoyuanNodeInfo.txt");

}
void test4() {//无向图 仓库最优取货路径
	using namespace chrono;
	duration<double> diff;
	Graph g(13, "changku.txt");//从changku.txt文件中读取数据领接矩阵
	g.initNodeInfo("changkuNodeInfo.txt");//从记录仓库结点名称changkuNodeInfo.txt文件中读取结点名称
	auto starttime = system_clock::now();
	g.initPath();//更新path数组
	auto end = system_clock::now();
	diff = end - starttime;
	cout << "初始化path数组信息耗时" << diff.count() << "s" << endl;

	starttime = system_clock::now();
	g.RouteSome();//输出途径某些点的路径展示
	end = system_clock::now();
	diff = end - starttime;
	cout << "途径某些点的路径展示信息耗时" << diff.count() << "s" << endl;

	starttime = system_clock::now();
	g.lessNumPath();//输出路径点最少的路径展示
	end = system_clock::now();
	diff = end - starttime;
	cout << "最少路径点的路径展示信息耗时" << diff.count() << "s" << endl;
	
	starttime = system_clock::now();
	g.AllPath();//输出全部路径的路径展示
	end = system_clock::now();
	diff = end - starttime;
	cout <<"全部路径展示信息耗时" << diff.count() << "s" << endl;

	g.delEdge(10, 9);//删除一条边
	g.initPath();
	g.AllPath();

	cout << "是否保存(保存 y)";
	string s; cin >> s;
}
int main() {
	//test3();
	test4();

}