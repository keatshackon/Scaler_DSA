#include <bits/stdc++.h>
using namespace std;
#define ll long long


int solve(int i, int len, vector<int>&A, vector<vector<int>>&dp) {

	if (len == 0) {
		return 0;
	}
	if (i >= A.size() or len < 0) {
		return -1e9;
	}

	int s1 = solve(i + 1, len, A, dp);
	int s2 = 0;
	if (len >= i + 1) {
		s2 = A[i] + solve(i, len - (i + 1), A, dp);
	}


	return max(s1, s2);
}



int main() {

	vector<int>A = {1, 5, 2, 5, 6};
	int len = A.size();

	vector<vector<int>>dp(len, vector<int>(len + 1, -1));

	cout << solve(0, len, A, dp);

	return 0;
}