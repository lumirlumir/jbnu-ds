/* 큐 - 정렬 가능 여부 확인 프로그램 */
#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int main(int argc, char* argv[]) {
	/* Faster */
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	/* Init & Input */
	int n; cin >> n;	//n=number
	char s; cin >> s;	//s=sort

	stack<int> stack;
	queue<int> seq;
	for (int i = 0; i < n; i++) {
		int tmp; cin >> tmp;
		seq.push(tmp);
	}

	/* Calculation */
	int i; s == 'a' ? i = 1 : i = n; //asc인 경우 i = 1, desc인 경우 i = n
	while(!seq.empty()) {
		if (stack.empty()) {
			stack.push(seq.front());
			seq.pop();
		}
		while (!seq.empty() ? stack.top() != i : false) {
			stack.push(seq.front());
			seq.pop();
		}
		while (!stack.empty() ? stack.top() == i : false) {
			stack.pop();
			s == 'a' ? i++ : i--;
		}
	}

	/* Output */
	if (stack.empty())
		cout << "Yes";
	else
		cout << "No";

	/* Return */
	return 0;
}