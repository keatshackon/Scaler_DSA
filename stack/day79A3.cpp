#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000007


int solve(int n, int b, vector<int>&A, vector<vector<int>>&dp) {

	if (b == 0) {
		return 1;
	}
	if (n < 0 and b < 0) {
		return 0;
	}

	int s1 = solve(n - 1, b, A, dp);
	int s2 = 0;

	if (b >= A[n]) {
		s2 = solve(n, b - A[n], A, dp);
	}

	int res = (s1 % MOD + s2 % MOD) % MOD;

	return res;

}


int main() {

	vector<int>A = {1, 2, 3};
	int b = 4;


	int n = A.size();

	vector<vector<int>>dp(n, vector<int>(b + 1, -1));


	cout << solve(n - 1, b, A, dp);


	return 0;
}