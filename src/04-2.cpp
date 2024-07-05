#include <iostream>
#include <list>
#include <string>
using namespace std;

int main(int argc, char* argv[]) {
	/* Faster */
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	/* Init */
	list<string> li;
	list<string>::iterator it;

	/* Loop */
	while (true) {
		/* Init */
		char c; cin >> c;

		switch (c) {
		/* i */
		case 'i': {
			/* Input */
			int n; cin >> n;
			string s; cin.ignore(); getline(cin, s);

			/* Insert */
			it = li.begin();
			for (int i = 0; i < n; i++) it++;
			li.insert(it, s);

			/* Break */
			break;
		}
		/* d */
		case 'd': {
			/* Input */
			int n; cin >> n;

			/* Delete */
			it = li.begin();
			for (int i = 0; i < n; i++) it++;
			li.erase(it);

			/* Break */
			break;
		}
		/* r */
		case 'r': {
			/* Input */
			int n; cin >> n;
			string s; cin.ignore(); getline(cin, s);

			/* Replace */
			it = li.begin();
			for (int i = 0; i < n; i++) it++;
			*it = s;

			/* Break */
			break;
		}
		/* f */
		case 'f': {
			/* Input */
			string prev; cin.ignore(); getline(cin, prev);
			string next; getline(cin, next);

			/* Find */
			for (auto& i : li)
				if (i == prev) i = next;

			/* Break */
			break;
		}
		/* p */
		case 'p': {
			/* Output */
			int line = 0;
			for (auto i : li)
				cout << line++ << ':' << ' ' << i << '\n';
			cout << "EOF\n";

			/* Break */
			break;
		}
		/* q */
		case 'q' :
			return 0;
		}
	}
}