#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(int idx, vector<int>nums, vector<vector<int>>&ans) {

	if (idx == nums.size()) {
		ans.push_back(nums);
		return;
	}
	for (int i = idx; i < nums.size(); i++) {
		swap(nums[idx], nums[i]);
		solve(idx + 1, nums, ans);
		swap(nums[idx], nums[i]);
	}
}



int main() {

	vector<int>A = {1, 2, 3};

	vector<vector<int>>ans;
	int idx = 0;
	solve(idx, A, ans);

	for (auto q : ans) {
		for (auto w : q) {
			cout << w << " ";
		}
		cout << "\n";
	}

	return 0;
}