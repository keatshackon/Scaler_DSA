#include <bits/stdc++.h>
using namespace std;
#define ll long long

// void subset(vector<int>&A, set<vector<int>>&ans, vector<int>temp, int index, int target) {
// 	// insert the current subset to our answer
// 	if (target == 0) {
// 		ans.insert(temp);
// 		return;
// 	} else if (target < 0) {
// 		return;
// 	}
// 	if (index == A.size()) {
// 		return;
// 	}

// 	subset(A, ans, temp, index + 1, target);

// 	if (target >= A[index]) {
// 		temp.push_back(A[index]);
// 		subset(A, ans, temp, index, target - A[index]);
// 		temp.pop_back();
// 	}
// }

// By scaler[dosn't need to sort two time]
void solve(int idx, vector<int>&A, vector<int>&ds, vector<vector<int>>&ans, int target) {

	if (target == 0) {
		ans.push_back(ds);
		return;
	}

	if (idx == A.size() or target < 0) {
		return;
	}

	for (int i = idx; i < A.size(); i++) {
		if (i > idx  and A[i] == A[i - 1]) continue;

		ds.push_back(A[i]);
		solve(i, A, ds, ans, target - A[i]);
		ds.pop_back();
	}
}


int main() {

	vector<int>A = {2, 3, 6, 7};
	int target = 7;

	// if (A.size() == 0) return {{}};

	vector<int>ds;
	// set<vector<int>>ans;
	vector<vector<int>>ans;
	int idx = 0;

	sort(A.begin(), A.end());

	solve(idx, A, ds, ans, target);

	for (auto q : ans) {
		for (auto w : q) {
			cout << w << " ";
		}
		cout << "\n";
	}

	return 0;
}