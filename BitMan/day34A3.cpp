#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() {


	int A = 7;
	int ans = 0;

	while (A) {
		ans++;
		A = A & (A - 1);
	}

	cout << ans << '\n';

	return 0;
}