#include <bits/stdc++.h>
using namespace std;
#define ll long


int solve(int n, vector<int>&dp) {

	if (n <= 2) {
		return n;
	}
	if (dp[n] == -1) {
		dp[n] = solve(n - 1, dp) + solve(n - 2, dp);
	}
	return dp[n];
}

int main() {

	int n;
	cin >> n;
	if (n <= 2) {
		cout << n;
		return 0;
	}
	vector<int>dp(n + 1, -1);
	dp[1] = 1;
	dp[2] = 2;
	solve(n, dp);
	for (int i = 0; i < dp.size(); ++i) {
		cout << dp[i] << " ";
	}
	cout << dp[n];

	return 0;
}