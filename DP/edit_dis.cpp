#include<bits/stdc++.h>
using namespace std;
#define ll long long


int solve(int n, int m, string &A, string &B, vector<vector<int>>&dp) {


	if (m == 0) {
		return n;
	}
	if (n == 0) {
		return m;
	}

	if (dp[n][m] != -1) return dp[n][m];

	if (A[n - 1] == B[m - 1]) {
		return dp[n][m] = solve(n - 1, m - 1, A, B, dp);
	} else {

		// insert
		int s1 = 1 + solve(n, m - 1, A, B, dp);

		// Replace
		int s2 = 1 + solve(n - 1, m - 1, A, B, dp);

		// Remove;
		int s3 = 1 + solve(n - 1, m, A, B, dp);


		return dp[n][m] = min(s1, min(s2, s3));
	}
}


int main() {

	string A = "Anshuman";
	string B = "Antihuman";


	int n = A.length();
	int m = B.length();

	vector<vector<int>>dp(n + 1, vector<int>(m + 1, 0));

	//cout << solve(n , m, A, B, dp) << "\n";

	for (int i = 0; i < m; i++) {
		dp[0][i] = i;
	}

	for (int i = 0; i < n; i++) {
		dp[i][0] = i;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {

			if (A[i - 1] == B[j - 1]) {
				dp[i][j] = solve(i - 1, j - 1, A, B, dp);
			} else {

				// insert
				int s1 = 1 + solve(i, j - 1, A, B, dp);

				// Replace
				int s2 = 1 + solve(i - 1, j - 1, A, B, dp);

				// Remove;
				int s3 = 1 + solve(i - 1, j, A, B, dp);


				dp[i][j] = min(s1, min(s2, s3));
			}
		}
	}

	cout <<

	for (auto q : dp) {
		for (auto w : q) {
			cout << w << " ";
		}
		cout << "\n";
	}



	return 0;
}
