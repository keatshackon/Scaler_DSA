#include<bits/stdc++.h>
using namespace std;
#define ll long long


int main() {

	ll t, n, a, b, c;
	cin >> t;
	while (t--) {
		cin >> a >> b >> c;
		ll cnt = 0;
		ll sum = b;
		int f = 0;
		while (a-- and sum <= c) {
			sum += b;
			cnt++;
		}

		ll ans = 0;
		if (sum - b != c) {
			ans = c - sum;
		}
		ll res = b * b ;
		res *= cnt;
		res = res + ans * ans;
		cout << res << "\n";

	}
	return 0;
}

