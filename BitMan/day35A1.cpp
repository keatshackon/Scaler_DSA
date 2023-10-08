#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main() {


	vector<int>A = {1, 2, 3, 1, 2, 4};

	int x = 0;
	int n = A.size();

	for (int i = 0; i < n; i++) {
		x ^= A[i];
	}

	int temp = x;
	int k = 0;
	while (true) {

		if (temp & 1 << k) {
			break;
		}
		k++;
	}

	int s1 = 0, s2 = 0;

	for (int i = 0; i < n; i++) {

		if ((A[i] & (1 << k)) >= 1) {
			s1 ^= A[i];
		} else {
			s2 ^= A[i];
		}
	}

	cout << s1 << " " << s2 << "\n";

	return 0;
}