#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() {

	vector<int> A = {1 , 1, 1, 2, 3, 5, 7};

	if (A.size() < 3) {
		cout << A[0];
	}

	int x = 0, z = 0;
	int res1 = INT_MAX, res2 = INT_MAX;
	x++;
	z++;

	for (int i = 0; i < A.size(); i++) {

		if (A[i] == res1) {
			x++;
		} else if (A[i] == res2) {
			z++;
		} else if (x == 0) {
			res1 = A[i];
			x++;
		} else if (z == 0) {
			res2 = A[i];
			z++;
		} else {
			x--;
			z--;
		}
	}
	cout << res1 << " " << res2 << "\n";
	int cnt1 = 0, cnt2 = 0;
	for (int i = 0; i < A.size(); i++) {
		if (A[i] == res1) {
			cnt1++;
		}
	}
	if (cnt1 > A.size() / 3) {
		cout << res1;
	}


	for (int i = 0; i < A.size(); i++) {
		if (A[i] == res2) {
			cnt2++;
		}
	}
	if (cnt2 > A.size() / 3) {
		cout << res2;
	}
	return 0;
}


