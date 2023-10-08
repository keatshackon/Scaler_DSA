#include <bits/stdc++.h>
using namespace std;
#define ll long long


bool cmp(pair<int , int>a, pair<int, int>b) {

	if (a.second == b.second) {
		return a.first < b.first;
	} else if (a.second < b.second) {
		return true;
	}
	return false;
}

int main() {


	vector<int>A = {3, 1, 2, 1, 3};
	vector<int>B = {100, 19, 27, 25, 30};

	int n = A.size();


	priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq1;
	priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq2;


	for (int i = 0; i < n; i++) {
		pq1.push({A[i], B[i]});
	}

	int time = 1;
	int deadLine = *max(A.begin(), A.end());
	int reward = 0;

	while (!pq1.empty()) {


		pair<int, int>cur = pq1.top();

		if (time <= cur.first) {

			reward += cur.second;
			pq2.push({cur.second, cur.first});
			time++;

		} else {
			if (cur.second >= pq2.top().first) {
				reward -= pq2.top().first;
				reward += cur.second;
				pq2.pop();
				pq2.push({cur.second, cur.first});
			}
		}

		pq1.pop();
	}

	cout << reward << "\n";


	return 0;
}