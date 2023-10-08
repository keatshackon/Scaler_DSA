#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main() {

	vector<vector<int>>A = {
		{1, 1, 0, 1},
		{0, 0, 0, 1},
		{1, 0, 0, 1},
		{0, 0, 1, 0}
	};
	vector<int> b = {1, 1};
	vector<int> c = {2, 1};

	priority_queue < pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>>q;
	q.push({0, {b[0], b[1]}});

	int row = A.size();
	int col = A[0].size();

	vector<vector<int>>visited(row, vector<int>(col, 0));
	vector<vector<int>>dist(row, vector<int>(col, 0));

	while (!q.empty()) {
		int p_dist = q.top().first;
		int x = q.top().second.first;
		int y = q.top().second.second;
		q.pop();

		int dx[] = {1, -1, 0, 0};
		int dy[] = {0, 0, -1, 1};

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 and nx < row and ny >= 0 and ny < col and
			        !visited[nx][ny] and A[nx][ny] == 0) {

				visited[nx][ny] = 1;
				dist[nx][ny] = p_dist + 1;
				q.push({p_dist, {nx, ny}});
			}
		}

	}


	for (auto q : dist) {
		for (auto w : q) {
			cout << w << " ";
		}
		cout << "\n";
	}
	cout << "\n\n";
	for (auto q : visited) {
		for (auto w : q) {
			cout << w << " ";
		}
		cout << "\n";
	}

	cout << dist[c[0]][c[1]];


	return 0;
}