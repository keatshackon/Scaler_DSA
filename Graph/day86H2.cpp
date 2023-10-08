#include <bits/stdc++.h>
using namespace std;
#define ll long long



int main() {


	int a = 2, b = 4, c = 2, d = 1, e = 4, f = 4;

	int row = a;
	int col = b;

	queue<pair<int, pair<int, int>>>q;
	vector<vector<int>>visited(row + 1, vector<int>(col + 1, 0));
	vector<vector<int>>dist(row + 1, vector<int>(col + 1, 0));
	q.push({0, {1, 1}});

	while (!q.empty()) {
		int p_dist = q.front().first;
		int x = q.front().second.first;
		int y = q.front().second.second;
		q.pop();

		int dx[] = { -2, -2, 2, 2, 1, -1, -1, 1};
		int dy[]  = { 1, -1, -1, 1, -2, -2, 2, 2};

		for (int i = 0; i < 8; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 1 and nx <= row and ny >= 1 and ny <= col and !visited[nx][ny]) {
				visited[nx][ny] = 1;
				dist[nx][ny] = p_dist + 1;
				q.push({dist[nx][ny], {nx, ny}});
			}
		}
	}

	for (auto q : visited) {
		for (auto w : q) {
			cout << w << " ";
		}
		cout << "\n";
	}
	cout << "\n";

	for (auto q : dist) {
		for (auto w : q) {
			cout << w << " ";
		}
		cout << "\n";
	}

	if (e >= 1 and e <= row and f >= 1 and f <= col and visited[e][f] != 0 ) {
		cout << dist[e][f];
	} else {
		cout << -1 << "\n";
	}

	return 0;
}