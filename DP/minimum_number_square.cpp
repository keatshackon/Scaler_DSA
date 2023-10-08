#include <bits/stdc++.h>
using namespace std;
#define ll long long

// MEMOIZATIONS
int solve(vector<int>&dp, int n) {

	if (n == 0) {
		return 0;
	}

	if (dp[n] != -1) {
		return dp[n];
	}
	int minn = INT_MAX;
	for (int i = 1; i * i <= n; i++) {
		minn = min(minn, solve(dp, (n - i * i)));
	}
	return dp[n] = 1 + minn;
}
int main() {

	int n;
	cin >> n;
	vector<int>dp(n + 1, -1);
	solve(dp, n);

	cout << dp[n] << "\n";

	for (auto q : dp) {
		cout << q << " ";
	}
	cout << "\n";

	return 0;
}
