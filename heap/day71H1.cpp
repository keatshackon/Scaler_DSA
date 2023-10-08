#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main() {

	vector<vector<int>>A = {{1, 3}, { -2, 2}};
	int B = 1;

	priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>>pq;

	int n = A.size();
	vector<vector<int>>ans;


	for (int i = 0; i < n; i++) {
		double t1 = (A[i][0] - 0);
		double t2 = (A[i][1] - 0);
		double res = t1 * t1 + t2 * t2;
		res = (int)sqrt(res);
		pq.push({res, {A[i][0], A[i][1]}});
	}



	while (B) {
		ans.push_back({pq.top().second.first, pq.top().second.second});
		pq.pop();
		B--;
	}

	for (auto q : ans) {
		for (auto w : q) {
			cout << w << " ";
		}
		cout << "\n";
	}

	return 0;
}