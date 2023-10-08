#include <bits/stdc++.h>
using namespace std;
#define ll long long


bool isPrime(int a) {

	if (a == 0 or a == 1) {
		return 0;
	}

	for (int i = 2; i * i <= a; i++) {
		if (a % i == 0) {
			return false;
		}
	}
	return true;
}



int main() {


	vector<int>A = {1, 2, 3, 4};

	set<int>s;

	int n = A.size();


	for (int i = 0; i < n; i++) {

		int temp = A[i];

		if (isPrime(temp)) {
			s.insert(temp);
		} else {
			for (int i = 2; i * i <= temp; i++) {
				if (temp % i == 0) {
					if (isPrime(i)) {
						s.insert(i);
					}
					if (isPrime(temp / i)) {
						s.insert(temp / i);
					}
				}
			}
		}
	}


	cout << s.size();


	return 0;
}