#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {


	vector<int>A = {62, -45, -12, -1, -81, 51, 11, -34,
	                -31, -12, -21, 36, 30, 4, -1, 3, 76, -36, -79, -25,
	                -45, -22, -35, 31, -20, -1, 81, -2, -94
	               };
	int b = 3326;

	int n = A.size();

	priority_queue<int, vector<int>, greater<int>>pq;


	sort(A.begin(), A.end());

	for (auto q : A) {
		cout << q << " ";
	}
	cout << "\n";

	int sum = 0;

	for (int i = 0; i < n; i++) {
		pq.push(A[i]);
	}

	int f = 0;
	int temp = -1;
	int res = -1e9;
	while (!pq.empty() and b) {

		if (pq.top() < 0 and b) {
			int k = pq.top();
			sum += (-1 * k);
		} else {
			temp = pq.top();
			break;
		}
		res = pq.top();
		pq.pop();
		b--;
	}

	cout << b << " " << res << "\n";

	if ( b % 2 == 0) {
		while (!pq.empty()) {
			sum += pq.top();
			pq.pop();
		}
	} else {
		if (res != -1e9 and abs(res) < abs(temp)) {
			sum += 2 * res;
			cout << sum << "\n";
			sum += temp;
			cout << sum << "\n";
			pq.pop();
			while (!pq.empty()) {
				sum += pq.top();
				pq.pop();
			}
		} else if (res != -1e9 and abs(res) > abs(temp)) {
			sum -= temp;
			pq.pop();
			while (!pq.empty()) {
				sum += pq.top();
				pq.pop();
			}
		} else {
			sum -= temp;
			pq.pop();
			while (!pq.empty()) {
				sum += pq.top();
				pq.pop();
			}
		}
	}

	cout << sum << "\n";


	return 0;
}