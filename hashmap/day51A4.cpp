#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main() {


	vector<int> A = { -19, 8, 2, -8, 19, 5, -2, -23};
	int n = A.size();

	vector<long long>prefix(n, 0);
	prefix[0]  = A[0];


	int ans = INT_MIN;
	int x = -1, y = -1;
	map<ll, ll> m;

	for (int i = 1; i < n; i++) {
		prefix[i] = prefix[i - 1] + A[i];
	}

	for (int i = 0; i < n; i++) {
		if (prefix[i] == 0) {
			int temp = i + 1;
			if (ans < temp) {
				ans = max(ans, temp);
				x = 0, y = i;
			}
		} else if (m.count(prefix[i]) != 0) {
			int temp = i - m[prefix[i]];
			if (ans < temp) {
				ans = max(ans, temp);
				x = m[prefix[i]] + 1, y = i;
			}
		} else {
			m[prefix[i]] = i;
		}
	}

	if (x == -1) {
		return {};
	}
	vector<int>res;

	for (int i = x; i <= y; i++) {
		res.push_back(A[i]);
	}

	// return res;

	return 0;
}