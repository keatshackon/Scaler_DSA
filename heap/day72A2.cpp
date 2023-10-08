#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main() {


	vector<int>A = {25, 16, 11, 31, 28, 20, 3, 8};
	int B = 6;


	vector<int>ans;
	priority_queue<int, vector<int>, greater<int>>pq;

	int n = A.size();

	int i = 0;

	while (i <= B) {
		pq.push(A[i]);
		i++;
	}
	ans.push_back(pq.top());
	pq.pop();


	while (i < n) {
		pq.push(A[i]);
		ans.push_back(pq.top());
		pq.pop();
		i++;
	}

	while (!pq.empty()) {
		ans.push_back(pq.top());
		pq.pop();
	}

	for (auto q : ans) {
		cout << q << " ";
	}

	return 0;
}