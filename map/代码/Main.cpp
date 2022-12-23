#include"Graph.hpp"
void test3() {//����ͼ ��У԰���·��
	using namespace chrono;
	duration<double> diff;
	Graph g(11, "xiaoyuan.txt");//��xiaoyuan.txt�ļ��ж�ȡ������Ӿ���
	auto starttime = system_clock::now();
	g.initNodeInfo("xiaoyuanNodeInfo.txt");//�Ӽ�¼У԰�������xiaoyuanNodeInfo.txt�ļ��ж�ȡ�������
	auto end = system_clock::now();
	diff = end - starttime;
	cout << "����ڵ���Ϣ��ʱ" << diff.count() << "s" << endl;

	starttime = system_clock::now();
	g.Dijkstra(1,2);//���ĳ�㵽ĳ������·��
	end = system_clock::now();
	diff = end - starttime;
	cout << "�����������·����Ϣ��ʱ" << diff.count() << "s" << endl;

	starttime = system_clock::now();
	cout << g.GetNodeInfo(12) << endl;//���ĳ�����Ϣ
	g.Floyd();//������������·��
	end = system_clock::now();
	diff = end - starttime;
	cout << "���������������·����Ϣ��ʱ" << diff.count() << "s" << endl;
	
	//�����Աߵ���в���
	int from, to, n;
	from = 2; to = 4;
	//�Ա߽����޸Ļ�ɾ�� ǰ��Ա�
	g.dbInfo(from, to);
	g.setEdge(from, to, 70);//�޸� 2��4 ·��Ȩ��
	cout << "�޸ĺ�" << endl;
	g.dbInfo(from, to);
	cout << "------------------" << endl;
	g.delEdge(from, to);//ɾ�� 2��4 ��·��Ȩ��
	cout << "ɾ����" << endl;
	g.dbInfo(from, to);
	cout << "------------------" << endl;
	//�Ե������ӻ�ɾ�� ǰ��Ա�
	g.addNode("����");
	n = g.getV();
	cout << g.GetNodeInfo(n) << endl;//��ӽ�����������β��
	cout << "------------------" << endl;
	g.deleteNode(12); //ɾ�����
	cout << g.GetNodeInfo(n) << endl;
	cout << "------------------" << endl;


	//��ӵ� ��Ϊ�丽�ϱ� �鿴 ���ǰ���·���仯
	//δ�޸ıߺ͵� 
	starttime = system_clock::now();
	g.Dijkstra(11, 4);//���ĳ�㵽ĳ������·��
	end = system_clock::now();
	diff = end - starttime;
	cout << "�����������·����Ϣ��ʱ" << diff.count() << "s" << endl;
	g.addNode("��Զ¥");
	n = g.getV();
	g.setEdge(n, 11,80);
	g.setEdge(n, 4, 150);
	starttime = system_clock::now();
	g.Dijkstra(11, 4);//���ĳ�㵽ĳ������·��
	end = system_clock::now();
	diff = end - starttime;
	cout << "�����������·����Ϣ��ʱ" << diff.count() << "s" << endl;

	cout << "�Ƿ񱣴�(���� y)";
	string s;cin >> s;
	if (s == "y")g.saveNode("xiaoyuanNodeInfo.txt");

}
void test4() {//����ͼ �ֿ�����ȡ��·��
	using namespace chrono;
	duration<double> diff;
	Graph g(13, "changku.txt");//��changku.txt�ļ��ж�ȡ������Ӿ���
	g.initNodeInfo("changkuNodeInfo.txt");//�Ӽ�¼�ֿ�������changkuNodeInfo.txt�ļ��ж�ȡ�������
	auto starttime = system_clock::now();
	g.initPath();//����path����
	auto end = system_clock::now();
	diff = end - starttime;
	cout << "��ʼ��path������Ϣ��ʱ" << diff.count() << "s" << endl;

	starttime = system_clock::now();
	g.RouteSome();//���;��ĳЩ���·��չʾ
	end = system_clock::now();
	diff = end - starttime;
	cout << ";��ĳЩ���·��չʾ��Ϣ��ʱ" << diff.count() << "s" << endl;

	starttime = system_clock::now();
	g.lessNumPath();//���·�������ٵ�·��չʾ
	end = system_clock::now();
	diff = end - starttime;
	cout << "����·�����·��չʾ��Ϣ��ʱ" << diff.count() << "s" << endl;
	
	starttime = system_clock::now();
	g.AllPath();//���ȫ��·����·��չʾ
	end = system_clock::now();
	diff = end - starttime;
	cout <<"ȫ��·��չʾ��Ϣ��ʱ" << diff.count() << "s" << endl;

	g.delEdge(10, 9);//ɾ��һ����
	g.initPath();
	g.AllPath();

	cout << "�Ƿ񱣴�(���� y)";
	string s; cin >> s;
}
int main() {
	//test3();
	test4();

}