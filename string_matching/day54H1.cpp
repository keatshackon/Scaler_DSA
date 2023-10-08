#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main() {


	string A = "acd";
	string B = "bay";


	int n = A.length();
	int m = B.length();

	int f1 = 1, f2 = 0, i = 1, j = 0;

	string  ans = "";
	ans += A[0];

	while (i < n and j < m) {
		if (A[i] < B[j]) {
			ans += A[i];
			i++;
			f1 = 1;
		} else {
			ans += B[j];
			j++;
			f2 = 1;
		}

		if (f1 == 1 and f2 == 1) {
			break;
		}
	}

	if (i == n and j < m and f2 == 0) {
		ans += B[j];
	} else if (j == m and i < n and f1 == 0) {
		ans += A[i];
	}

	cout << ans;

	return 0;
}