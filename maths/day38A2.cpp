#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool isPrime(int n) {

	if (n <= 1) {
		return 0;
	}

	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			return 0;
		}
	}
	return 1;

}

int main() {

	int A = 4;

	for (int i = 1; i <= A; i++) {
		if (isPrime(i) and isPrime(A - i)) {
			cout << i << " " << A - i << "\n";
			break;
		}
	}

	return 0;
}