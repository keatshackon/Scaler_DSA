#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(vector<int>&A, int k) {


	int n = A.size();
	queue<int>q;

	vector<int>ans;

	int i = 0;
	while (i < k) {
		if (A[i] < 0) {
			q.push(A[i]);
		}
		i++;
	}
	if (!q.empty()) {
		ans.push_back(q.front());
	} else {
		ans.push_back(-2);
	}

	i = 0;

	for (int j = k ; j < n; j++) {
		if (A[j] < 0) {
			q.push(A[j]);
		}
		if (A[i] == q.front()) {
			q.pop();
		}
		if (!q.empty()) {
			ans.push_back(q.front());
		} else {
			ans.push_back(-2);
		}
		i++;
	}

	for (auto q : ans) {
		cout << q << " ";
	}
}


int main() {


	vector<int>A = {12, -1, -7, 8, -15, 30, 16, -28};
	int k = 3;
	int n = A.size();

	// BRUTE FORCE O(n^2)
	// int i = 0;

	// while (i < n) {
	// 	int j = i;
	// 	int f = 0;
	// 	while (j < i + k and i + k <= n) {
	// 		if (A[j] < 0) {
	// 			cout << A[j] << " ";
	// 			f = 1;
	// 			break;
	// 		}
	// 		j++;
	// 	}
	// 	if (f == 0) {
	// 		cout << 0 << " ";
	// 	}
	// 	i++;
	// }



	solve(A, k);

	return 0;
}