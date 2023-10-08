#include <bits/stdc++.h>
using namespace std;
#define ll long long


int solve(int i, int j, int row, int col, vector<vector<int>>&A, vector<vector<int>>&dp) {

	if (i >= row) {
		return 0;
	}

	if (dp[i][j] != -1) return dp[i][j];

	int mini = INT_MAX;
	for (int k = 0; k < col; k++) {
		if (k != j) {
			int s1 = A[i][k] + solve(i + 1, k, row, col, A, dp);
			dp[i][j] = mini = min(mini, s1);
		}
	}
	return mini;
}


int main() {


	vector<vector<int>>A = {
		{5, 8, 10, 2},
		{4, 9, 13, 7},
		{6, 5, 10, 11},
		{19, 20, 21, 3}
	};


	int row = A.size();
	int col = A[0].size();

	vector<vector<int>>dp(row, vector<int>(col, -1));

	cout << solve(0, 0, row, col, A, dp) << "\n";


	for (auto q : dp) {
		for (auto w : q) {
			cout << w << " ";
		}
		cout << "\n";
	}



	return 0;
}