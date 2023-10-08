#include <bits/stdc++.h>
using namespace std;
#define ll long long


bool solve(int ind, int target, vector<int>&A, vector<vector<bool>>&dp) {

	if (target == 0) return true;

	if (ind == 0) {
		if (A[0] == target) return true;
		else return false;
	}

	if (dp[ind][target] != -1) return dp[ind][target];

	bool s1 = solve(ind - 1, target, A, dp);

	bool s2 = false;

	if (target >= A[ind]) {
		s2 = solve(ind - 1, target - A[ind], A, dp);
	}

	return dp[ind][target] = s1 or s2;
}

int main() {


	vector<int>A = {2, 3, 1, 1, 2, 3, 1, 1, 2, 3, 1, 1, 2, 3, 1, 1, 2, 3, 1, 1, 2, 3, 1, 1, 2, 3, 1, 1, 2, 3, 1, 1, 2, 3, 1, 1, 2, 3, 1, 1, 2, 3, 1, 1, 2, 3, 1, 1, 2, 3, 1, 1, 2, 3, 1, 1, 2, 3, 1, 1, 2, 3, 1, 1, 2, 3, 1, 1, 2, 3, 1, 1, 2, 3, 1, 1};
	int target = 1000;

	int n = A.size();

	cout << n << "\n";

	vector<vector<bool>>dp(n, vector<bool>(target + 1, -1));

	//cout << solve(n - 1, target, A, dp);


	vector<int>prev(target + 1, 0);

	prev[A[0]] = 1;

	for (int i = 1; i < n; i++) {
		vector<int>cur(target + 1, 0);
		cur[0] = 1;
		for (int j = 1; j <= target; j++) {

			//  Not Take
			bool s1 = prev[j];

			// take
			int s2 = false;
			if (target >= A[i]) {
				s2 = prev[target - j];
			}
			cur[j] = s1 or s2;
		}
		prev = cur;
	}

	cout << prev[target] << "\n";

	return 0;
}