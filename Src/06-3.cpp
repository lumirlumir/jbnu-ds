#include <iostream>
#include <map>
#include <string>
using namespace std;

int main(void) {
	/* Faster */
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	/* Init */
	map<string, string> ke;
	map<string, string> ek;

	/* Input */
	while (true) {
		/* Input */
		char c; cin >> c;

		/* I */
		if (c == 'i') {
			cin.ignore();
			string kr; getline(cin, kr);
			string eg; getline(cin, eg);

			ke.insert(make_pair(kr, eg));
			ek.insert(make_pair(eg, kr));
		}
		/* K */
		else if (c == 'k') {
			cin.ignore();
			string kr; getline(cin, kr);

			if (ke.find(kr) == ke.end())
				cout << kr << " UNKNOWN ENTRY" << '\n';
			else
				cout << ke.find(kr)->first << ' ' << ke.find(kr)->second << '\n';
		}
		/* E */
		else if (c == 'e') {
			cin.ignore();
			string eg; getline(cin, eg);

			if (ek.find(eg) == ek.end())
				cout << eg << " UNKNOWN ENTRY" << '\n';
			else
				cout << ek.find(eg)->first << ' ' << ek.find(eg)->second << '\n';
		}
		/* P */
		else if (c == 'p') {
			cout << "K-E dictionary:\n";
			for (auto i : ke)
				cout << i.first << ' ' << i.second << '\n';

			cout << "E-K dictionary:\n";
			for (auto i : ek)
				cout << i.first << ' ' << i.second << '\n';
		}
		/* Q */
		else if (c == 'q')
			return 0;
	}
}