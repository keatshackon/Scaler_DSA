#include <bits/stdc++.h>
using namespace std;
#define ll long long

int dfs(int b, int c, vector<int>g[], vector<int>&visited) {

	if (c == b) {
		return 1;
	}

	if (g[c].size() == 0) {
		return 0;
	}

	for (auto q : g[c]) {
		if (dfs(b, q, g, visited) == 1) {
			return 1;
		}
	}
}


int main() {

	vector<int>A = {1, 1, 2, 3, 4};
	int b = 2, c = 4;

	int len = A.size();
	vector<int>g[len + 1];

	vector<int>visited(len + 1, 0);


	for (int i = 1; i < len; i++) {
		g[A[i]].push_back(i + 1);
	}

	for (int i = 1; i <= len; i++) {
		cout << i << ": ";
		for (auto q : g[i]) {
			cout << q << " ";
		}
		cout << "\n";
	}


	if (dfs(b, c, g, visited)) {
		cout << "1";
	} else {
		cout << "0";
	}

	return 0;
}