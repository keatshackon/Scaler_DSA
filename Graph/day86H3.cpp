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
		int up_v  = findParent(v);

		if (up_u == up_v) return;

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

	int A = 7;
	vector<vector<int>> B = {{1, 2, 468},
		{2, 3, 335},
		{3, 1, 501},
		{2, 4, 170},
		{2, 5, 725},
		{2, 7, 479},
		{4, 6, 359},
		{5, 6, 963}
	};

	vector<vector<int>>x(begin(B), end(B));


	int len = B.size();

	Disjoint ds(A);

	sort(begin(B), end(B), [&](auto & s1, auto & s2) {return s1[2] < s2[2];});


	for (auto q : B) {
		cout << q[0] << " " << q[1] << " " << q[2] << "\n";
	}
	cout << "\n";

	set<pair<int, int>>ss;

	for (int i = 0; i < len; i++) {
		if (ds.findParent(B[i][0]) != ds.findParent(B[i][1])) {
			ds.UnionBySize(B[i][0], B[i][1]);
		} else {
			ss.insert({B[i][0], B[i][1]});
		}
	}

	for (int i = 1; i <= A; i++) {
		ds.findParent(i);
	}

	vector<int>res;

	for (auto q : x) {
		if (ss.find({q[0], q[1]}) != ss.end()) {
			res.push_back(0);
		} else {
			res.push_back(1);
		}
	}

	for (auto q : res) {
		cout << q << " ";
	}

	return 0;
}