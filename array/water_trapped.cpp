#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main() {


	vector<int>A = { 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};


	int n = A.size();

	vector<int>rg(n, 0);
	rg[n - 1] = A[n - 1];

	// Building The RightMax Array.
	for (int i = n - 2; i >= 0; i--) {
		rg[i] = max(A[i], rg[i + 1]);
	}

	int ans = 0;

	// Maintaining LeftMax Array.
	int maxi = A[0];

	for (int i = 1; i < n; i++) {
		// Maintaining LeftMax Array.
		maxi = max(A[i], maxi);
		ans += min(rg[i], maxi) - A[i];
	}

	// return ans;

	return 0;
}