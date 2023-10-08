#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {


	vector<vector<int>>A = {
		{5, 17, 100, 11},
		{0, 0, 2, 8}
	};


	vector<int>b = {1, 1};
	vector<int>c = {1, 4};
	vector<int>d = {2, 2};
	vector<int>e = {2, 4};

	int row = A.size();
	int col = A[0].size();

	int query = b.size();

	vector<vector<int>>prefix(row, vector<int>(col, 0));


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



	for (int i = 0; i < query; i++) {
		int x1 = b[i] - 1;
		int y1 = c[i] - 1;
		int x2 = d[i] - 1;
		int y2 = e[i] - 1;

		cout << x1 << " " << y1 << " " << x2 << " " << y2 << "\n";

		if (x1 == 0 and y1 == 0) {
			int ans = prefix[x2][y2];
			cout << ans << "\n";

		} else if (x1 == 0 and y1 != 0) {

			int ans = prefix[x2][y2] - prefix[x2][y1 - 1];
			cout << ans << "\n";

		} else if (y1 == 0 and x1 != 0) {

			int ans = prefix[x2][y2] - prefix[x1 - 1][y2];
			cout << ans << "\n";
		} else {
			int ans = prefix[x2][y2] - prefix[x1 - 1][y2]
			          - prefix[x2][y1 - 1] + prefix[x1 - 1][y1 - 1];

			cout << ans << "\n";
		}
	}


	return 0;
}