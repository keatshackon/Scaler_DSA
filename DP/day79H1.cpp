#include <bits/stdc++.h>
using namespace std;
#define ll long long

int solve(int n, int m, string &A, string &B, vector<vector<int>>&dp) {

	if (m == 0) {
		return 1;
	}
	else if (n == 0) {
		return 0;
	}

	if (dp[n][m] != -1) {
		return dp[n][m];
	}

	int s1 = 0, s2 = 0, s3 = 0;

	if (A[n - 1] == B[m - 1]) {
		s1 = solve(n - 1, m, A, B, dp);
		s2 = solve(n - 1, m - 1, A, B, dp);


	} else {
		s3 = solve(n - 1, m, A, B, dp);
	}
	return dp[n][m] = s1 + s2 + s3;

}

int main() {


	string A =  "rabbbbbit";
	string B = "rabbbbbbbbit";

	int n = A.length();
	int m = B.length();


	vector<vector<int>>dp(n + 1, vector<int>(m + 1, 0));
	//cout << solve(n, m, A, B, dp);



	// METHOD-2  TABULATIONS APPROACHES;

	for (int i = 0; i < n; i++) {
		dp[i][0] = 1;
	}


	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; ++j) {

			int s1 = 0, s2 = 0, s3 = 0;
			if (A[i - 1] == B[j - 1]) {
				s1 = dp[i - 1][j];
				s2 = dp[i - 1][j - 1];

			} else {
				s3 = dp[i - 1][j];
			}
			dp[i][j] = s1 + s2 + s3;

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