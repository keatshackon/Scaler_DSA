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

	int a = 0;
	int b = 1;

	if (n == 0 or n == 1) {
		cout << n;
		return 0;
	}

	// USING TABULATION SC: O(N)(STACK) AND SC : O()N FOR DP ARRAY AND TC : O(N)

	vector<int>dp(n + 1, -1);
	dp[0] = 0;
	dp[1] = 1;

	cout << solve(2, n, dp);



	// USING TABULATION SC: O(1) AND TC : O(N)

	// for (int i = 2; i <= n; i++) {
	// 	int cur = (a % MOD + b % MOD) % MOD;
	// 	a = b;
	// 	b = cur;
	// }
	// cout << b << "\n";

	return 0;
}


