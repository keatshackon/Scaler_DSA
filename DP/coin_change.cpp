#include <bits/stdc++.h>
using namespace std;
#define ll long long


int solve(int n, vector<int> v, int k, vector<vector<int>>&dp) {

	if (k == 0) {
		return 1;
	}
	if (n == 0) {
		return 0;
	}
	if (dp[n][k] != -1 ) {
		return dp[n][k];
	}

	if (k >= v[n - 1]) {
		return dp[n][k] =  solve(n - 1, v, k - v[n - 1], dp) + solve(n - 1, v, k, dp);
	} else {
		return dp[n][k] = solve(n - 1, v, k, dp);
	}
}

int main() {

	vector<int>v = {7, 4, 9, 6, 10, 13, 14, 11};

	int n = v.size();
	int k = 22;
	vector<vector<int>>dp(n + 1, vector<int>(k + 1, -1));

	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= k; j++) {
			dp[i][j] = -1;
		}
	}
	solve(n , v, k, dp);
	cout << dp[n][k] << "\n";
	return 0;
}