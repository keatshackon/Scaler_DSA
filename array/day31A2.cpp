#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {


	vector<int>A = { -2, 1, -3, 4, -1, 2, 1, -5, 4};


	// Method-1 O(N^2) approache.

	int n = A.size();
	int ans = INT_MIN;

	// for (int i = 0; i < n; i++) {
	// 	int sum = 0;
	// 	for (int j = i; j < n; j++) {
	// 		sum += A[j];
	// 		ans = max(ans, sum);
	// 	}
	// }

	// cout << ans << "\n";


	// Method - 2 Kadane Algorithm.
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += A[i];
		ans = max(ans, sum);
		if (sum < 0) {
			sum = 0;
		}
	}

	cout << ans << "\n";


	return 0;
}
