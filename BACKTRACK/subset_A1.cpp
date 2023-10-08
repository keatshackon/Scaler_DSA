#include <bits/stdc++.h>
using namespace std;
#define ll long long

// By scaler[dosn't need to sort two time]
void subset(vector<int>&A, vector<vector<int>>&ans, vector<int>temp, int index) {
	// insert the current subset to our answer
	ans.push_back(temp);
	for (int i = index; i < A.size(); i++) {
		// for every element we can either take it or skip it
		temp.push_back(A[i]);
		subset(A, ans, temp, i + 1);
		temp.pop_back();
	}
	return;
}

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

	vector<int>A = {2, 12, 13};

	// if (A.size() == 0) return {{}};

	vector<int>ds;
	vector<vector<int>>ans;
	int idx = 0, n = A.size();

	sort(A.begin(), A.end());

	// solve(idx, n, A, ds, ans);
	// sort(ans.begin(), ans.end());

	subset(A, ans, ds, idx);

	for (auto q : ans) {
		for (auto w : q) {
			cout << w << " ";
		}
		cout << "\n";
	}

	return 0;
}