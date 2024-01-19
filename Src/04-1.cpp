///* 리스트 - 다항식 프로그램 */
//#include <iostream>
//#include <list>
//#include <algorithm>
//using namespace std;
//
//int main(int argc, char* argv[]) {
//	/* Faster */
//	ios::sync_with_stdio(0);
//	cin.tie(0); cout.tie(0);
//
//	/* Init */
//	list<pair<int, int>> li[3];
//
//	/* Input */
//	for (int i = 0; i < 2; i++) {
//		int n; cin >> n;
//		for (int j = 0; j < n; j++) {
//			int coef, degr; cin >> coef >> degr; //계수, 차수
//			li[i].push_back(make_pair(coef, degr));
//		}
//	}
//
//	/* Merge */
//	list<pair<int, int>>::iterator i = li[0].begin();
//	list<pair<int, int>>::iterator j = li[1].begin();
//		
//	while ((i != li[0].end()) && (j != li[1].end())) {
//		if (i->second > j->second) {
//			li[2].push_back(*i);
//			i++;
//		}
//		else if (i->second < j->second) {
//			li[2].push_back(*j);
//			j++;
//		}
//		else {
//			li[2].push_back(make_pair(i->first + j->first, i->second));
//			i++; j++;
//		}
//	}
//	while (i != li[0].end()) {
//		li[2].push_back(*i);
//		i++;
//	}
//	while (j != li[1].end()) {
//		li[2].push_back(*j);
//		j++;
//	}
//		
//	/* Output */
//	for (int i = 0; i < 3; i++) {
//		cout << '(' << li[i].size() << ") = ";
//		while (!li[i].empty()) {
//			if (li[i].front().first != 0) {
//				cout << li[i].front().first << ".0" << ' ';
//				cout << "x^" << li[i].front().second << ' ';
//				if (li[i].size() != 1)
//					cout << "+ ";
//			}
//
//			li[i].pop_front();
//		}
//		cout << '\n';
//	}
//	
//	/* Return */
//	return 0;
//}