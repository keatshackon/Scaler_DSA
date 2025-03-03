#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {

	vector<int>A = { 1967513926, 1540383426, -1303455736, -521595368 };
	vector<int>res;
	int sum = INT_MIN;
	int ans = INT_MIN;
	int l1  = 0;
	int l2  = 0;
	int l3  = 0;
	int i   = A.size() - 1;
	int idx = -1;
	if (sum >= 0) {
		l2++;
	} else {
		sum = 0;
	}
	for (; i >= 0; i--) {
		if (A[i] < 0) {
			if (sum > ans) {
				ans = sum;
				idx = i + 1;
				l1 = l2;
				l2 = 0;
			} else if (sum == ans and l1 < l2) {
				l1 = l2;
				idx = i;
				l2 = 0;
			} else if (sum == ans and l1 == l2) {
				idx = i;
				l2 = 0;
			}
			sum = 0;
		} else {
			sum += A[i];
			l2++;
		}
	}

	cout << i << "\n";
	cout << sum << " " << ans << "\n";
	cout << l2 << "\n";
	if (sum > ans) {
		ans = sum;
		idx = i + 1;
	} else if (sum == ans and l2 > l1) {
		l1 = l2;
		idx = i + 1;
	} else if (sum == ans and l1 == l2) {
		idx = i + 1;
	}

	cout << idx << "\n";

	while (A[idx] >= 0 and idx < A.size()) {
		res.push_back(A[idx]);
		idx++;
	}

	for (auto q : res) {
		cout << q << " ";
	}

	return 0;
}