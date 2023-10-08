#include <bits/stdc++.h>
using namespace std;
#define ll long long


bool solve(int ind, int target, vector<int>&A, vector<vector<bool>> &dp) {

	if (target == 0) return true;
	if (ind == 0) return A[0] == target;

	int s1 = solve(ind - 1, target, A, dp);
	int s2 = false;

	if (target >= A[ind]) {
		s2 = solve(ind - 1, target - A[ind], A, dp);
	}

	return dp[ind][target] = s1 or s2;

}

int main() {


	vector<int>A = {2, 3, 5, 14};

	int n = A.size();

	int total = accumulate(A.begin(), A.end(), 0);

	if (total % 2  == 1) {
		cout << "False";
		return 0;
	}

	int target = total / 2;

	vector<vector<bool>>dp(n, vector<bool>(target + 1, 0));

	//cout << solve(n - 1, target, A, dp);


	for (int i = 0; i < n; i++) {
		dp[i][0] = 1;
	}
	dp[0][A[0]] = 1;


	for (int i = 1; i < n; i++) {
		for (int j = 1; j <= target; j++) {

			bool s1 = dp[i - 1][j];

			bool s2 = false;
			if (j >= A[i]) {
				s2 = dp[i - 1][j - A[i]];
			}
			dp[i][j] = s1  or s2;
		}
	}

	cout << dp[n - 1][target];
	return 0;
}