#include <bits/stdc++.h>
using namespace std;
#define ll long long



void solve(int idx, int n, vector<int>&A, vector<int>&ds, vector<vector<int>>&ans) {


	if (idx == n) {
		ans.push_back(ds);
		return;
	}


	for (int i = 0; i < A.size(); i++) {
		ds.push_back(A[i]);
		solve(idx + 1, n, A, ds, ans);
		ds.pop_back();
	}
}


int main() {


	int n = 3;
	vector<int >A = {1, 2};

	int len = A.size();

	vector<int>ds;
	vector<vector<int>>ans;

	solve(0, n, A, ds, ans);

	for (auto q : ans) {
		for (auto w : q) {
			cout << w << " ";
		}
		cout << "\n";
	}

	return 0;
}
