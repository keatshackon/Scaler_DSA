#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007


int solve(int cnt, int n, vector<int>&dp) {

	if (cnt == n) {
		return (dp[cnt - 1] % MOD + dp[cnt - 2] % MOD) % MOD;
	}
	if (dp[cnt] != -1) {
		return dp[cnt];
	}

	dp[cnt]  = (dp[cnt - 1] % MOD + dp[cnt - 2] % MOD) % MOD;
	return solve(cnt + 1, n, dp);
}


int main() {


	int n;
	cin >> n;

	int a = 1;
	int b = 2;

	if (n == 1 or n == 2) {
		cout << n;
		return 0;
	}

	// USING TABULATION SC: O(N)(STACK) AND SC : O()N FOR DP ARRAY AND TC : O(N)

	vector<int>dp(n + 1, -1);
	dp[1] = 1;
	dp[2] = 2;

	cout << solve(3, n, dp);

	// USING TABULATION SC: O(1) AND TC : O(N)

	// for (int i = 3; i <= n; i++) {
	// 	int cur = (a % MOD + b % MOD) % MOD;
	// 	a = b;
	// 	b = cur;
	// }
	// cout << b << "\n";

	return 0;
}


