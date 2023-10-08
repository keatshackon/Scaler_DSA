#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main() {


	vector<int>A = {8, 6, 4, 2 };
	int B = 8;


	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	int n = A.size();

	for (int i = 0; i < n; i++) {
		pq.push({2 * A[i], i});
	}

	vector<int>state(n);


	while (B--) {
		pair<int, int>temp = pq.top();
		state[temp.second] = temp.first;
		temp.first += A[temp.second];
		pq.pop();
		pq.push(temp);
	}

	int ans = 0;

	for (auto q : state) {
		ans = max(ans, q);
	}

	cout << ans << "\n";

	return 0;
}