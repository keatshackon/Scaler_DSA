#include <bits/stdc++.h>
using namespace std;
#define ll long long


void solve(int idx, int n, int target, int sum, vector<int>&A, vector<int>&ds, vector<vector<int>>&ans) {


	if (target == sum) {
		ans.push_back(ds);
		return;
	}
	if (idx == n or sum > target) {
		return;
	}

	// use i=0 when you want break the order meaning if u want taking subset.
	for (int i = idx; i < n; i++) {
		sum += A[i];
		ds.push_back(A[i]);
		solve(i, n, target, sum, A, ds, ans);
		ds.pop_back();
		sum -= A[i];
	}
}

int main() {


	vector<int>A = {2, 3, 6, 7};
	int target = 7;
	int idx = 0, sum = 0;

	vector<int>ds;
	vector<vector<int>>ans;

	int n = A.size();

	solve(idx, n, target, sum, A, ds, ans);


	for (auto q : ans) {
		for (auto w : q) {
			cout << w << " ";
		}
		cout << "\n";
	}



	return 0;
}