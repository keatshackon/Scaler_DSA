#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {


	vector<vector<int>>A = {{1, 2}, {3, 4}};


	int row = A.size();
	int col = A[0].size();


	int ans = 0;

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			ans += A[i][j] * (i + 1) * (j + 1) * (row - i) * (col - j);
		}
	}

	cout << ans << "\n";

	return 0;
}