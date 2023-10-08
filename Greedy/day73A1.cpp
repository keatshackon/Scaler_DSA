#include <bits/stdc++.h>
using namespace std;
#define ll long long



int main() {

	vector<int>A = {1, 5, 2, 1};

	int n = A.size();

	if (n == 1) {
		return 1;
	}

	vector<pair<int, int>>choc(n);

	if (A[0] > A[1]) {
		choc[0].first = 2;
	} else {
		choc[0].first = 1;
	}

	for (int i = 1; i < n; i++) {
		if (A[i] > A[i - 1]) {
			choc[i].first = choc[i - 1].first + 1;
		} else {
			choc[i].first = 1;
		}
	}

	if (A[n - 1] > A[n - 2]) {
		choc[n - 1].second = 2;
	} else {
		choc[n - 1].second = 1;
	}

	for (int i = n - 2; i >= 0; i--) {
		if (A[i] > A[i + 1]) {
			choc[i].second = choc[i + 1].second + 1;
		} else {
			choc[i].second = 1;
		}
	}

	int ans = 0;

	for (auto q : choc) {
		ans += max(q.first, q.second);
	}

	cout << ans;

	return 0;
}