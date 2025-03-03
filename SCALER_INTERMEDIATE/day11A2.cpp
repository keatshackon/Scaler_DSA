#include<bits/stdc++.h>
using namespace std;
#define ll long long


int main() {

	vector<int> A = {343, 291, 963, 165, 152};

	int minn = INT_MAX;
	int maxx = INT_MIN;

	for (int i = 0; i < A.size(); i++) {
		if (minn > A[i]) {
			minn = A[i];
		}
		if (maxx < A[i]) {
			maxx = A[i];
		}
	}

	int ans = INT_MAX;

	//// o(n)
	int r1 = -1, r2 = -1;
	for (int i = 0; i < A.size(); i++) {
		if (A[i] == minn) {
			r1 = i;
		}
		if (A[i] == maxx and r1 != -1) {
			ans =  min(ans, i - r1 + 1);
		}

		if (A[i] == maxx) {
			r2 = i;
		}
		if (A[i] == minn and r2 != -1) {
			ans =  min(ans, i - r2 + 1);
		}
	}



	cout << ans;


	//// o(n^2)

	// for (int i = 0; i < A.size(); i++) {
	// 	if (A[i] == minn) {
	// 		for (int j = 0; j < A.size(); j++) {
	// 			if (A[j] == maxx) {
	// 				int temp = max(i, j) - min(i, j) + 1;
	// 				ans = min(ans, temp);
	// 			}
	// 		}
	// 	}
	// }

	return 0;

}