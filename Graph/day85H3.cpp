#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main() {

	int A = 2;
	vector<vector<int>>B = {
		{1, 2}

	};

	vector<int>g[A + 1];
	int len = B.size();
	vector<int>ind(A + 1, 0);

	for (int i = 0; i < len; i++) {
		g[B[i][0]].push_back(B[i][1]);
	}

	for (int i = 1; i <= A; i++ ) {
		cout << i << ": ";
		for (auto w : g[i]) {
			cout << w << " ";
		}
		cout << "\n";
	}

	for (int i = 0; i < len; i++) {
		ind[B[i][1]]++;
	}
	vector<int> topo;
	queue<int>q;

	for (int i = 1; i <= A; i++) {
		if (ind[i] == 0) {
			q.push(i);
		}
	}

	while (!q.empty()) {
		int temp = q.front();
		q.pop();
		topo.push_back(temp);
		for (auto w : g[temp]) {
			ind[w]--;
			if (ind[w] == 0) {
				q.push(w);
			}
		}


	}

	if (topo.size() != A) {
		cout << "YES\n";
		return 0;
	}

	cout << "No\n";
	return 0;
}
