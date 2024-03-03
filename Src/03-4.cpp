/* 토이 편집기 Undo Redo */
#include <iostream>
#include <deque>
#include <stack>
#include <string>
using namespace std;

int main(int argc, char* argv[]) {
	/* Faster */
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	/* Init */
	deque<char> u;	// Undo Deque
	stack<char> r;	// Redo Stack
	string str;		// Input

	/* Input */
	getline(cin, str);

	/* Calculation */
	for (int i = 0; i < str.size(); i++) {
		/* Ignore Blank */
		if (str[i] == ' ')
			continue;
		/* U : Undo */
		else if (str[i] == 'U') {
			/* Undo Deque이 비어있을 경우 */
			if (u.empty()) {
				cout << "ERROR" << '\n';
				return 0;
			}
			/* 연산 */
			r.push(u.front());
			u.pop_front();
		}
		/* R : Redo */
		else if (str[i] == 'R') {
			/* Redo Stack이 비어있을 경우 */
			if (r.empty()) {
				cout << "ERROR" << '\n';
				return 0;
			}
			/* 연산 */
			u.push_front(r.top());
			r.pop();
		}
		/* a ~ z */
		else if ('a' <= str[i] && str[i] <= 'z') {
			/* 새로운 입력이 들어오면 Redo Stack을 비움 */
			while (!r.empty())
				r.pop();
			/* Size가 10보다 커질 경우 */
			if (u.size() == 10)
				u.pop_back();
			/* 연산 */
			u.push_front(str[i]);
		}
	}

	/* Output */
	// Undo Deque
	if (u.size() == 0)
		cout << "EMPTY";
	else
		while (u.size() != 0) {
			cout << u.front() << ' ';
			u.pop_front();
		}

	cout << '\n';

	// Redo Stack
	if (r.empty())
		cout << "EMPTY";
	else
		while (!r.empty()) {
			cout << r.top() << ' ';
			r.pop();
		}

	/* Return */
	return 0;
}