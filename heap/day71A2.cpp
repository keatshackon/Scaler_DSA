#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main() {


	vector<int>A = {5, 17, 100, 11};
	int n = A.size();

	priority_queue<int, vector<int>, greater<int>>pq;

	for (int i = 0; i < n; i++) {
		pq.push(A[i]);
	}

	int ans = 0;

	while (pq.size() > 1) {

		int a = pq.top();
		int b = 0;
		pq.pop();
		if (!pq.empty()) {
			b = pq.top();
		}
		pq.pop();
		int temp = a + b;
		ans += temp;
		pq.push(temp);
	}

	cout << ans << "\n";


	return 0;
}