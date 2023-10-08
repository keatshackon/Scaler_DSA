#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main() {


	vector<vector<int>>A = {
		{ -2, -3, 3},
		{ -5, -10, 1},
		{10, 30, -5}
	};


	int row = A.size();
	int col = A[0].size();

	vector<vector<int>>dp(row, vector<int>(col, 0));



	for (int i = row - 1; i >= 0; i--) {
		for (int j = col - 1; j >= 0; j--) {

			if (i == row - 1 and j == col - 1) {
				dp[row - 1][col - 1] = abs(A[row - 1][col - 1]) + 1;
				continue;
			}

			int s1 = 1e9;
			int s2 = 1e9;
			if (j + 1 < col) {
				s1 = dp[i][j + 1];
			}
			if (i + 1 < row) {
				s2 = dp[i + 1][j];
			}

			dp[i][j] = max(1, min(s1, s2) - A[i][j]);
		}
	}


	for (auto q : dp) {
		for (auto w : q) {
			cout << w << " ";
		}
		cout << "\n";
	}

	return 0;
}