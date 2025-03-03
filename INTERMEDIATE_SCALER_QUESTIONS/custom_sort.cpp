#include<bits/stdc++.h>
using namespace std;
#define ll long long

bool  cmp (int x, int y) {

	int f1 = 0;
	int f2 = 0;

	for (int i = 2; i * i  <= x; i++) {
		if ((x % i) == 0) {
			f1++;
			if (i * i != x) {
				f1++;
			}
		}
	}

	for (int i = 2; i * i  <= y; i++) {
		if ((y % i) == 0) {
			f2++;
			if (i * i != y) {
				f2++;
			}
		}
	}

	// cout << x << " " << y << " ";
	// cout << f1 << " " << f2 << "\n";

	if (f1 < f2) {
		return true;
	} else if (f1 > f2) {
		return false;
	} else {
		if (x <= y) {
			return true;
		} else {
			return false;
		}
	}

}

int main() {

	vector<int> v = {4, 9, 3, 10, 6}; // 3,4,9,6,10

	sort(v.begin(), v.end(), cmp);

	for (auto q : v) {
		cout << q << " ";
	}

	return 0;
}