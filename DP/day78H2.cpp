#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main() {


	vector<int>A = {2, 4, 6};
	vector<int>B = {2, 1, 3};
	vector<int>C = {2, 5, 3};


	int cap = 0;
	int len = A.size();

	for (auto q : A) {
		cap = max(cap, q);
	}

	// TABULATION
	vector<vector<int>>dp(len + 1, vector<int>(cap + 1, 0));


	for (int i = 1; i <= len; i++) {
		for (int j = 1; j <= cap; j++) {

			if (B[i - 1] <= j) {
				int temp1 = C[i - 1] + dp[i][j - B[i - 1]];
				int temp2 = dp[i - 1][j];

				dp[i][j] = max(temp2, temp1);
			} else {
				dp[i][j] = dp[i - 1][j];
			}
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