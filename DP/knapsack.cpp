#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main() {

	vector<int>A = { 504, 449, 201, 459, 619, 581, 797, 799, 282, 590, 799, 10, 158, 473, 623 };
	vector<int>B = { 39, 93, 39, 80, 91, 58, 59, 92, 16, 89, 57, 12, 3, 35, 73};

	int c = 56;

	int row = A.size();


	// TABULATION
	vector<vector<int>>dp(row + 1, vector<int>(c + 1, 0));


	for (int i = 1; i <= row; i++) {
		for (int j = 1; j <= c; j++) {
			if (B[i - 1] <= j) {
				int temp1 = A[i - 1] + dp[i - 1][j - B[i - 1]];
				int temp2 = dp[i - 1][j];

				dp[i][j] = max(temp2, temp1);
			} else {
				dp[i][j] = dp[i - 1][j];
			}
		}
	}

	cout << dp[row][c] << "\n";

	for (auto q : dp) {
		for (auto w : q) {
			cout << w << " ";
		}
		cout << "\n";
	}

	return 0;
}
