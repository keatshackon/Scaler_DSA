#include <bits/stdc++.h>
using namespace std;
#define ll long long

int solve(int i, int j, vector<int>&A, vector<vector<int>>&dp) {

	if (i == j) {
		return 0;
	}

	if (dp[i][j] != -1) return dp[i][j];

	int mini = 1e9;

	for (int k = i; k < j; k++) {
		int step = A[i - 1] * A[k] * A[j] + solve(i, k, A, dp) +
		           solve(k + 1, j, A, dp);
		mini = min(mini, step);
	}

	return dp[i][j] = mini;
}


int main() {


	vector<int>A = {40, 20, 30, 10, 30};


	int j = A.size() ;
	int i = 1;

	vector<vector<int>>dp(j, vector<int>(j, -1));

	cout << solve(i, j - 1, A, dp);

	return 0;
}