#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007

bool isPrime(int x) {

	if (x == 0 or x == 1) return 0;

	for (int i = 2; i * i <= x; i++) {
		if (x % i == 0) {
			return 0;
		}
	}

	return 1;
}

int mypow(int x, int y) {

	if (y == 0) {
		return 1;
	}

	int temp = mypow(x, y / 2);

	if (y % 2 == 0) {
		return (temp % MOD * temp % MOD) % MOD;
	} else {
		return (x % MOD * ((temp % MOD) % MOD * temp % MOD)) % MOD;
	}

}

int main() {


	vector<int>A = {12, 24, 34, 3, 5, 56};

	int n = A.size();
	int cnt = 0;

	for (int i = 0; i < n; i++) {
		if (isPrime(A[i])) {
			cnt++;
		}
	}

	cout << cnt << "\n";


	cnt = 1;

	int  temp  = mypow(2, cnt);

	cout << temp << "\n";

	int ans = (temp % MOD - 1 % MOD)  % MOD;

	if (ans < 0) {
		ans += MOD;
	}

	cout << ans << "\n";


	return 0;
}