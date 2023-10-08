#include <bits/stdc++.h>
using namespace std;
#define ll long long

int dfs(int node, int parent, vector<int>g[], vector<int>&vis) {

	for (auto q : g[node]) {
		if (vis[q] == -1) {
			vis[q] = 1 - parent;
			if (dfs(q, vis[q], g, vis) == 0) {
				return 0;
			}
		} else if (vis[q] == parent) {
			return 0;
		}
	}
	return 1;
}

int main() {


	vector<vector<int>>B = {
		{2, 5},
		{6, 7},
		{4, 8},
		{2, 3},
		{0, 3},
		{4, 7},
		{1, 8},
		{3, 8},
		{1, 3}
	};
	int A = 9;

	vector<int>g[A];
	int len = B.size();

	for (int i = 0; i < len; i++) {
		g[B[i][0]].push_back(B[i][1]);
		g[B[i][1]].push_back(B[i][0]);
	}

	for (int i = 0; i < len; i++) {
		cout << i << ": ";
		for (auto w : g[i]) {
			cout << w << " ";
		}
		cout << "\n";
	}

	vector<int>vis(A, -1);

	for (int i = 0; i < A; i++) {
		if (vis[i] == -1) {
			vis[i] = 0;
			if (dfs(i, 0, g, vis) == 0) {
				cout << "False";
				return 0;
			}
		}
	}

	for (auto q : vis) {
		cout << q << " ";
	}

	cout << "true";
	return 0;
}