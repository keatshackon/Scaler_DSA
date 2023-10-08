#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(int n, vector<pair<int, int>>&m, vector<int>&ds, vector<vector<int>>&ans) {

	if (ds.size() == n) {
		ans.push_back(ds);
		return;
	}
	for (int i = 0; i < m.size(); i++) {

		if (m[i].second > 0) {
			ds.push_back(m[i].first);
			m[i].second--;
			solve( n, m, ds, ans);
			m[i].second ++;
			ds.pop_back();
		}
	}
}


int main() {

	vector<int>A = {1, 2, 3, 4, 5};

	vector<vector<int>>ans;
	vector<int>ds;
	int idx = 0;


	map<int, int> m;
	vector<pair<int, int>>v;
	int n = A.size();

	for (auto q : A) {
		m[q]++;
	}

	for (auto q : m) {
		v.push_back({q.first, q.second});
	}


	solve( n, v, ds, ans);


	for (auto q : ans) {
		for (auto w : q) {
			cout << w << " ";
		}
		cout << "\n";
	}

	return 0;
}