#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {


	unsigned int  A = 3;
	unsigned int ans = 0;

	int i = 1;
	int k = 31;
	while (i < 16) {
		if ((A & (1 << i)) >= 1) {
			ans = ans | (1 << k);
		}
		i++;
		k--;
	}

	cout << ans << "\n";

	if ((A & 1) == 1) {
		ans += (long)pow(2, 31);
		if (ans == 0)
			ans--;
	}

	cout << ans;

	return 0;
}