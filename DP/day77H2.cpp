#include <bits/stdc++.h>
using namespace std;
#define ll long long


int solve(int x, int y, vector<vector<int>>&v, vector<vector<int>>&dp) {

	if (x == 0 or y == 0) {
		return dp[x][y];
	}

	if (dp[x][y] != -1) return dp[x][y];

	int s1 = v[x][y] + solve(x - 1, y, v, dp);
	int s2 = v[x][y] + solve(x, y - 1, v, dp);
	return dp[x][y] = min(s1 , s2);

}

int main() {


	vector<vector<int>>A = {
		{1, 3, 2},
		{4, 3, 1},
		{5, 6, 1}
	};

	int row = A.size();
	int col = A[0].size();

	vector<vector<int>>dp(row, vector<int>(col, -1));
	dp[0][0] = A[0][0];

	for (int i = 1; i < col; i++) {
		dp[0][i] = A[0][i] + dp[0][i - 1];
	}

	for (int i = 1; i < row; i++) {
		dp[i][0] = A[i][0] + dp[i - 1][0];
	}

	for (auto q : dp) {
		for (auto w : q) {
			cout << w << " ";
		}
		cout << "\n";
	}

	cout << solve(row - 1, col - 1, A, dp) << "\n\n";

	for (auto q : dp) {
		for (auto w : q) {
			cout << w << " ";
		}
		cout << "\n";
	}
	return 0;
}
