#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007

int solve(int a, int b, vector<vector<int>>&dp) {



	if (a == 0) {
		if (b == 0) {
			return 1;
		} else {
			return 0;
		}
	}

	int sum = 0;
	for (int i = 0; i <= 9; i++) {
		sum = (sum % MOD + solve(a - 1, b - i, dp) % MOD) % MOD;
	}
	return sum;
}

int main() {


	int A = 1;
	int B = 3;

	vector<vector<int>>dp;


	int ans = 0;
	for (int i = 1; i <= 9; i++) {
		ans += solve(A - 1, B - i, dp);
	}
	cout << ans;


	return 0;
}