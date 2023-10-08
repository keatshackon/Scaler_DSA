#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main() {


	vector<int> A = {2, 3, 5, 7, -15, 8, 9};
	int n = A.size();

	vector<long long>prefix(n, 0);
	prefix[0]  = A[0];

	map<ll, ll> m;

	for (int i = 0; i < n; i++) {
		prefix[i] = prefix[i - 1] + A[i];
	}

	for (int i = 0; i < n; i++) {
		if (prefix[i] == 0) {
			// return 1;
			cout << 1;
		} else if (m.count(prefix[i]) != 0) {
			// return 1;
			cout << 1;
		} else {
			m[prefix[i]] = 1;
		}
	}


	// return -1;
	cout << 0;



	return 0;
}