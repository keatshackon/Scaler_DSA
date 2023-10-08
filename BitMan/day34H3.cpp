#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007


int main() {


	vector<int>A = {1, 3, 5};


	int n = A.size();

	int ans = 0;

	for (int i = 0; i < 31; i++) {
		int one = 0;
		int zero = 0;
		for (int j = 0; j < n; j++) {
			if ((A[j] & (1 << i)) >= 1) {
				one++;
			} else {
				zero++;
			}
		}
		ans = (ans % MOD + ((one % MOD * zero % MOD) % MOD)) % MOD;
	}

	ans = (ans % MOD + ans % MOD ) % MOD;

	cout << ans << "\n";

	return 0;
}