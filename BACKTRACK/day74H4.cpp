#include <bits/stdc++.h>
using namespace std;
#define ll long long


// METHOD-1 USING SET TO AVOID DPULICATE ELEMENT
// void solve(int idx, int n, vector<int>&A, vector<int>&ds, set<vector<int>>&ans) {

// 	if (idx == n) {
// 		ans.insert(ds);
// 		return;
// 	}

// 	solve(idx + 1, n, A, ds, ans);

// 	ds.push_back(A[idx]);
// 	solve(idx + 1, n, A, ds, ans);
// 	ds.pop_back();
// }

void backtrack(int first, int n, vector<int>&nums, vector<int>&curr, vector<vector<int>>&output) {
	// if the combination is done
	// if (curr.size() == n) {
	// 	output.push_back(curr);
	// 	return;
	// }

	output.push_back(curr);
	for (int i = first; i < n; ++i) {
		if (i != first and nums[i] == nums[i - 1]) continue;
		// add i into the current combination
		curr.push_back(nums[i]);
		// use next integers to complete the combination
		backtrack(i + 1, n, nums, curr, output);
		// backtrack
		curr.pop_back();
	}
}



int main() {


	vector<int>nums = {1, 2, 1};


	// int idx = 0;
	vector<int>ds;
	// //set<vector<int>>ans;
	// vector<vector<int>>res;

	sort(nums.begin(), nums.end());

	// solve(idx, n, A, ds, ans);

	//solve(idx, n, A, ds, res);

	//sort(res.begin(), res.end());

	// for (auto q : ans) {
	// 	res.push_back(q);
	// }


	//

	vector<vector<int>>output;
	int n = nums.size();
	backtrack(0, n, nums, ds, output);

	for (auto q : output) {
		for (auto w : q) {
			cout << w << " ";
		}
		cout << "\n";
	}


	return 0;
}