#include "Binary_tree.hpp"
#include<vector>
template<class T>
Binary_tree<T>::Binary_tree(T* a, int n)
{
	int i = 0;
	CreateBiTree(this->root,a, n, i);
}
template<class T>
Binary_tree<T>::Binary_tree(Binary_tree<T>& bt)
{
	this->copy(this->root, bt.root);
	this->cnt = bt.cnt;
}
template<class T>
void Binary_tree<T>::getLevel(Node<T>* p){
	cout << "----------------------计算节点层次~~~" << endl;
	int level=get_Level(this->root, p);
	if (level)
		cout << "已找到该元素位于：第" << level << "层" << endl;
	else {
		cout << "不存在该元素" << endl;
	}
}
template<class T>
void Binary_tree<T>::getNodeNum()//统计结点数目
{
	cout << "---------------------统计结点数目~~~" << endl;
	if (cnt == 0)
		cout << "为空树" << endl;
	else {
		cout << "结点数目为：" << cnt << endl;
	}
}
template<class T>
void Binary_tree<T>::getYeNodeNum()
{
	cout << "----------------------统计叶结点的数目~~~" << endl;
	int num = 0;
	get_YeNodeNum(this->root, num);
	cout << "叶结点的数目为：" << num << endl;
}
template<class T>
void Binary_tree<T>::getHeight()
{
	cout << "----------------------计算二叉树的高度~~~" << endl;
	int h = get_height(this->root);
	if (h == 0)
		cout << "为空树" << endl;
	else
		cout << "该树的高度为：" << h << endl;
}
template<class T>
void Binary_tree<T>::getNodeDu(Node<T>* p)
{
	cout << "----------------------计算结点的度~~~" << endl;
	int cd=-1, rd=-1;
	get_NodeDu(this->root, p, cd, rd);
	if (cd == -1 || rd == -1)
		cout << "不存在该结点" << endl;
	else
		cout << "入度：" << rd << " " << "出度：" << cd << endl;
}
template<class T>
void Binary_tree<T>::getParent(Node<T>* p)
{
	cout << "----------------------正在找结点的双亲中~~~" << endl;
	if (cnt == 0)cout << "为空树" << endl;
	else if (cnt == 1)cout << "只有一个根节点，无双亲" << endl;
	else {
		Node<T>* par;
		int biaoji=-1;
		if (p->operator==(this->root)) {
			cout << "你访问的是根结点，无双亲" << endl;
			return;
		}
		get_parent(this->root, p, par, biaoji);
		if (biaoji == -1)cout << "不存在该结点" << endl;
		else if (biaoji)cout << "结点值为：" << par->val << "的左孩子为：" << "结点值为：" << p->val << endl;
		else cout << "结点值为：" << par->val << "的右孩子为：" << "结点值为：" << p->val << endl;
	}
}
template<class T>
void Binary_tree<T>::getChild(Node<T>* p)
{
	cout << "----------------------寻找子女中~~~" << endl;
	Node<T>* lchid, * rchild;
	get_child(this->root, p, lchid, rchild);
	cout << "结点值为：" << p->val;
	if (lchid)cout << "左孩子为结点值为：" << lchid->val<<"\t";
	else cout << "无左孩子"<<"\t";
	if (rchild)cout << "右孩子为结点值为：" << rchild->val << endl;
	else cout << "无右孩子" << endl;
}
template<class T>
void Binary_tree<T>::preOrder()
{
	cout << "----------------------前序遍历(递归)~~~" << endl;
	pre_Order(root);
	cout << endl;
}
template<class T>
void Binary_tree<T>::inOrder()
{
	cout << "----------------------中序遍历(递归)~~~" << endl;
	in_Order(root);
	cout << endl;
}
template<class T>
void Binary_tree<T>::postOrder()
{
	cout << "后序遍历(递归)~~~" << endl;
	post_Order(root);
	cout << endl;
}

template<class T>
void Binary_tree<T>::preOrder1()
{
	cout << "----------------------前序遍历(非递归)~~~" << endl;
	Stack<Node<T>*> s;
	Node<T>* p;
	if (this->root) {
		s.Push(this->root);
		while (!s.empty()) {
			p = s.getTop();
			cout << p->val << " ";
			s.Pop();
			if (p->rchid!=NULL)
				s.Push(p->rchid);
			if (p->lchid != NULL)
				s.Push(p->lchid);
		}
		cout << endl;
	}
}

template<class T>
void Binary_tree<T>::inOrder1()
{
	cout << "----------------------中序遍历(非递归)~~~" << endl;
	Stack<Node<T>*> s;
	Node<T>* p;
	p = root;
	while (!s.empty() || p) {
		while (p) {
			s.Push(p);
			p = p->lchid;
		}
		if(!s.empty()) {
			p = s.getTop();
			s.Pop();
			cout << p->val << " ";
			p = p->rchid;
		}
	}
	cout << endl;
}

