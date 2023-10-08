#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {


	string A = "010110110000";

	int n = A.length();
	int ans = 0;
	int l = -1, r = -1;
	int x = -1, y = -1;

	int sum = 0;

	for (int i = 0; i < n; i++) {
		if (A[i] == '0') {
			sum += 1;
		} else {
			sum += -1;
		}

		if (sum <= 0) {
			sum = 0;
			l = i;
			r = i;
			x = i;
		}

		if (sum > ans) {
			ans = sum;
			x = l;
			y = r;
		}
		r = i;
	}

	if (ans < sum) {
		y = n - 1;
	}

	cout << x << " " << y;

	return 0;
}