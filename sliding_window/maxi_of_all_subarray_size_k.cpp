#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {

	vector<int>A = {1, 3, -1, -3, 5, 3, 6, 7};
	int k = 3;
	int n = A.size();

	vector<int>ans;

	deque<int>dq;


	int i = 0;
	int j = 0;
	while (j < n) {
		if (j - i + 1 < k) {
			if (dq.empty()) {
				dq.push_back(A[j]);
			} else {
				while (!dq.empty() and dq.back() < A[j]) {
					dq.pop_back();
				}
				dq.push_back(A[j]);
			}
			j++;
		} else if (j - i + 1 == k) {

			if (dq.empty()) {
				dq.push_back(A[j]);
				ans.push_back(dq.front());
			} else if (!dq.empty() and dq.back() > A[j]) {
				dq.push_back(A[j]);
				ans.push_back(dq.front());
			} else {
				while (!dq.empty() and dq.back() < A[j]) {
					dq.pop_back();
				}
				dq.push_back(A[j]);
				ans.push_back(dq.front());
			}

			if (dq.front() == A[i]) {
				dq.pop_front();
			}
			i++;
			j++;
		}
	}

	for (auto q : ans) {
		cout << q << " ";
	}

	return 0;
}