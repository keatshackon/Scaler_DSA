#include <bits/stdc++.h>
using namespace std;
#define ll long long

int solve1(int n, vector<int>&dp) {

	if (n <= 1) {
		return n;
	}
	if (dp[n] == -1) {
		dp[n] = solve1(n - 1, dp) + solve1(n - 2, dp);
	}
	return dp[n];
}

int solve2(int n) {

	vector<int>dp(n + 1, -1);
	dp[0] = 0;
	dp[1] = 1;

	for (int i = 2; i <= n; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}
	return dp[dp.size() - 1];
}

int solve3(int n) {

	int prev = 1;
	int prev2 = 0;
	int temp;
	int cnt = 0;
	for (int i = 2; i <= n; i++) {
		temp = prev + prev2;
		prev2 = prev;
		prev = temp;
		cnt++;
	}
	cout << cnt << "\n";
	return temp;
}

int main() {

	ll n;
	cin >> n;
	// vector<int>dp(n + 1 , -1);
	// dp[0] = 0;
	// dp[1] = 1;
	// solve1(n, dp);
	// for (auto q : dp) {
	// 	cout << q << " ";
	// }
	// cout << dp[n] << "\n";


	// Method 2
	//cout << solve2(n);


	// Method 3
	cout << solve3(n);

	return 0;
}