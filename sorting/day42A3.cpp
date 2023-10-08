#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main() {


	if (A.size() == 1) return 1;

	sort(A.begin(), A.end());

	for (int i = 1; i < A.size(); i++) {
		if ((A[i] - A[i - 1]) != 1) {
			return 0;
		}
	}

	cout << 1;

	return 0;
}