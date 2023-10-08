#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(int idx, int n, vector<int>&A, vector<int>&ds, vector<vector<int>>&ans) {

	if (idx == n) {
		ans.push_back(ds);
		return;
	}

	ds.push_back(A[idx]);
	solve(idx + 1, n, A, ds, ans);
	ds.pop_back();

	solve(idx + 1, n, A, ds, ans);
}


int main() {


	vector<int>A = {1, 2, 3};

	int idx = 0;
	vector<int>ds;
	vector<vector<int>>ans;

	int n = A.size();

	sort(A.begin(), A.end());

	solve(idx, n, A, ds, ans);

	sort(ans.begin(), ans.end());

	for (auto q : ans) {
		for (auto w : q) {
			cout << w << " ";
		}
		cout << "\n";
	}

	return 0;
}
