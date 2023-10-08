#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main() {


	vector<vector<int>>A = {
		{ -5, -4, -3},
		{1, 2, 3},
		{2, 2, 4}
	};

	int row =  A.size();
	int col = A[0].size();

	vector<vector<ll>>prefix(row, vector<ll>(col, 0));

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {

			if (j == 0) {
				prefix[i][j] = A[i][j];
			} else {
				prefix[i][j] = prefix[i][j - 1] + A[i][j];
			}
		}
	}

	for (int i = 0; i < col; i++) {
		for (int j = 1; j < row; j++) {
			prefix[j][i] = prefix[j - 1][i] + prefix[j][i];
		}
	}


	for (auto q : prefix) {
		for (auto w : q) {
			cout << w << " ";
		}
		cout << "\n";
	}


	int x2 = row - 1;
	int y2 = col - 1;

	int ans = INT_MIN;

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {

			if (x1 == 0 and y1 == 0) {
				int temp = prefix[x2][y2];
				ans = max(ans, temp);

			} else if (x1 == 0 and y1 != 0) {

				int ans = (prefix[x2][y2] % MOD - prefix[x2][y1 - 1] % MOD) % MOD;
				if (ans < 0) {
					res.push_back(ans + MOD);
				} else {
					res.push_back(ans);
				}
			} else if (y1 == 0 and x1 != 0) {

				int ans = (prefix[x2][y2] % MOD - prefix[x1 - 1][y2] % MOD ) % MOD;
				if (ans < 0) {
					res.push_back(ans + MOD);
				} else {
					res.push_back(ans);
				}

			} else {

				int temp = (prefix[x2][y2] % MOD - prefix[x1 - 1][y2] % MOD ) % MOD;

				temp = (temp % MOD  - prefix[x2][y1 - 1] % MOD ) % MOD;

				temp = (temp % MOD + prefix[x1 - 1][y1 - 1] % MOD) % MOD;

				// int ans = prefix[x2][y2] - prefix[x1 - 1][y2]
				//           - prefix[x2][y1 - 1] + prefix[x1 - 1][y1 - 1];


				if (temp < 0) {
					res.push_back(temp + MOD);
				} else {
					res.push_back(temp);
				}
			}

		}
	}


	cout << ans << "\n";

	return 0;
}