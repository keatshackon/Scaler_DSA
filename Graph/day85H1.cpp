#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main() {

	int A = 5;
	vector<vector<int>> B = {{1, 2},
		{2, 3},
		{4, 3},
		{4, 5}
	};

	const long INF = 1e9;
	vector<pair<long, long>>graph[A + 1];
	for (int i = 0 ; i < B.size(); ++i) {
		graph[B[i][0]].push_back({B[i][1], 0});
		graph[B[i][1]].push_back({B[i][0], 1});

	}

	deque<long>dq;
	dq.push_front(1);

	long ans = 0;

	vector<long>dist(A + 1, INF);
	dist[1] = 0;

	while (!dq.empty()) {
		long u = dq.front();
		dq.pop_front();

		for (auto temp : graph[u]) {
			long v = temp.first;

			if (dist[v] > dist[u] + temp.second) {

				dist[v] = dist[u] + temp.second;
				dq.push_back(v);
			}

		}
	}

	if (dist[A] == INF) {
		return -1;
	}
	cout << dist[A] << "\n";

	return 0;
}