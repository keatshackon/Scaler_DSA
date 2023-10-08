#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007

class Disjoint {

public:
	vector<int>parent, comp_size;
	Disjoint(int n) {
		parent.resize(n + 1);
		comp_size.resize(n + 1, 1);

		for (int i = 0; i <= n; i++) {
			parent[i] = i;
		}
	}

	int findParent(int n) {
		if (n == parent[n]) {
			return n;
		}
		return parent[n] = findParent(parent[n]);
	}

	void UnionBySize(int u, int v) {
		int up_u = findParent(u);
		int up_v = findParent(v);
		if (up_v == up_u) return;

		if (comp_size[up_u] < comp_size[up_v]) {
			parent[up_u] = up_v;
			comp_size[up_v] += comp_size[up_u];
		} else {
			parent[up_v] = up_u;
			comp_size[up_u] += comp_size[up_v];
		}
	}
};


int main() {

	int A = 4;
	vector<vector<int>> B  =  {{ 1, 2, 1},
		{2, 3, 4},
		{1, 4, 3},
		{4, 3, 2},
		{1, 3, 10}
	};

	sort(begin(B), end(B), [&](auto & s1, auto & s2) { return s1[2] < s2[2]; });

	for (auto q : B) {
		for (auto w : q) {
			cout << w << " ";
		}
		cout << "\n";
	}

	Disjoint ds(A);
	int sum = 0;

	for (int i = 0; i < B.size(); i++) {
		if (ds.findParent(B[i][0]) != ds.findParent(B[i][1])) {
			ds.UnionBySize(B[i][0], B[i][1]);
			sum = (sum % MOD + B[i][2] % MOD) % MOD;
		}
	}

	cout << sum << "\n";


	return 0;
}

