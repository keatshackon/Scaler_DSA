#include<bits/stdc++.h>
using namespace std;
#define ll long long


int main() {

	string A = "a";

	int k = A.length() - 1;
	int p1 = 0, p2 = 0;
	int ans = -1;
	int cnt = 0;
	int idx = -1;
	for (int i = 1; i < k; i++) {
		p1 = p2 = i;
		while (p1 >= 0 and p2 < A.length() and A[p1] == A[p2]) {
			p1--;
			p2++;
		}
		cnt = (p2 - 1) - (p1 + 1) + 1;
		if (cnt > ans) {
			idx = i;
			ans = cnt;
		}

	}
	// cout << cnt << "\n";
	// cout << ans << "\n";

	for (int i = 0; i < A.length(); i++) {
		p1 = i;
		p2 = i + 1;
		while (p1 >= 0 and p2 < A.length() and A[p1] == A[p2]) {
			p1--;
			p2++;
		}
		cnt = (p2 - 1) - ( p1 + 1) + 1;
		if (cnt > ans) {
			idx = i;
			ans = cnt;
		}

	}
	if (ans == 0) {
		return A[0];
	}
	string res = "";
	if (ans % 2 == 0) {

		int start = idx - (ans / 2) + 1;
		int end = idx + (ans / 2) ;
		// cout << start << " " << end << "\n";
		for (int i = start ; i <= end; i++) {
			res += A[i];
		}
	} else {
		int start = idx - (ans / 2);
		int end = idx + (ans / 2);
		for (int i = start ; i <= end; i++) {
			res += A[i];
		}
	}
	cout << ans << "\n";
	cout << res << "\n";


	return 0;
}