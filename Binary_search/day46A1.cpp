#include <bits/stdc++.h>
using namespace std;
#define ll long long



int solve(int A) {

	int l = 1;
	int r = A - 2;

	int ans = -1;

	while (l <= r) {

		long mid = ((long long)l + r) / 2;

		if (mid * mid == A) {
			return mid;
		} else if (mid * mid < A) {
			ans = mid;
			l = mid + 1;
		} else {
			r = mid - 1;
		}
	}

	return ans;

}

int main() {

	int A = INT_MAX;

	cout << solve(A);


	return 0;
}