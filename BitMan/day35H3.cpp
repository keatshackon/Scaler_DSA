#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {

	int A = 0;
	int B = 2;


	int ans = 0;
	int k = 30;

	while (k >= 0 and B) {
		if (A & (1 << k)) {
			ans = ans | (1 << k);
			B--;
		}
		k--;
	}

	k = 0;
	while (B and k < 31) {
		if ((A & (1 << k)) == 0) {
			ans = ans | (1 << k);
			B--;
		}
		k++;
	}


	cout << ans << '\n';



	return 0;
}