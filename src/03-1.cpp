/* 큐 - 미팅 주선 프로그램 */
#include <iostream>
#include <deque>
#include <string>
using namespace std;

int main(int argc, char* argv[]) {
	/* Faster */
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	/* Input */
	deque<string> m; //남성
	deque<string> f; //여성
	int n; cin >> n;

	/* Calculation */
	for (int i = 0; i < n; i++) {
		/* Init */
		int time;	 //시간
		string name; //이름
		char sex;    //성별
		char fr;     //앞뒤

		/* Input */
		cin >> time >> name >> sex >> fr;

		/* Deque Insertion */
		if (sex == 'm') {
			if (fr == 'F')
				m.push_front(name);
			else if (fr == 'R')
				m.push_back(name);
		}
		else if (sex == 'f') {
			if (fr == 'F')
				f.push_front(name);
			else if (fr == 'R')
				f.push_back(name);
		}

		/* Matching */
		if (!m.empty() && !f.empty()) {
			cout << "Matched : " << m.front() << ' ' << f.front() << '\n';
			m.pop_front(); f.pop_front();
		}
	}

	/* Output */
	cout << (n - (m.size() + f.size())) / 2 << ' ' << m.size() << ' ' << f.size();
	
	/* Return */
	return 0;
}