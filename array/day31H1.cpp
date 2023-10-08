#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main() {

	vector<int>A = {0, 3, 7, 6, 4, 0, 5, 5, 5};

	reverse(A.begin(), A.end());

	int n = A.size();

	int carry = 1;

	for (int i = 0; i < n; i++) {
		carry += A[i];

		if (carry >= 10) {
			A[i] = carry % 10;
			carry /= 10;
		} else {
			A[i] = carry;
			carry = 0;
		}
	}

	if (carry != 0) {
		A.push_back(carry);
	}

	reverse(begin(A), end(A));

	vector<int>res;


	int k = 0;
	int f = 0;
	while (k < A.size()) {
		if (A[k] == 0 and f == 0) {
			k++;
		} else {
			f = 1;
			res.push_back(A[k]);
			k++;
		}
	}

	// return res;

	return 0;
}