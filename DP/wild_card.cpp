#include <bits/stdc++.h>
using namespace std;
#define ll long long

int solve(int i, int j, const string &A, const string &B, vector<vector<int>>&dp) {

	if (i < 0) {
		for (int ii = 0; ii <= j; ii++) {
			if (B[ii] != '*') {
				return 0;
			}
		}
		return 1;
	}
	if (j < 0) {
		return 0;
	}

	if (dp[i][j] != - 1) return dp[i][j];

	if (A[i] == B[j] or B[j] == '?') {
		return dp[i][j] = solve(i - 1, j - 1, A, B, dp);
	} else if (B[j] == '*') {
		bool s1 = solve(i - 1, j, A, B, dp);
		bool s2 = solve(i, j - 1, A, B, dp);

		return dp[i][j] = s1 or s2;
	} else {
		return dp[i][j] = 0;
	}
}


int main() {

	string A = "bcd";
	string B = "*b***cd";


	int n = A.length();
	int m = B.length();

	vector<vector<int>>dp(n + 1, vector<int>(m + 1, 0));


	dp[0][0] = 1;

	for (int i = 1; i <= m; i++) {
		int f = true;
		for (int k = 1; k <= i; k++) {
			if (B[k - 1] != '*') {
				f = false;
				break;
			}
		}
		dp[0][i] = f;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {

			if (A[i - 1] == B[j - 1] or B[j - 1] == '?') {
				dp[i][j] = dp[i - 1][j - 1];
			} else if (B[j - 1] == '*') {
				bool s1 = dp[i - 1][j];
				bool s2 = dp[i][j - 1];

				dp[i][j] = s1 or s2;
			} else {
				dp[i][j] = 0;
			}
		}
	}

	for (auto q : dp) {
		for (auto w : q) {
			cout << w << " ";
		}
		cout << "\n";
	}

	cout << dp[n][m] << "\n";

	return 0;
}