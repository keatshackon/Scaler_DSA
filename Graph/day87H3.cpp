#include <bits/stdc++.h>
using namespace std;
#define ll long long


void dfs(int node, vector<int>g[], vector<int>&visited, int &maxi, int &nNode, int src) {

	visited[node] = 1;
	for (auto q : g[node]) {

		if (!visited[q]) {

			if (src > maxi) {
				maxi = src;
				nNode = q;
			}
			dfs(q, g, visited, maxi, nNode, src + 1);
		}

	}
}


int main() {

	vector<int>A = { -1, 0, 1, 1, 0, 4};
	int len = A.size();

	vector<int>g[len + 1];

	for (int i = 0; i < len; i++) {
		if (A[i] != -1) {
			g[A[i]].push_back(i);
			g[i].push_back(A[i]);
		}
	}

	for (int i = 0; i < len; i++) {
		cout << i << " : ";
		for (auto q : g[i]) {
			cout << q << " ";
		}
		cout << "\n";
	}

	int nNode = -1;
	int maxi = 0 ;
	vector<int>visited(len + 1, 0);

	maxi = 0;

	dfs(0, g, visited, maxi, nNode, 1);

	cout << "\n";
	cout << maxi << " " << nNode << "\n";

	vector<int>vis(len + 1, 0);
	cout << "\n";

	maxi = 0;
	int mNode = nNode;
	dfs(mNode, g, vis, maxi, nNode, 1);

	for (auto q : vis) {
		cout << q << " ";
	}
	cout << "\n";


	cout << maxi << "\n";


	return 0;
}
