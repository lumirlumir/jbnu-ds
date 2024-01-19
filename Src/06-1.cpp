//#include <iostream>
//#include <algorithm>
//#include <cstdio>
//#include <cstdlib>
//#include <cmath>
//#define MAX_QUEUE_SIZE 100
//using namespace std;
//
///* Class */
//class binarynode {
//protected:
//	int	data;
//	binarynode* left;
//	binarynode* right;
//public:
//	/* Constructor & Destructor */
//	binarynode(int _data = 0, binarynode* _left = NULL, binarynode* _right = NULL)  
//		: data(_data), left(_left), right(_right) { }
//	~binarynode() { }
//	/* Method : Set */
//	void setdata(int _data) { 
//		data = _data; 
//	}
//	void setleft(binarynode* _left) { 
//		left = _left; 
//	}
//	void setright(binarynode* _right) { 
//		right = _right; 
//	}
//	/* Method : Get */
//	int	getdata() { 
//		return data; 
//	}
//	binarynode* getleft() { 
//		return left; 
//	}
//	binarynode* getright() { 
//		return right; 
//	}
//	/* Method : Others */
//	bool isleaf() { 
//		return left == NULL && right == NULL; 
//	}
//};
//
//class binarytree {
//protected:
//	binarynode* root;
//public:
//	/* Constructor & Destructor */
//	binarytree() 
//		: root(NULL) { }
//	~binarytree() { }
//	/* Method : Bool */
//	bool isempty() {
//		return root == NULL;
//	}
//	/* Method : Set */
//	void setroot(binarynode* node) { 
//		root = node; 
//	}
//	/* Method : Get */
//	binarynode* getroot() { 
//		return root; 
//	}
//	int	getcount() { 
//		return isempty() ? 0 : getcount(root); 
//	}
//	int getcount(binarynode* node) {
//		if (node == NULL) return 0;
//		return 1 + getcount(node->getleft()) + getcount(node->getright());
//	}
//	int	getleafcount() { 
//		return isempty() ? 0 : getleafcount(root); 
//	}
//	int getleafcount(binarynode* node) {
//		if (node == NULL) return 0;
//		if (node->isleaf()) return 1;
//		else return getleafcount(node->getleft()) + getleafcount(node->getright());
//	}
//	int	getheight() { 
//		return isempty() ? 0 : getheight(root); 
//	}
//	int getheight(binarynode* node) {
//		if (node == NULL) return 0;
//		int	hLeft = getheight(node->getleft());
//		int	hRight = getheight(node->getright());
//		return (hLeft > hRight) ? hLeft + 1 : hRight + 1;
//	}
//	/* Method : Traversal */
//	void inorder() { 
//		printf("\n%10s : ", "inorder");
//		inorder(root); 
//	}
//	void inorder(binarynode* node) {
//		if (node != NULL) {
//			if (node->getleft() != NULL) inorder(node->getleft());
//			printf("[%c] ", node->getdata());
//			if (node->getright() != NULL) inorder(node->getright());
//		}
//	}
//	void preorder() { 
//		printf("\n%10s : ", "preorder");
//		preorder(root); 
//	}
//	void preorder(binarynode* node) {
//		if (node != NULL) {
//			printf("[%c] ", node->getdata());
//			if (node->getleft() != NULL) preorder(node->getleft());
//			if (node->getright() != NULL) preorder(node->getright());
//		}
//	}
//	void postorder() { 
//		printf("\n%10s : ", "postorder");
//		postorder(root); 
//	}
//	void postorder(binarynode* node) {
//		if (node != NULL) {
//			if (node->getleft() != NULL) postorder(node->getleft());
//			if (node->getright() != NULL) postorder(node->getright());
//			printf("[%c] ", node->getdata());
//		}
//	}	
//	/* Method : New(Homework) */
//	bool isfull() {
//		return getcount() == pow(2, getheight()) - 1;
//	}
//	/*
//	1. 높이가 h일때, 트리는 최소 h개 ~ 최대 2^h - 1개의 노드를 가진다.
//	2. 이때, 노드의 개수가 0, 1, 3, 7, ..., 2^h - 1개 일 때,
//	   (노드가 해당 높이에서 지닐 수 있는 최대 개수일 때) 포화이진트리가 된다.
//	3. 노드의 개수가 0개일때도 포화이진트리가 성립하는 걸로 생각하자.
//	*/
//	
//	bool isbalanced_slow() {
//		return isbalanced_slow(root);
//	}
//	bool isbalanced_slow(binarynode* node) {
//		/* Base Case */
//		if (node == NULL) 
//			return true;
//		/* Inductive Step */
//		else 
//			return 
//			abs(getheight(node->getleft()) - getheight(node->getright())) < 2 &&
//			isbalanced_slow(node->getleft()) &&
//			isbalanced_slow(node->getright());
//	}
//	/*
//	1. return isempty() ? true : isbalanced(root); 에서 isempty() 메소드는 결국
//	   root == NULL 여부를 따지는 것이므로, return isbalanced(root)와 동일하다. 
//	2. 노드의 개수가 0개일때도 balanced가 true가 된다고 생각하자.	
//	*/
//
//	bool isbalanced_fast() {
//		bool isbalanced = true;
//		isbalanced_fast(root, isbalanced);
//
//		return isbalanced;
//	}
//	int isbalanced_fast(binarynode* node, bool& isbalanced) {
//		/* Base Case */
//		if (node == NULL || !isbalanced)
//			return 0;
//		/* Inductive Step */
//		int left_height = isbalanced_fast(node->getleft(), isbalanced);
//		int right_height = isbalanced_fast(node->getright(), isbalanced);
//
//		if (abs(left_height - right_height) > 1)
//			isbalanced = false;
//
//		return max(left_height, right_height) + 1;			
//	}
//
//	void reverse() {
//		return reverse(root);
//	}
//	void reverse(binarynode* node) {
//		/* Base Case */
//		if (node == NULL)
//			return;
//		/* Inductive Step */
//		//Recursion
//		reverse(node->getleft());
//		reverse(node->getright());
//		//Swap
//		binarynode* temp = node->getleft();
//		node->setleft(node->getright());
//		node->setright(temp);
//	}
//};
//
//class binarysearchtree : public binarytree {
//public:
//	void insert(binarynode* n) {
//		if (n == NULL)
//			return;
//		if (isempty())
//			root = n;
//		else
//			insert(root, n);
//	}
//	void insert(binarynode* r, binarynode* n) {
//		if (n->getdata() == r->getdata())
//			return;
//		else if (n->getdata() < r->getdata()) {
//			if (r->getleft() == NULL)
//				r->setleft(n);
//			else
//				insert(r->getleft(), n);
//		}
//		else {
//			if (r->getright() == NULL)
//				r->setright(n);
//			else
//				insert(r->getright(), n);
//		}
//	}
//	void remove(int data) {
//		if (isempty())
//			return;
//
//		binarynode* parent = NULL;
//		binarynode* node = root;
//		while (node != NULL && node->getdata() != data) {
//			parent = node;
//			node = (data < node->getdata()) ? node->getleft() : node->getright();
//		}
//
//		if (node == NULL) {
//			cout << "Error : key is not in the tree\n";
//			return;
//		}
//		else
//			remove(parent, node);			
//	}
//	void remove(binarynode* parent, binarynode* node) {
//		/* Case 1 */
//		if (node->isleaf()) {
//			if (parent == NULL)
//				root = NULL;
//			else {
//				if (parent->getleft() == node)
//					parent->setleft(NULL);
//				else
//					parent->setright(NULL);
//			}
//		}
//		/* Case 2 */
//		else if (node->getleft() == NULL || node->getright() == NULL) {
//			binarynode* child = node->getleft() != NULL ? node->getleft() : node->getright();
//
//			if (node == root)
//				root = child;
//			else {
//				if (parent->getleft() == node)
//					parent->setleft(child);
//				else
//					parent->setright(child);
//			}
//		}
//		/* Case 3 */
//		else {
//			binarynode* succp = node;
//			binarynode* succ = node->getright();
//			while (succ->getleft() != NULL) {
//				succp = succ;
//				succ = succ->getleft();
//			}
//
//			if (succp->getleft() == succ)
//				succp->setleft(succ->getright());
//			else
//				succp->setright(succ->getright());
//
//			node->setdata(succ->getdata());
//			node = succ;
//		}
//		delete node;
//	}
//};
//
//int main(void) {
//	/* Faster */
//	ios::sync_with_stdio(0);
//	cin.tie(0); cout.tie(0);
//
//	/* Init */
//	binarysearchtree bst;
//
//	/* Input */
//	int n; cin >> n;
//
//	/* Loop */
//	while (n--) {
//		/* Input */
//		char c; cin >> c;
//
//		if (c == 'I') {
//			int x; cin >> x;
//			bst.insert(new binarynode(x));
//		}
//		else if (c == 'D') {
//			int x; cin >> x;
//			bst.remove(x);
//		}
//	}
//
//	/* Output */
//	if (bst.isbalanced_fast())
//		cout << "Balanced";
//	else
//		cout << "Unbalanced";
//
//	/* Return */
//	return 0;
//}