#include <bits/stdc++.h>
using namespace std;
#define ll long long


void solve(int idx, vector<int>&A, vector<int>&ds, vector<vector<int>>&ans, int n) {

	if (ds.size() == n) {
		ans.push_back(ds);
		return;
	}

	if (idx == A.size()) {
		return;
	}

	for (int i = 0; i < A.size(); i++) {
		ds.push_back(A[i]);
		solve(i, A, ds, ans, n);
		ds.pop_back();
	}

}

int main() {

	int n = 3;
	vector<int>A = {1, 2, 3};

	vector<vector<int>>ans;
	vector<int>ds;

	solve(0, A, ds, ans, n);

	for (auto q : ans) {
		for (auto w : q) {
			cout << w << " ";
		}
		cout << "\n";
	}

	return 0;
}