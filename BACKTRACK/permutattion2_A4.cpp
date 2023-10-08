#include <bits/stdc++.h>
using namespace std;
#define ll long long



// SOLVED USING FREQUENCY TECHNIQUE.
// void solve(int idx, vector<pair<int, int>>&A, int n, vector<int>&ds, vector<vector<int>>&ans) {

// 	if (ds.size() == n) {
// 		ans.push_back(ds);
// 		return;
// 	}
// 	if (idx == n) {
// 		return;
// 	}
// 	for (int i = idx; i < A.size(); i++) {

// 		if (A[i].second > 0) {
// 			ds.push_back(A[i].first);
// 			A[i].second--;
// 			solve(idx, A, n, ds, ans);
// 			A[i].second++;
// 			ds.pop_back();
// 		}
// 	}
// }


// USING FOR LOOP TECHNOIQUE TO ELIMINATE THE DIPLICATE
void solve(int i, int n, vector<int>&A, vector<vector<int>>&ans) {

	if (i == n - 1) {
		ans.push_back(A);
		return;
	}
	for (int k = i; k < n; k++) {

		if (i != k and A[i] == A[k]) continue;

		swap(A[i], A[k]);
		solve(i + 1, n, A, ans);
		swap(A[i], A[k]);
	}
}

int main() {

	vector<int>A = {1, 1, 2, 2};

	// map<int, int> m;
	// int len = A.size();
	// vector<int>ds;

	// for (auto q : A) {
	// 	++m[q];
	// }
	// vector<pair<int, int>>nums;
	// vector<vector<int>>ans;

	// for (auto q : m) {
	// 	nums.push_back({q.first, q.second});
	// }

	// solve(0, nums, len, ds, ans);

	sort(A.begin(), A.end());
	int n = A.size();
	vector<vector<int>>ans;

	solve(0, n, A, ans);


	for (auto q : ans) {
		for (auto w : q) {
			cout << w << " ";
		}
		cout << "\n";
	}


	return 0;
}