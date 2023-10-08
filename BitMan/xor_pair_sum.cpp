#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {


	vector<int>A = {0, 4, 7, 9};

	int n = A.size();
	int ans = 0;
	int cnt = 0;

	for (int i = 0; i < 31; i++) {
		int one = 0, zero = 0;
		for (int j = 0; j < n; j++) {
			if ((A[j] & (1 << i)) >= 1) {
				one++;
			} else {
				zero++;
			}
		}
		cnt = one * zero;
		ans += cnt * 1 << i;
	}

	cout << ans * 2 << "\n";
	return 0;;
}