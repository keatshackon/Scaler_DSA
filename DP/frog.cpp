#include <bits/stdc++.h>
using namespace std;
#define ll long


// MEMOIZATION FROM RECURSION
int solve(int n, vector<int>&dp, vector<int>v) {

	if (n == 0) {
		return 0;
	}
	if (dp[n] == -1) {
		int k1 = solve(n - 1, dp, v) + abs(v[n] - v[n - 1]);
		int k2 = INT_MAX;
		if (n > 1) {
			k2 = solve(n - 2, dp, v) + abs(v[n] - v[n - 2]);
		}
		dp[n] = min(k1, k2);
	}
	return dp[n];
}

int main() {

	vector<int>v = {30, 10, 60, 10, 60, 50};
	int len = v.size();
	vector<int>dp(len + 1, -1);

	// Method 1 recusrsion or memoizations

	solve(len - 1, dp, v);

	cout << dp[len - 1] << "\n";


	// Method 2 tabulation
	// vector<int>dp(len + 1, -1);
	// dp[0] = 0;

	// for (int i = 1; i < len; i++) {
	// 	int fs = dp[i - 1]  + abs(v[i] - v[i - 1]);
	// 	int ss = INT_MAX;
	// 	if (i > 1) {
	// 		ss = dp[i - 2]  + abs(v[i] - v[i - 2]);
	// 	}
	// 	dp[i] = min(fs, ss);
	// }

	// for (auto q : dp) {
	// 	cout << q << " ";
	// }
	// cout << "\n";
	//cout << dp[len - 1];

	return 0;
}