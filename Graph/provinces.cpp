#include <bits/stdc++.h>
using namespace std;
#define ll long long


void dfs(int row, int col, vector<vector<int>>&provinces, vector<vector<bool>>&visited) {

	visited[row][col] = 1;

	int dx[] = {0, 0, 1, 1};
	int dy[] = {1, -1, 0, 0};

	for (int i = 0; i < 4; i++) {

		int nrow = row + dx[i];
		int ncol = col + dy[i];

		if (nrow >= 0 and nrow < provinces.size() and ncol >= 0 and ncol < provinces[0].size() and
		        provinces[nrow][ncol] == 1 and visited[nrow][ncol] == 0) {

			dfs(nrow, ncol, provinces, visited);
		}
	}

}


void bfs(int row, int col, vector<vector<int>>&provinces, vector<vector<bool>>&visited) {

	visited[row][col] = 1;
	queue<pair<int, int>>q;
	q.push({row, col});

	while (!q.empty()) {
		int row = q.front().first;
		int col = q.front().second;
		q.pop();
		for (int i = -1; i <= 1; i++) {
			for (int j = -1; j <= 1; j++) {
				int nrow = row + i;
				int ncol = col + j;
				//int sum = nrow + ncol;
				if (nrow >= 0 and nrow < provinces.size() and ncol >= 0 and ncol < provinces.size() and
				        provinces[nrow][ncol] == 1 and visited[nrow][ncol] == 0) {

					q.push({nrow, ncol});
					visited[nrow][ncol] = 1;
				}
			}
		}
	}
}

int main() {

	vector<vector<int>>provinces = {{1, 1, 0}, {1, 1, 0}, {0, 0, 1}};

	int row = provinces.size();
	int col = row;

	vector<vector<bool>>visited(row, vector<bool>(col, 0));


	int cnt = 0;

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (provinces[i][j] == 1 and visited[i][j] == 0) {
				cnt++;
				dfs(i, j, provinces, visited);
			}
		}
	}

	cout << cnt << "\n";

	// PRINTING THE GRAPH;
	for (auto q : visited) {
		for (auto w : q) {
			cout << w << " ";
		}
		cout << "\n";
	}

	return 0;
}