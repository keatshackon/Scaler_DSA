#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {


	int A = 3543;

	int ans = 0;
	while (A) {

		int i = 1;
		while (i * 5 <= A) {
			i = i * 5;
		}
		ans++;
		A -= i;
	}

	cout << ans;

	return 0;
}