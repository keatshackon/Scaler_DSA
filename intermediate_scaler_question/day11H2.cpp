#include<bits/stdc++.h>
using namesapace std;
#define ll long long


int main() {

	vector<int> A = {1, 3};

	for (int i = 0; i < A.size(); i++) {
		if (maxx < A[i]) {
			maxx = A[i];
		}
		if (A[i] < minn) {
			minn = A[i];
		}
	}

	cout << maxx << " " << minn << '\n';

	return 0;
}