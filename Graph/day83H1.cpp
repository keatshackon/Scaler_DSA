#include <bits/stdc++.h>
using namespace std;
#define ll long long


void solve(int i, int j, vector<vector<int>>&A, vector<vector<int>>&visited) {

	visited[i][j] = 1;

	int dx[] = { -1, -1, -1, 0, 0, 1, 1, 1};
	int dy[] = { -1, 0, 1, -1, 1, -1, 0, 1};

	for (int k = 0; k < 8; k++) {
		int nrow = i + dx[k];
		int ncol = j + dy[k];

		if (nrow >= 0 and nrow < A.size() and ncol >= 0 and ncol < A[0].size()
		        and A[nrow][ncol] == 1 and visited[nrow][ncol] == 0) {

			solve(nrow, ncol, A, visited);
		}
	}
}

int main() {

	vector<vector<int>>A = {
		{1, 1, 0, 0, 0},
		{0, 1, 0, 0, 0},
		{1, 0, 0, 1, 1},
		{0, 0, 0, 0, 0},
		{1, 0, 1, 0, 1}
	};

	int row = A.size();
	int col = A[0].size();

	vector<vector<int>>visited(row, vector<int>(col, 0));


	int cnt = 0;

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (!visited[i][j] and A[i][j] == 1) {
				cnt++;
				solve(i, j, A, visited);
			}
		}
	}

	cout << cnt << "\n";

	return 0;
}