#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main() {

	vector<vector<int>>A = {
		{1, 2, 3},
		{4, 5, 6},
		{7, 8, 9}
	};

	int B = 2;

	int row = A.size();
	int col = A[0].size();

	int i = 0;
	int j = col - 1;

	int ans = INT_MAX;

	while (i < row and j >= 0) {

		if (A[i][j] == B) {
			ans = min(ans, (i + 1) * 1009 + (j + 1));
			j--;
		} else if (A[i][j] > B) {
			j--;
		} else {
			i++;
		}
	}

	if (ans == INT_MAX) {
		cout << -1 << "\n";
		return 0;
	}

	cout << ans << "\n";

	return 0;
}