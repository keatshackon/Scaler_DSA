#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main() {

	vector<int>A = {0, 1, 0, 3, 1, 4, 6, 8};

	int ans = 0;
	vector<int>right(A.size());
	right[right.size() - 1] =  A[A.size() - 1];
	for (int i = right.size() - 2; i >= 0; i--) {
		right[i] = max(A[i], right[i + 1]);
	}

	for (auto q : right) {
		cout << q << " ";
	}
	cout << "\n";

	int left = A[0];

	for (int i = 1; i < A.size() - 1; i++) {
		left = max(left, A[i]);
		ans += min(left, right[i]) - A[i];
	}

	cout << ans;


	return 0;
}
