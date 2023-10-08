#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {

	vector<int>	A = { -1, 10};


	if (A.size() == 1) return A[0];

	int len = A.size();

	int min_so_far = A[0];
	int max_so_far = A[0];
	int ans = A[0];

	// MAINTAING MIN/MAX PRODUCT TILL I TH INDEX TO
	// COMPUTER I+1 TH INDEX.

	for (int i = 1; i < len; i++) {

		int temp = min_so_far;
		min_so_far = min(A[i], min(A[i] * min_so_far, A[i] * max_so_far));
		max_so_far = max(A[i], max(A[i] * temp, A[i] * max_so_far));
		ans = max(ans, max_so_far);
	}

	cout << ans;

	return 0;
}