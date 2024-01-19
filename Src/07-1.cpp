//#include <iostream>
//#define ELEM 200
//using namespace std;
//
//class heapnode {
//private:
//	int key;
//
//public:
//	/* Constructor */
//	heapnode(int _key = 0) : key(_key) {}
//
//	/* Method */
//	void setkey(int _key) {
//		key = _key;
//	}
//	int getkey(void) {
//		return key;
//	}
//	void display(void) {
//		cout << key << ' ';
//	}
//};
//
//class minheap {
//private:
//	heapnode node[ELEM];
//	int size;
//
//public:
//	/* Constructor */
//	minheap() : size(0) {}
//
//	/* Method */
//	heapnode& getparent(int i) {
//		return node[i / 2];
//	}
//	heapnode& getleft(int i) {
//		return node[i * 2];
//	}
//	heapnode& getright(int i) {
//		return node[i * 2 + 1];
//	}
//
//
//	bool empty() {
//		return size == 0;
//	}
//	bool full() {
//		return size == ELEM - 1;
//	}
//	void push(int key) { //insert
//		if (full()) return;
//
//		int i = ++size;
//
//		while (i != 1 && key < getparent(i).getkey()) {
//			node[i] = getparent(i);
//			i /= 2;
//		}
//		node[i].setkey(key);
//	}
//	heapnode pop() { //remove
//		heapnode item = node[1];
//		heapnode last = node[size--];
//		int parent = 1;
//		int child = 2;
//
//		while (child <= size) {
//			if (child < size && getleft(parent).getkey() > getright(parent).getkey())
//				child++;
//			if (last.getkey() <= node[child].getkey())
//				break;
//
//			node[parent] = node[child];
//			parent = child;
//			child *= 2;
//		}
//
//		node[parent] = last;
//		return item;
//	}
//	heapnode top() {
//		return node[1];
//	}
//	void display() {
//		for (int i = 1; i <= size; i++)
//			node[i].display();
//		cout << '\n';
//	}
//};
//
//int main(int argc, char* argv[]) {
//	/* Faster */
//	ios::sync_with_stdio(0);
//	cin.tie(0); cout.tie(0);
//
//	/* Init */
//	minheap mh;
//
//	/* Input */
//	int n, k; cin >> n >> k;
//	for (int i = 0; i < n; i++) {
//		int x; cin >> x;
//		mh.push(x);
//	}
//		
//	/* Output1 */
//	mh.display();
//
//	/* Pop */
//	for (int i = 0; i < k; i++)
//		mh.pop();
//
//	/* Output2 */
//	mh.display();
//
//	/* Return */
//	return 0;
//}
//
///*
//6 3
//5 3 8 1 2 10
//
//10 5
//20 15 54 60 12 5 8 17 30 22
//*/