#include <bits/stdc++.h>
using namespace std;
#define ll long long


// PASS THE STRING S1 AND S2 WITH REFERENCES.
int solve(int i, int j, string &s1, string &s2, vector<vector<int>>&dp) {

	if (i == 0  or j == 0) {
		return 0;
	}

	if (dp[i][j] != -1 ) return dp[i][j];

	if (s1[i - 1] == s2[j - 1]) {
		return dp[i][j] = 1 + solve(i - 1, j - 1, s1, s2, dp);
	} else {
		int k1 = solve(i - 1, j, s1, s2, dp);
		int k2 = solve(i, j - 1, s1, s2, dp);

		return dp[i][j] = max(k1, k2);
	}
}

int main() {


	string s1 = "ecd";
	string s2 = "csd";

	int n = s1.length();
	int m = s2.length();

	vector<vector<int>>dp(n + 1, vector<int>(m + 1, -1));

	cout << solve(n, m, s1, s2, dp) << "\n";

	// for (int i = 1; i <= n; i++) {
	// 	for (int j = 1; j <= m; j++) {

	// 		if (s1[i - 1] == s2[j - 1]) {
	// 			dp[i][j] = 1 + dp[i - 1][j - 1];
	// 		} else {
	// 			int k1 =  dp[i - 1][j];
	// 			int k2 =  dp[i][j - 1];

	// 			dp[i][j] = max(k1, k2);
	// 		}
	// 	}
	// }

	for (auto q : dp) {
		for (auto w : q) {
			cout << w << " ";
		}
		cout << "\n";
	}

	// cout << dp[n][m] << "\n";

	return 0;
}