#include <,bits/stdc++.h>
using namespace std;
#define ll long long


int solve(const vector<int>&A, int B) {

	int l = 0;
	int r = A.size() - 1;

	while (l <= r) {
		int mid = (l + r) / 2;

		if (A[mid] == B) {
			return mid;
		} else if (A[mid] >= A[0]) {
			if (B >= A[0] and A[mid] > B) {
				r = mid - 1;
			} else {
				l = mid + 1;
			}
		} else {
			if (B > A[mid] and B < A[0]) {
				l = mid + 1;
			} else {
				r = mid - 1;
			}
		}
	}

	return -1;
}


int main() {


	vector<int>A = {4, 5, 6, 7, 0, 1, 2, 3};
	int B = 4;

	solve(A, B);

	return 0;
}