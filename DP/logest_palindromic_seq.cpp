#include <bits/stdc++.h>
using namespace std;
#define ll long long


int solve(int n, int m, string &A, string &B, vector<vector<int>>&dp) {

	if (n < 0 or m < 0) {
		return 0;
	}

	if (A[n] == B[m]) {
		return 1 + solve(n - 1, m - 1, A, B, dp);
	} else {
		int s1 = solve(n - 1, m, A, B, dp);
		int s2 = solve(n, m - 1, A, B, dp);

		return max(s1, s2);
	}
}

int main() {


	string A = "aedsead";

	string B = A;

	reverse(B.begin(), B.end());

	int n = A.length();

	vector<vector<int>>dp(n + 1, vector<int>(n + 1, -1));
	cout << solve(n - 1, n - 1, A, B, dp) << "\n";

	return 0;
}