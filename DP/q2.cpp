#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {

	string s;
	cin >> s;
	int f = 0;
	ll len = s.length();
	if (len == 8) {
		if (!(s[0] >= 'A' and s[0] <= 'Z')) {
			cout << "No";
		} else if (!(s[len - 1] >= 'A' and s[len - 1] <= 'Z')) {
			cout << "No";
		} else {

			for (int i = 1; i <= len - 2; i++) {
				if (!(s[i] >= '0' and s[i] <= '9')) {
					cout << "No";
					f = 1;
					break;
				}
			}
			if (f == 0) {
				if (s[1] != 0) {
					cout << "Yes";
				} else {
					cout << "No";
				}
			}
		}
	} else {
		cout << "No";
	}

	return 0;
}