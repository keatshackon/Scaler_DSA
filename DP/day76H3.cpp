#include <bits/stdc++.h>
using namespace std;
#define ll long long

nt solve(int i, int len, string s, vector<int>&dp) {

	if (i == len) {
		return 1;
	}
	if (s[i] == '0') {
		return 0;
	}

	if (dp[i] != - 1) return dp[i];

	int s1 = solve(i + 1, len, s, dp);
	int s2 = 0;
	if (i + 1 < len and s[i] == '1' or s[i] == '2' and s[i + 1] >= '0' and s[i + 1] <= '6') {
		s2 = solve(i + 2, len, s, dp);
	}

	return dp[i] = (s1 % MOD + s2 % MOD) % MOD;

}

int main() {


	string A = "12";

	int len = A.length();
	vector<int>dp(len, -1);

	return solve(0, len, A, dp);


	return 0;
}