template<class T>
void Binary_tree<T>::postOrder1()
{
	cout << "----------------------后序遍历(非递归)~~~" << endl;
	Stack<Node<T>*>s;
	Node<T>* p, * r;
	p = root;
	bool flag;
	do
	{
		while (p) {
			s.Push(p);
			p = p->lchid;
		}
		flag = true;
		r = NULL;
		while (!s.empty()&&flag)
		{
			p = s.getTop();
			if (p->rchid == r) {
				cout << p->val << " ";
				s.Pop();
				r = p;
			}
			else {
				p = p->rchid;
				flag = false;
			}
		}
	} while (!s.empty());
	cout << endl;
}
template<class T>
void Binary_tree<T>::levelOrder()
{
	cout << "----------------------层序遍历~~~" << endl;
	Queue<Node<T>*> q;
	Node<T>* p=this->root;
	if (!p) {
		cout << "为一个空树" << endl;
		return;
	}
	q.Push(this->root);
	while (!q.empty()) {
		p = q.getFront();
		q.Pop();
		cout << p->val << " ";
		if (p->lchid)
			q.Push(p->lchid);
		if (p->rchid)
			q.Push(p->rchid);
	}
	cout << endl;
}

template<class T>
void Binary_tree<T>::TreePrint()
{
	cout << "----------------------输出二叉树树形~~~" << endl;

	int arr[100][3];
	int i = 0;
	int level = 0;
	Tree_Print(this->root,arr,i,level);
	//for (int k = 0; k < 3; k++) {
	//	for (int j = 0; j < i; j++) {
	//		cout << arr[j][k] << " ";
	//	}
	//	cout << endl;
	//}
	//cout << endl;
	sort_arr(arr, i);//按层次进行排序
	/*for (int k = 0; k < 3; k++) {
		for (int j = 0; j < i; j++) {
			cout << arr[j][k] << " ";
		}
		cout << endl;
	}*/
	cout << endl;
	bool flag=false;//是否在同一层
	int num=0,kg;
	vector<int> v;
	for (int k = 0; k < i; k++) {
		if (arr[num][1] != arr[k][1]) {
			num = k;
		}
		kg = num == k ? arr[k][2] : arr[k][2] - arr[k-1][2];
		v.push_back(kg);
		for (int j = 0; j < kg; j++) {
			cout << "\t";
		}
		cout << arr[k][0];
		if (arr[k][1] != arr[k + 1][1]) {
			cout << endl;
			for (int b = 0; b < arr[k + 1][2]; b++)//从这儿开始
				cout << "\t ";
			int ss = arr[k + 1][1];
			int c;
			for (c = k + 1; c < i; c++) {
				if (arr[c][1] == ss) {
					int d = 0;
					while (d < (arr[c][2] - arr[c - 1][2])) {
						cout << "--------";
						d++;
					}
				}
			}
			cout << endl;

		}
	}
}

template<class T>
void Binary_tree<T>::Exchage()
{
	if(root)
		Exchagechild(root);
}

template<class T>
void Binary_tree<T>::co_b_tree()
{
	cout << "----------------------判断是否为完全二叉树~~~" << endl;
	if (isCo_b_tree(root)) {
		cout << "是完全二叉树" << endl;
	}
	else {
		cout << "不是完全二叉树" << endl;
	}
}

template<class T>
void Binary_tree<T>::CreateBiTree(Node<T>*&root,T* a, int n,int &i) {
	if (i == n)
		return ;
	else if (i < n && a[i] == -1) {
		i++;
		root = NULL;
	}
	else {
		cnt++;
		root = new Node<T>(a[i]);
		i++;
		CreateBiTree(root->lchid,a, n, i );
		CreateBiTree(root->rchid,a, n, i );
	}
}

template<class T>
int Binary_tree<T>::get_Level(Node<T>* t, Node<T>* p)
{
	if (t == NULL)
		return 0;
	else {
		if (p->operator==( t))return 1;
		int L = get_Level(t->lchid, p);
		int R = get_Level(t->rchid, p);
		if (L || R)
			return 1 + (L > R ? L : R);
		else {
			return 0;
		}
	}
}

template<class T>
void Binary_tree<T>::get_YeNodeNum(Node<T>* t,int &num)
{
	
	if (t == NULL)return;
	else {
		if (t->lchid == NULL && t->rchid == NULL)
			num++;
		get_YeNodeNum(t->lchid, num);
		get_YeNodeNum(t->rchid, num);
	}
}

template<class T>
int Binary_tree<T>::get_height(Node<T>* t)
{
	if (t == NULL)
		return 0;
	else {
		int L = get_height(t->lchid);
		int R = get_height(t->rchid);
		return 1+( L > R ? L : R);
	}
}

