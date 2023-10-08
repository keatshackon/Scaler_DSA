#include <bits/stdc++.h>
using namespace std;
#define ll long long


int solve(vector<int>&A, int place, int c) {


	int n = A.size();
	c -= 1;
	int sum = 0;
	int res = A[0];

	for (int i = 1; i < n; i++) {
		if ((A[i] - res) >= place) {
			c--;
			res = A[i];
		}
		if (c == 0) {
			return true;
		}
	}

	if (c == 0) {
		return true;
	}
	return false;
}

int main() {


	vector<int>A = {82, 61, 38, 88, 12, 7, 6, 12, 48, 8, 31, 90, 35, 5, 88, 2, 66, 19, 5, 96, 84, 95};
	int B = 8;

	sort(A.begin(), A.end());

	int n = A.size();
	int minn = INT_MAX;
	int maxx = INT_MIN;

	for (auto q : A) {
		if (q > maxx) {
			maxx = q;
		}
		if (q < minn) {
			minn = q;
		}
	}

	cout << minn << " " << maxx << "\n";

	int l = 1;
	int r = maxx - minn;
	int ans = 0;

	cout << l << " " << r << "\n";

	while (l <= r) {
		int mid = (l + r) / 2;

		bool res = solve(A, mid, B);

		if (res) {
			ans = mid;
			l = mid + 1;
		} else {
			r = mid - 1;
		}
	}

	cout << ans;

	return 0;
}