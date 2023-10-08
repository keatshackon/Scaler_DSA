#include <bits/stdc++.h>
using namespace std;
#define ll long long int


int main() {

	int A = -2147483648;
	int B = 1;

	int sign = 1;
	if (A < 0) {
		sign *= -1;
	}
	if (B < 0) {
		sign *= -1;
	}

	ll a = A;
	ll b = B;

	a = abs(a);
	b = abs(a);

	ll ans = 0;

	cout << a << " " << b << "\n";

	int k = 30;

	while (a >= b and k >= 0) {
		if ((1 << k) <= a) {
			a -= ((1 << k) * b);
			ans += 1 << k;
		}
		k--;
	}

	cout << ans << "\n";

	ans *= sign;

	cout << ans << "\n";

	return 0;
}