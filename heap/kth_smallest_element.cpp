#include <bits/stdc++.h>
using namespace std;
#define ll long long

// time complexity nlog(k) due to heap.
int main() {


	vector<int>A = {7, 10, 3, 41, 51, 1};
	int k = 3;

	priority_queue<int>pq;

	int n = A.size();
	int j = 0;

	while (k--) {
		pq.push(A[j]);
		j++;
	}

	while (j < n) {
		if (pq.top() > A[j]) {
			pq.pop();
			pq.push(A[j]);
		}
		j++;
	}

	if (!pq.empty()) {
		cout << pq.top();
	} else {
		cout << -1;
	}
	return 0;
}
