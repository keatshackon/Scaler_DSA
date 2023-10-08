#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007


int solve1(int ind, int prev, int A, vector<vector<int>>&dp) {

	if (ind == 0) {
		dp[ind][prev] = 1;
		return 1;
	}

	if (dp[ind][prev] != -1) return dp[ind][prev];

	int s1 = 0, s2 = 0, s3 = 0;

	if (prev == 0) {
		s1 = solve1(ind - 1, !prev, A, dp);
		s2 = solve1(ind - 1, prev, A, dp);
	} else {
		s3 = solve1(ind - 1, !prev, A, dp);
	}

	return dp[ind][prev] = (s1 % MOD + s2 % MOD  + s3 % MOD) % MOD;
}


int main() {

	int A = 3;

	vector<vector<int>>dp(A + 1, vector<int>(2, -1));
	solve1(A, 0, A, dp);

	for (auto q : dp) {
		for (auto w : q) {
			cout << w << " ";
		}
		cout << "\n";
	}

	return 0;
}