#include <bits/stdc++.h>
using namespace std;
#define ll long long


int solve(int x, int y, vector<vector<int>>&v, vector<vector<int>>&dp) {

	if (x == 0 or y == 0) {
		if (v[x][y] == -1) {
			return 0;
		} else {
			return 1;
		}
		return 1;
	}

	if (dp[x][y] != -1) return dp[x][y];

	if (v[x][y] == 0) {
		int s1 = solve(x - 1, y, v, dp);
		int s2 = solve(x, y - 1, v, dp);
		return dp[x][y] = s1 + s2;
	} else {
		dp[x][y] = 0;
		return 0;
	}
}

int main() {


	vector<vector<int>>A = {{0, 0, 0},
		{0, 1, 0},
		{0, 0, 0}
	};

	int row = A.size();
	int col = A[0].size();

	if (A[0][0] == 1) return 0;
	if (A[row - 1][col - 1] == 1) return 0;

	int f = 0;
	for (int i = 0; i < col; i++) {
		if (A[0][i] == 1 or f == 1) {
			A[0][i] = 0;
			f = 1;
		} else {
			A[0][i] = 1;
		}
	}
	f = 0;
	for (int i = 1; i < row; i++) {
		if (A[i][0] == 1 or f == 1) {
			A[i][0] = 0;
			f = 1;
		} else {
			A[i][0] = 1;
		}
	}

	vector<vector<int>>dp(row, vector<int>(col, -1));

	cout << solve(row - 1, col - 1, A, dp) << "\n\n";


	return 0;
}
