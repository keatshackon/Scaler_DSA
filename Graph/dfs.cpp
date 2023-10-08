#include <bits/stdc++.h>
using namespace std;
#define ll long long

void dfs(int src, vector<int>g[], vector<bool> &visited, vector<int>&ans) {


	if (!visited[src]) {
		visited[src] = 1;
		ans.push_back(src);
		for (auto q : g[src]) {
			dfs(q, g, visited, ans);
		}
	} else {
		return;
	}
}

int main() {

	int n = 5, m = 6;

	vector<bool>visited(n + 1, 0);
	vector<int>g[n + 1];

	g[1].push_back(2);
	g[2].push_back(1);
	g[1].push_back(4);
	g[4].push_back(1);

	g[2].push_back(3);
	g[3].push_back(2);
	g[2].push_back(5);
	g[5].push_back(2);

	g[3].push_back(4);
	g[4].push_back(3);
	g[3].push_back(5);
	g[5].push_back(3);


	vector<int>ans;

	dfs(1, g, visited, ans);

	for (auto q : ans) {
		cout << q << " ";
	}


	//PRINTING THE GRAPH;
	cout << "\n";
	for (int i = 1; i <= n; i++) {
		cout << i << ": ";
		for (auto w : g[i]) {
			cout << w << " ";
		}
		cout << "\n";
	}


	return 0;
}