template<class T>
void Binary_tree<T>::get_NodeDu(Node<T>* t, Node<T>* p, int& cd, int& rd)
{
	if (t) {
		if (p->operator==(t))
		{
			if (t->lchid != NULL && t->rchid != NULL)cd = 2;
			else if (t->lchid != NULL || t->rchid != NULL)cd = 1;
			else cd = 0;
			if (t != this->root)rd = 1;
			else rd = 0;
			return;
		}
		get_NodeDu(t->lchid, p, cd, rd);
		get_NodeDu(t->rchid, p, cd, rd);
	}
}

template<class T>
void Binary_tree<T>::get_parent(Node<T>* t, Node<T>* p,Node<T>*&par,int& biaoji)
{
	if (t) {
		if ((t->lchid!=NULL&&t->lchid ->operator==( p)) ||(t->rchid!=NULL&& t->rchid->operator==( p))) {
			par = new Node<T>(t->val);
			biaoji = t->lchid->operator==( p) ? 1 : 0;
			return;
		}
		get_parent(t->lchid, p, par, biaoji);
		get_parent(t->rchid, p, par, biaoji);
	}
}

template<class T>
void Binary_tree<T>::get_child(Node<T>* t, Node<T>* p, Node<T>*& lchild, Node<T>*& rchild)
{
	if (t) {
		if (p->operator==(t)) {
			if (t->lchid == NULL)lchild = NULL;
			if (t->rchid == NULL)rchild = NULL;
			rchild = t->rchid;
			lchild = t->lchid;
			return;
		}
		get_child(t->lchid, p, lchild, rchild);
		get_child(t->rchid, p, lchild, rchild);
	}
}

template<class T>
void Binary_tree<T>::pre_Order(Node<T>* t)
{
	if (t) {
		cout << t->val << " ";
		pre_Order(t->lchid);
		pre_Order(t->rchid);
	}
}

template<class T>
void Binary_tree<T>::in_Order(Node<T>* t)
{
	if (t) {
		in_Order(t->lchid);
		cout << t->val << " ";
		in_Order(t->rchid);
	}
}

template<class T>
void Binary_tree<T>::post_Order(Node<T>* t)
{
	if (t) {
		post_Order(t->lchid);
		post_Order(t->rchid);
		cout << t->val << " ";
	}
}

template<class T>
void Binary_tree<T>::copy(Node<T> *&new_root, Node<T>* src)
{
	if (src)
	{
		new_root = new Node<T>(src->val);
		copy(new_root->lchid, src->lchid);
		copy(new_root->rchid, src->rchid);
	}
}

template<class T>
void Binary_tree<T>::Tree_Print(Node<T>* T, int arr[100][3], int& i, int level)
{
	if (T) {
		Tree_Print(T->lchid, arr,i,level+1);
		arr[i][0] = T->val;
		arr[i][1] = level;
		arr[i][2] = i++;
		Tree_Print(T->rchid, arr,i, level + 1);
	}
}

template<class T>
void Binary_tree<T>::sort_arr(int arr[100][3],int i)
{
	int temp;
	for (int j = 0; j < i; j++) {
		int count = 0;
		for (int k = 0; k < i - j-1; k++) {
			if (arr[k][1] > arr[k + 1][1]) {
				swap(arr[k], arr[k + 1]);
				count = 1;
			}

		}
		if (count == 0)
			break;
	}
}

template<class T>
void Binary_tree<T>::Exchagechild(Node<T>* root)
{
	if (root) {
		Node<T>* temp = root->lchid;
		root->lchid = root->rchid;
		root->rchid = temp;
		Exchagechild(root->lchid);
		Exchagechild(root->rchid);
	}
	
}

template<class T>
bool Binary_tree<T>::isCo_b_tree(Node<T>* root)
{
	if(!root)
		return false;
	Queue<Node<T>*> q;
	Node<T>* p = this->root;
	q.Push(this->root);
	while (!q.empty()) {
		p = q.getFront();
		if (p->lchid && p->rchid) {
			q.Pop();
			q.Push(p->lchid);
			q.Push(p->rchid);
		}
		else if (p->lchid == NULL && p->rchid) {
			return false;
		}
		if ((p->lchid && p->rchid == NULL) || (p->lchid == NULL && p->rchid == NULL))
		{
			if (NULL != p->lchid && NULL == p->rchid)
			{
				q.Push(p->lchid);
			}
			q.Pop(); //则该节点之后的所有结点都是叶子节点
			while (!q.empty())
			{
				p = q.getFront();
				if (p->lchid == NULL && p->rchid == NULL)
				{
					q.Pop();
				}
				else
				{
					return false;
				}
			}
			return true;
		}
		
	}
	return false;
	cout << endl;
}



