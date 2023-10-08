#include <bits/stdc++.h>
using namespace std;
#define ll long long


int bitonic_key(vector<int>&A) {

	int l = 0;
	int r = A.size() - 2;

	int n = A.size();

	if (A[n - 1] > A[n - 2]) {
		return n - 1;
	}

	int ans = 0;

	while (l <= r) {
		int m = (l + r) / 2;

		if (m == 0) {
			l = m + 1;
			continue;
		}

		if (A[m] > A[m + 1] and A[m] > A[m - 1]) {
			return m;
		} else if (m > 0 and A[m] > A[m - 1]) {
			l =  m + 1;
			ans = m;
		} else {
			r = m - 1;
		}
	}

	return ans;
}

int ascending_part(vector<int>&A, int B, int l, int r) {

	while (l <= r) {
		int mid = (l + r) / 2;

		if (A[mid] == B) {
			return mid;
		} else if (A[mid] > B) {
			r = mid - 1;
		} else {
			l = mid + 1;
		}
	}
	return -1;
}

int descending_part(vector<int>&A, int B, int l, int r) {

	while (l <= r) {
		int mid = (l + r) / 2;

		if (A[mid] == B) {
			return mid;
		} else if (A[mid] > B) {
			l = mid + 1;
		} else {
			r = mid - 1;
		}
	}
	return -1;
}



int main() {


	vector<int>A = {3, 9, 10, 20, 17, 5, 1};
	int B = 20;

	int n = A.size();

	if (n == 1 and A[0] == B) {
		cout << 0 << "\n";
		return 0;
	} else if (n == 1 and A[0] != B) {
		cout << -1 << "\n";
		return 0;
	}

	int peak = bitonic_key(A);

	cout << peak << " " << A[peak] << "\n";


	int res = ascending_part(A, B, 0, peak);

	if (res == -1) {
		int res = descending_part(A, B, peak + 1, n - 1);
		if (res == -1) {
			cout << -1 << "\n";
			return 0;
		} else {
			cout << res << "\n";
			return 0;
		}
	} else {
		cout << res << "\n";
		return 0;
	}





	return 0;
}