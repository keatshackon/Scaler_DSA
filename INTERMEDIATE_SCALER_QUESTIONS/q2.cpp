#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() {

	ll t, n, a, b;
	cin >> t;
	while (t--) {
		cin >> a >> b;

		if (b >= a) {
			cout << 0 << '\n';
			continue;
		}

		if ((a - b) % 4 == 0) {
			cout << (a - b) / 4 << "\n";
		} else {
			cout << (a - b) % 4 << "\n";
		}
	}
	return 0;

}