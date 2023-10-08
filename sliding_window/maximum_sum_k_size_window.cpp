#include <bits/stdc++.h>
using namespace std;
#define ll long long


// prefix sum way with sliding window, TC o(n) and SC o(n)
// but it can  be done constant space;
int solve(vector<int>&A, int k) {

	int n = A.size();

	vector<int>prefix(n);
	vector<int>ans;

	prefix[0] = A[0];

	for (int i = 1; i < n; i++) {
		prefix[i] = prefix[i - 1] + A[i];
	}

	// for (auto q : prefix) {
	// 	cout << q << " ";
	// }
	// cout << "\n";

	int res = -1;
	int i = 0;
	while (i + k < n) {
		if (i == 0) {
			ans.push_back(prefix[k - 1]);
			res = max(res, prefix[k - 1]);
		} else {
			int temp = prefix[i + k - 1] - prefix[i - 1];
			ans.push_back(temp);
			res = max(res, temp);
		}
		i++;
	}

	cout << res ;
}


int main() {

	vector<int> v = {1, 2, 3, 2, 2, 4, 4, 6, 6, 7, 8, 8, 6, 5, 5};
	int k = 4;

	// int n = v.size();
	// vector<int>ans;

	// int res = -1;

	// BRUTE FORCE WAY o(N^2)
	// for (int i = 0; i < n; i++) {
	// 	int sum = 0;
	// 	for (int j = i; j < i + k and i + k <= n; j++) {
	// 		sum += v[j];
	// 	}
	// 	res = max(res, sum);
	// 	ans.push_back(sum);
	// }

	// cout << res << "\n";


	solve(v, k);

	return 0;
}