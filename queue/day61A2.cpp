#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main() {

	int k = B;
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

			while (!dq.empty() and dq.back() < A[j]) {
				dq.pop_back();
			}
			dq.push_back(A[j]);
			ans.push_back(dq.front());

			if (dq.front() == A[i]) {
				dq.pop_front();
			}
			i++;
			j++;
		}
	}


	return ans;
}

