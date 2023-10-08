#include <bits/stdc++.h>
using namespace std;
#define ll long long


int solve(int i, int j, vector<vector<int>>&A, vector<vector<int>>&dp) {

	if (i == 0) {
		return A[0][0];
	}

	if (dp[i][j] != -1) return dp[i][j];

	int s1 = INT_MAX, s2 = INT_MAX;

	if (j < i) {
		s1 = solve(i - 1, j, A, dp);
	}

	if (j - 1 >= 0) {
		s2 = solve(i - 1, j - 1, A, dp);
	}


	return dp[i][j] = A[i][j] + min(s1, s2);
}


int main() {

	vector<vector<int>> A = {
		{2},
		{3, 4},
		{6, 5, 7},
		{4, 1, 8, 3}
	};

	int row = A.size();
	int len = A[row - 1].size();


	vector<vector<int>>dp(row, vector<int>(row, -1));
	dp[0][0] = A[0][0];

	for (int i = 0; i < len; i++) {
		solve(row - 1, i, A, dp);
	}


	for (auto q : dp) {
		for (auto w : q) {
			cout << w << " ";
		}
		cout << "\n";
	}
	cout << "\n";

	int ans = INT_MAX;

	for (auto q : dp[row - 1]) {
		ans = min(ans, q);
	}

	cout << ans;


	return 0;
}