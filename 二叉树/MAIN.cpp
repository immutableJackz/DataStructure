#include"Binary_tree.hpp"
#include"Binary_tree.cpp"
template<class T>
void test1(Binary_tree<T> bt, Node<T>* p) {
	bt.getLevel(p);//获取目标节点的层次

	bt.getNodeNum();//获取树的结点数目
	bt.getYeNodeNum();//获取树的叶结点数目

	bt.getHeight();//获取树的高度

	bt.getNodeDu(p);//获取目标节点的出度和入度
	
	bt.getParent(p);//获取目标节点的双亲
	bt.getChild(p);//获取目标节点的孩子

	bt.preOrder();//前序遍历（递归）
	bt.inOrder();//中序遍历（递归）
	bt.postOrder();//后序遍历（递归）
	bt.preOrder1();	//前序遍历（非递归）
	bt.inOrder1(); // 中序遍历（非递归）
	bt.postOrder1();;//后序遍历（非递归）
	bt.levelOrder();//层序遍历
	
	bt.TreePrint();//输出树形结构
	
	bt.Exchage();//交换左右子树	
	bt.TreePrint();//输出树形结构
	
	bt.co_b_tree();//判断是否为完全二叉树
}
int main() {
	int arr1[] = {1,2,4,-1,-1,8,-1,-1,3,5,-1,-1,7};//满二叉树 13
	int arr2[] = { 1,2,4,-1,-1,8,100,-1,-1,101,-1,-1,3,5,-1,-1,9 };//17
	Binary_tree<int> bt (arr2, 13);
	Node<int>* p = new Node<int>(3);
	test1(bt, p);
	Binary_tree<int> bt1(bt);//二叉树的复制
	cout << endl;
	cout << "复制后的二叉树的测试" << endl;
	test1(bt1, p);
}