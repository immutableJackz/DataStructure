#include"Binary_tree.hpp"
#include"Binary_tree.cpp"
template<class T>
void test1(Binary_tree<T> bt, Node<T>* p) {
	bt.getLevel(p);//��ȡĿ��ڵ�Ĳ��

	bt.getNodeNum();//��ȡ���Ľ����Ŀ
	bt.getYeNodeNum();//��ȡ����Ҷ�����Ŀ

	bt.getHeight();//��ȡ���ĸ߶�

	bt.getNodeDu(p);//��ȡĿ��ڵ�ĳ��Ⱥ����
	
	bt.getParent(p);//��ȡĿ��ڵ��˫��
	bt.getChild(p);//��ȡĿ��ڵ�ĺ���

	bt.preOrder();//ǰ��������ݹ飩
	bt.inOrder();//����������ݹ飩
	bt.postOrder();//����������ݹ飩
	bt.preOrder1();	//ǰ��������ǵݹ飩
	bt.inOrder1(); // ����������ǵݹ飩
	bt.postOrder1();;//����������ǵݹ飩
	bt.levelOrder();//�������
	
	bt.TreePrint();//������νṹ
	
	bt.Exchage();//������������	
	bt.TreePrint();//������νṹ
	
	bt.co_b_tree();//�ж��Ƿ�Ϊ��ȫ������
}
int main() {
	int arr1[] = {1,2,4,-1,-1,8,-1,-1,3,5,-1,-1,7};//�������� 13
	int arr2[] = { 1,2,4,-1,-1,8,100,-1,-1,101,-1,-1,3,5,-1,-1,9 };//17
	Binary_tree<int> bt (arr2, 13);
	Node<int>* p = new Node<int>(3);
	test1(bt, p);
	Binary_tree<int> bt1(bt);//�������ĸ���
	cout << endl;
	cout << "���ƺ�Ķ������Ĳ���" << endl;
	test1(bt1, p);
}