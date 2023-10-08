#include <bits/stdc++.h>
using namespace std;
#define ll long long

int solve(int i, int n, vector<int>&A, vector<int>&dp) {

	if (i >= n) {
		return 0;
	}

	if (dp[i] != - 1) return dp[i];

	int s1 = A[i] + solve(i + 2, n, A, dp);
	int s2 = solve(i + 1, n, A, dp);

	return dp[i] = max(s1, s2);
}

int main() {


	vector<vector<int>>A = {
		{74, 37, 82, 1},
		{66, 38, 16, 1}
	};

	vector<int>nums;
	int len = A[0].size();

	for (int i = 0; i < len; i++) {
		nums.push_back(max(A[0][i], A[1][i]));
	}
	for (auto q : nums) {
		cout << q << " ";
	}
	cout << "\n";

	int n = nums.size();
	vector<int>dp(n, -1);

	cout << solve(0, n, nums, dp);



	// TABULATION
	// vector<int>dp2(n, -1);
	// dp2[0] = nums[0];
	// dp2[1] = max(nums[0], nums[1]);
	// for (int i = 2; i < n; i++) {

	// 	int s1 = INT_MIN;
	// 	int s2 = INT_MIN;

	// 	s1 = nums[i] + dp2[i - 2];
	// 	s2 = dp2[i - 1];

	// 	dp2[i] = max(s1, s2);
	// }

	// for (auto q : dp2) {
	// 	cout << q << " ";
	// }

	// cout << dp2[n - 1];


	return 0;
}