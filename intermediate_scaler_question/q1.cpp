#include<bits/stdc++.h>
using namespace std;
#define ll long long


int main() {

	ll t, n, a, b, c;
	cin >> t;
	while (t--) {
		cin >> a >> b >> c;

		if (a + b + c >= 100 and a >= 10 and b >= 10 and c >= 10) {
			cout << "PASS\n";
		} else {
			cout << "FAIL\n";
		}
	}

	return 0;

}