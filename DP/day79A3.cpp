#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000007


int solve(int n, int b, vector<int>&A, vector<vector<int>>&dp) {

	if (b == 0) {
		return 1;
	}
	if (n < 0 or b < 0) {
		return 0;
	}

	if (dp[n][b] != -1) return dp[n][b];

	int s1 = solve(n - 1, b, A, dp);
	int s2 = 0;

	if (b >= A[n]) {
		s2 = solve(n, b - A[n], A, dp);
	}

	int res = (s1 % MOD + s2 % MOD) % MOD;

	return dp[n][b] = res;

}


int main() {

	vector<int>A = {18, 24, 23, 10, 16, 19, 2, 9, 5, 12, 17, 3, 28, 29, 4, 13, 15, 8};
	int b = 458;


	int n = A.size();

	//vector<vector<int>>dp(n, vector<int>(b + 1, -1));


	//cout << solve(n - 1, b, A, dp) << "\n";

	vector<int>prev(b + 1, 0);

	for (int i = 1; i <= b; i++) {
		prev[i] = (i % A[0] == 0);
	}

	for (int i = 1; i < n; i++) {
		vector<int>cur(b + 1, 0);
		cur[0] = 1;
		for (int j = 1; j <= b; j++) {

			// IF  NOT TAKEN
			int s1 = 0, s2 = 0;
			s1 = prev[j];

			// IF TAKEN
			if (j >= A[i]) {
				s2 = cur[j - A[i]];
			}

			cur[j] = (s1 % MOD + s2  % MOD) % MOD;
		}
		prev = cur;
	}

	cout << prev[b];

	return 0;
}