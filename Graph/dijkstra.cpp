#include <bits/stdc++.h>
using namespace std;
#define ll long long




// USING PRIORITY QUEUE FOR DIJKSTRA
void solve1(vector<pair<int, int>>g[], vector<int>&dist, int src) {

	// THIS IS HOW PRIORITY QUEUE IS DEFINE.
	priority_queue<pair<int, int>, vector<pair<int, int>>,
	               greater<pair<int, int>>> pq;


	pq.push({0, src});


	while (!pq.empty()) {
		int dis = pq.top().first;
		int node = pq.top().second;
		pq.pop();

		for (auto q : g[node]) {
			int nNode = q.first;
			int ndis = q.second;

			if (ndis + dis < dist[nNode]) {
				dist[nNode] = ndis + dis;
				pq.push({dist[nNode], nNode});
			}

		}
	}
}

int main() {

	// U CAN CHOOSE ANY NODE AS A SOURCE.

	// EDGES BETWEEN THE NODES.
	vector<vector<int>>B = {{0, 1, 4},
		{0, 2, 4},
		{1, 2, 2},
		{2, 3, 3},
		{2, 4, 1},
		{2, 5, 6},
		{3, 5, 2},
		{4, 5, 3},
	};
	int A = 5;
	int src = 0;

	// INITIAZING GRAPH.
	vector<pair<int, int>>g[A + 1];

	// KEEPING ALL THE SHORTEST DISTANCE FROM SRC NODE.
	vector<int>dis(A + 1, 1e9);

	// SRC NODE TO SRC NODE, SHORTEST DISTANCE IS 0.
	dis[src] = 0;


	// CREATING UNDIRECTED GRAPH.
	for (int i = 0; i < B.size(); i++) {
		// FIRST WILL BE NODE AND SECOND WILL BE WEIGHT.
		g[B[i][0]].push_back({B[i][1], B[i][2]});
		g[B[i][1]].push_back({B[i][0], B[i][2]});
	}

	// PRINTING THE UNDIRECTED GRPAH.
	for (int i = 0; i < A; i++) {
		cout << i << ": ";
		for (auto q : g[i]) {
			cout << "{" << q.first << "," << q.second << "} ";
		}
		cout << "\n";
	}

	// USING PQ FOR DIJKSTRA
	solve1(g, dis, src);


	// PRINTING SHORTEST DISTANCE FROM SRC NODE TO ALL OTHER NODE.
	//cout << "\nALL NODE SHORTEST DISTANCE FROM SRC NODE \n";
	for (auto q : dis) {
		cout << q << " ";
	}

	return 0;
}