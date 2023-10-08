#include <bits/stdc++.h>
using namespace std;
#define ll long long


vector<int> left_smallest(vector<int>&his) {

	stack<pair<int, int>>ls;
	int len = his.size();
	vector<int>res(len);

	ls.push({his[0], 0});
	res[0] = 0;

	for (int i = 1; i < len; i++) {
		if (his[i] > ls.top().first) {
			ls.push({his[i], i});
			res[i] = i - 1;
		} else {
			while (!ls.empty() and his[i] <= ls.top().first) {
				ls.pop();
			}
			if (ls.empty()) {
				res[i] = 0;
			} else {
				res[i] = ls.top().second;
			}
			ls.push({his[i], i});
		}
	}

	return res;
}

vector<int> right_smallest(vector<int>&his) {

	stack<pair<int, int>>rs;
	int len = his.size();
	vector<int>res(len);

	rs.push({his[len - 1], len});
	res[len - 1] = len;

	for (int i = len - 2; i >= 0 ; i--) {
		if (his[i] > rs.top().first) {
			rs.push({his[i], i});
			res[i] = i + 1;
		} else {
			while (!rs.empty() and his[i] <= rs.top().first) {
				rs.pop();
			}
			if (rs.empty()) {
				res[i] = len;
			} else {
				res[i] = rs.top().second;
			}
			rs.push({his[i], i});
		}
	}

	return res;
}



int main() {

	vector<int>his = {2, 1, 5, 6, 2, 3};

	vector<int>ans1 = left_smallest(his);
	vector<int>ans2 = right_smallest(his);


	int len = his.size();
	int ans = 0;

	for (int i = 0; i < len; i++) {
		int res = ((ans2[i] - ans1[i]) - 1) * his[i];
		ans = max(ans, res);
	}

	cout << ans << "\n";

	return 0;
}