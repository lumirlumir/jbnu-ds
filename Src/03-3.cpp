/* BFS for Maze */
#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;

int main(int argc, char* argv[]) {
	/* Faster */
	ios::sync_with_stdio(0);
	std::cin.tie(0); 
	std::cout.tie(0);

	/* Input & Init */
	int n, m; cin >> n >> m;

	int dist[50][50] = {};
	bool visit[50][50] = {};
	char maze[50][50] = {};
	for (int i = 0; i < n; i++)
		cin >> maze[i];

	pair<int, int> T;
	queue<pair<int, int>> q;	// <col, row>
	
	/* BFS for Maze */
	// find S & T
	for (int x = 0; x < n; x++)
		for (int y = 0; y < m; y++) {
			if (maze[x][y] == 'S') {
				visit[x][y] = true;
				q.push(make_pair(x, y));
			}
			else if (maze[x][y] == 'T') {
				T.first = x;
				T.second = y;
			}
		}	

	// BFS
	while (!q.empty()) {
		/* Init */
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		/* Up */
		if (x - 1 >= 0 ?
			(maze[x - 1][y] != '1') && (visit[x - 1][y] == false) : false) {
			dist[x - 1][y] = dist[x][y] + 1;
			visit[x - 1][y] = true;
			q.push(make_pair(x - 1, y));
		}
		/* Down */
		if (x + 1 <= n - 1 ?
			(maze[x + 1][y] != '1') && (visit[x + 1][y] == false) : false) {
			dist[x + 1][y] = dist[x][y] + 1;
			visit[x + 1][y] = true;
			q.push(make_pair(x + 1, y));
		}	
		/* Left */
		if (y - 1 >= 0 ?
			(maze[x][y - 1] != '1') && (visit[x][y - 1] == false) : false) {
			dist[x][y - 1] = dist[x][y] + 1;
			visit[x][y - 1] = true;
			q.push(make_pair(x, y - 1));
		}
		/* Right */
		if (y + 1 <= m - 1 ?
			(maze[x][y + 1] != '1') && (visit[x][y + 1] == false) : false) {
			dist[x][y + 1] = dist[x][y] + 1;
			visit[x][y + 1] = true;
			q.push(make_pair(x, y + 1));
		}

		/* Debug */
		std::cout << '\n';
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				std::cout << maze[i][j];
			}
			std::cout << ' ';
			for (int j = 0; j < m; j++) {
				std::cout << visit[i][j];
			}
			std::cout << ' ';
			for (int j = 0; j < m; j++) {
				std::cout << dist[i][j] + 1;
			}
			std::cout << '\n';
		}
		queue<pair<int, int>> _q; _q = q;
		std::cout << "<QUEUE>" << '\n';
		while (!_q.empty()) {
			std::cout << '(' << _q.front().first << ' ' << _q.front().second << ')' << '\n';
			_q.pop();
		}

	}

	/* Output */
	std::cout << ((dist[T.first][T.second] != 0) ? (dist[T.first][T.second] + 1) : 0);

	/* Return */
	return 0;
}