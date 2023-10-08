#include <bits/stdc++.h>
using namespace std;
#define ll long long

int size = 9;

int solve(int n, vector<int> &v, int k) {

	if (k == 0) {
		return 0;
	}
	if (n == -1) {
		return 9;
	}

	if (k >= v[n]) {
		return min(1 + solve(n - 1, v, k - v[n]) , solve(n - 1, v, k));
	} else {
		return solve(n - 1, v, k);
	}
}

int main() {

	vector<int>v = {7, 4, 9, 6, 10, 14, 11};

	// for (int i = 1; i <= 10000; i++) {
	// 	v.push_back(i);
	// }

	int n = v.size();
	int k = 22;
	vector<vector<int>>dp(n + 1, vector<int>(k + 1, -1));

	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= k; j++) {
			dp[i][j] = -1;
		}
	}
	cout << solve(n - 1 , v, k);
	//cout << dp[n][k];
	//cout << "\n";
	// for (int i = 0; i <= n; i++) {
	// 	for (int j = 0; j <= k; j++) {
	// 		cout << dp[i][j] << "  " ;
	// 	}
	// 	cout << "\n";
	// }
	return 0;
}