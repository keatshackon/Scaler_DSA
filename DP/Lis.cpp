#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(int idx, vector<int>&v, vector<int>&ds, int &ans) {

	if (idx == v.size()) {
		int temp = 0;
		if (ds.size() > 2) {
			for (int i = 1; i < ds.size(); i++) {
				if (v[i] >= v[i - 1]) {
					temp++;
				}
			}
		}
		ans = max(temp, ans);
		return;
	}
	ds.push_back(v[idx]);
	solve(idx + 1, v, ds, ans);
	ds.pop_back();
	solve(idx + 1, v, ds, ans);

}
int main() {

	vector<int>v = {10, 3, 12, 7, 2, 9, 11, 20, 11, 13, 6, 8};

	int ans = 0;
	vector<int>ds;
	solve(0, v, ds, ans);

	cout << ans;
	return 0;
}