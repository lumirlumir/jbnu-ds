#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

bool DC(vector<int>& v, int i) {
	/* Base Case */
	if (i * 2 + 1 >= v.size() && i * 2 + 2 >= v.size()) //말단노드
		return true;

	/* Inductive Step */
	if (i * 2 + 2 < v.size())   //자식 노드가 2개인 경우.
		return
		v[i] >= v[i * 2 + 1] &&
		v[i] >= v[i * 2 + 2] &&
		DC(v, i * 2 + 1) &&
		DC(v, i * 2 + 2);
	else                        //자식 노드가 1개인 경우.
		return
		v[i] >= v[i * 2 + 1];
}

int main(int argc, char* argv[]) {
	/* Faster */
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	/* Input */
	int n; cin >> n;
	vector<int> v(n, 0); for (auto& i : v) cin >> i;
	
	/* Output */
	if (DC(v, 0))
		cout << "YES" << '\n';
	else
		cout << "NO" << '\n';

	/* Return */
	return 0;
}

/*
10
15 14 13 12 11 10 9 8 7 5

10
15 13 14 12 11 10 9 8 7 5

5
30 15 16 7 20
*/