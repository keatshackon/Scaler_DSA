#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007


int solve(int n, vector<int>&dp) {

	if (n == 0) {
		return 0 ;
	}

	if (dp[n] != -1) {
		return dp[n];
	}

	// WHEN WE HAVE TO CHOOSE MIN/MAX OUT OF MORE THAN TWO OPTIONS.
	int mini = INT_MAX;
	// ITERATING OVER ALL THE OPTIONS.
	for (int i = 1; i * i <= n; i++) {
		mini = min(mini, solve(n - (i * i), dp));
	}
	return dp[n] = 1 + mini;
}


int main() {


	int n = 6;
	vector<int>dp(n + 1, -1);
	dp[0] = 0;

	//solve(n, dp);



	for (int i = 1; i <= n; i++) {
		int ans = INT_MAX;
		for (int j = 1; j * j <= i; j++) {
			ans = min(ans, dp[i - j * j]);
		}
		dp[i] = 1 + ans;
	}

	cout << dp[n] << "\n";

	return 0;
}


