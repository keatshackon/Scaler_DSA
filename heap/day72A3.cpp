#include <bits/stdc++.h>
using namespace std;


int main() {


	int A = 4;
	vector<int> B = {1, 2, 3, 4, 5, 6};

	int n = B.size();

	priority_queue<int, vector<int>, greater<int>>pq;

	vector<int>ans;


	for (int i = 0; i < A - 1; i++) {
		ans.push_back(-1);
	}

	int i = 0;
	while (i < A) {
		pq.push(B[i]);
		i++;
	}

	if (!pq.empty())
		ans.push_back(pq.top());

	while (i < n) {
		if (pq.top() < B[i]) {
			pq.pop();
			pq.push(B[i]);
		}
		ans.push_back(pq.top());
		i++;
	}

	for (auto q : ans) {
		cout << q << " ";
	}


	return 0;
}