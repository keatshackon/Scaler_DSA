#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {

	int A = 5;

	vector<int>v(A + 1, 0);

	vector<vector<int>>query = {{1, 2, 10}, {2, 3, 20}, {2, 5, 25}};


	int n = query.size();

	for (int i = 0; i < n; i++) {
		int l = query[i][0];
		int r = query[i][1];
		int p = query[i][2];

		v[l - 1] += p;
		v[r] += -p;
	}

	for (int i = 1; i < A; i++) {
		v[i] = v[i - 1] + v[i];
	}

	v.pop_back();

	for (auto q : v) {
		cout << q << " ";
	}


	return 0;
}