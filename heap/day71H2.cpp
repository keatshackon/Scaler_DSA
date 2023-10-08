#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {

	vector<int>A = {946, 354, 88, 528, 677, 662, 662, 30,
	                137, 325, 522, 920, 198, 923, 959, 555,
	                950, 717, 573, 933, 344, 640, 37, 619
	               };
	int B = 27;

	int n = A.size();


	priority_queue<int, vector<int>, greater<int>>pq;


	for (int i = 0; i < n; i++) {
		pq.push(A[i]);
	}

	int ans = 0;

	while (pq.size() > 1 ) {
		if (pq.top() > B) break;
		int temp = pq.top();
		int k = 0;
		pq.pop();
		if (!pq.empty()) {
			ans += temp / 2;
			cout << ans << "\n";
			k = temp - temp / 2;
			int s = pq.top();
			pq.pop();
			pq.push(s + k);
		}
		if (pq.top() > B) {
			break;
		}
	}

	cout << ans;

	return 0;
}