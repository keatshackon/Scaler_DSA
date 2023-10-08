#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {


	int n = 5, m = 6;

	vector<int>g[n + 1];

	//map<string, vector<string>>A;

	// Creating The Graph
	// while (m--) {
	// 	cin >> u >> v;
	// 	g[u].push_back(v);
	// 	g[v].push_back(u);
	// }
	g[1].push_back(2);
	g[1].push_back(4);

	g[2].push_back(3);
	g[2].push_back(5);

	g[3].push_back(4);
	g[3].push_back(5);


	// bfs starts here
	vector<bool>visited(n + 1, 0);
	queue<int>q;

	q.push(1);
	visited[1] = 1;

	while (!q.empty()) {
		int temp = q.front();
		cout << temp << " ";
		q.pop();
		for (int i = 0; i < g[temp].size(); i++) {
			if (!visited[g[temp][i]]) {
				q.push(g[temp][i]);
				visited[g[temp][i]] = 1;
			}
		}
	}


	// PRINTING THE GRAPH;
	// for (int i = 1; i <= n; i++) {
	// 	cout << i << ": ";
	// 	for (auto w : g[i]) {
	// 		cout << w << " ";
	// 	}
	// 	cout << "\n";
	// }

	return 0;
}