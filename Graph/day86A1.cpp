#include <bits/stdc++.h>
using namespace std;
#define ll long long

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

	int A = 9;
	vector<int>B = {10, 8, 2, 3, 4, 8, 3, 5, 9};
	vector<vector<int>> C = {{ 1, 4},
		{1, 6},
		{2, 7},
		{2, 9},
		{3, 5},
		{3, 8},
		{4, 9},
		{5, 8},
		{6, 8}
	};
	int D = 25;

	Disjoint ds(A);

	for (int i = 0; i < C.size(); i++) {
		if (ds.findParent(C[i][0]) != ds.findParent(C[i][1])) {
			ds.UnionBySize(C[i][0], C[i][1]);
		}
		if (ds.findParent(C[i][1]) != ds.findParent(C[i][0])) {
			ds.UnionBySize(C[i][0], C[i][1]);
		}
	}

	for (auto q : ds.parent) {
		cout << ds.findParent(q) << " ";
	}
	cout << "\n";

	map<int, int> m;

	for (int i = 1; i <= A; i++) {
		m[ds.findParent(i)] += B[i];
	}

	int cnt = 0;
	for (auto q : m) {
		if (q.second >= D) cnt++;
		cout << q.first << " " << q.second << "\n";
	}
	cout << cnt << "\n";

	return 0;
}