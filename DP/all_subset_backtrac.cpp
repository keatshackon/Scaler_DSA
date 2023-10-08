#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Using CASCADING- LEETCODE SOLUTION
vector<vector<int>> solve1(vector<int>v) {

	vector<vector<int>>output;
	output.push_back({});

	for (auto q : v) {
		vector<vector<int>>temp;
		for (auto cur : output) {
			cur.push_back(q);
			temp.push_back(cur);
		}
		for (auto t : temp) {
			output.push_back(t);
		}
	}
	return output;
}

// Using Backtracking
void solve2(int idx, vector<int>v, vector<int>ds, vector<vector<int>>&ans) {

	if (idx == v.size()) {
		ans.push_back(ds);
		return;
	}
	ds.push_back(v[idx]);
	solve2(idx + 1, v, ds, ans);
	ds.pop_back();
	solve2(idx + 1, v, ds, ans);
}

int main() {

	vector<int>v = {1, 2, 3};

	//Method 2 using BackTrackings
	vector<vector<int>>ans;
	int idx = 0;
	vector<int>ds;
	solve2(idx, v, ds , ans);

	for (auto q : ans) {
		if (q.size() == 0) {
			cout << "{}" << "\n";
			continue;
		}
		for (auto w : q) {
			cout << w << " ";
		}
		cout << "\n";
	}

	// Method 1
	// vector<vector<int>>ans =  solve1(v);

	// for (auto q : ans) {
	// 	if (q.size() == 0) {
	// 		cout << "{}" << "\n";
	// 		continue;
	// 	}
	// 	for (auto w : q) {
	// 		cout << w << " ";
	// 	}
	// 	cout << "\n";
	// }

	return 0;
}
