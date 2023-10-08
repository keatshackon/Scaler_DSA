#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main() {

	int A = 6;
	vector<vector<int>> B =  {{6, 3},
		{6, 1},
		{5, 1},
		{5, 2},
		{3, 4},
		{4, 2}
	};

	vector<int>g[A + 1];

	vector<int>ind(A + 1, 0);

	for (int i = 0; i < B.size(); i++) {
		g[B[i][0]].push_back(B[i][1]);
		ind[B[i][1]]++;

	}

	for (int i = 1; i <= A; i++) {
		cout << i << " : ";
		for (auto q : g[i]) {
			cout << q << " ";
		}
		cout << "\n";
	}

	priority_queue<int, vector<int>, greater<int>>q;

	for (int i = 1; i <= A; i++) {
		if (ind[i] == 0) {
			q.push(i);
		}
	}


	vector<int>ans;

	while (!q.empty()) {
		int k = q.top();
		q.pop();
		ans.push_back(k);
		for (auto w : g[k]) {
			ind[w]--;
			if (ind[w] == 0) {
				q.push(w);
			}
		}
	}

	for (auto w : ans) {
		cout << w << " ";
	}

	return 0;
}