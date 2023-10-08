#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007


int main() {


	int A = 19, B = 11, C = 13;

	long lcm = __gcd(B, C);
	lcm = (B * C) / lcm;

	cout << lcm << "\n";

	long l = 1;
	long r = min(B, C) * A;

	cout << r << "\n";

	int ans = 0;

	while (l <= r) {
		long m = (l + r) / 2;

		long s1 = m / B;
		long s2 = m / C;
		long s3 = m / lcm;

		long long res = (((s1 % MOD) + (s2 % MOD) % MOD) % MOD - (s3 % MOD)) % MOD;

		if (res < 0) res += MOD;

		if (res >= A) {
			ans = m;
			r = m - 1;
		} else if (res > A) {
			r = m - 1;
		} else {
			l = m + 1;
		}
	}

	cout << ans << "\n";

	return 0;
}