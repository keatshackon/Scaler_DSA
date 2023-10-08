#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main() {


	map<int, int> map;

	vector<int> v(26, 0);

	string A = "bbaabb";

	int n = A.length();

	for (int i = 0; i < n; i++) {
		v[A[i] - 'a']++;
	}

	for (auto q : v) {
		if (q % 2 != 0) {
			cout << -1;
			break;
		}
	}

	cout << 1;

	return 0;
}