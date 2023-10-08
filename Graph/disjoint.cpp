#include <bits/stdc++.h>
using namespace std;
#define ll long long


class Disjoint {

public:
	vector<int>parent, rank, n_size;

	Disjoint(int n) {
		parent.resize(n + 1);
		rank.resize(n + 1, 0);
		n_size.resize(n + 1, 1);
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

	void UnionByRank(int u, int v) {
		int ulp_u = findParent(u);
		int ulp_v = findParent(v);

		if (ulp_u == ulp_v) return;

		if (rank[ulp_u] < rank[ulp_v]) {
			parent[ulp_u] = ulp_v;
		} else if (rank[ulp_u] > rank[ulp_v]) {
			parent[ulp_v] = ulp_u;
		} else {
			rank[ulp_u]++;
			parent[ulp_v] = ulp_u;
		}
	}

	void UnionBySize(int u, int v) {
		int ulp_u = findParent(u);
		int ulp_v = findParent(v);
		if (ulp_v == ulp_u) return;

		if (n_size[ulp_u] < n_size[ulp_v]) {
			parent[ulp_u] = ulp_v;
			n_size[ulp_v] += n_size[ulp_u];
		} else if (n_size[ulp_u] > n_size[ulp_v]) {
			parent[ulp_v] = ulp_u;
			n_size[ulp_u] += n_size[ulp_v];
		} else {
			parent[ulp_v] = ulp_u;
			n_size[ulp_u] += n_size[ulp_v];
		}
	}
};


int main() {

	vector<vector<int>>e = {{1, 2}, {1, 3}, {2, 3}};

	int n = e.size();

	Disjoint ds(3);


	for (int i = 0; i < n; i++) {
		if (ds.findParent(e[i][0]) == ds.findParent(e[i][1])) {
			cout << "Extra Edges ";
			return 0;
		} else {
			ds.UnionBySize(e[i][0], e[i][1]);
		}
	}

	return 0;
}