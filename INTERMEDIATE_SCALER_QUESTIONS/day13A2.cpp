#include<bits/stdc++.h>
using namespace std;
#define ll long long


int main() {


	vector<vector<int>> v = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

	int j = v.size();
	vector<vector<int>>ans(j + j - 1, vector<int>(v[0].size(), 0));
	int x = 0;
	int y = 0;
	for (int i = 0; i < v.size(); ++i) {
		int k = i;
		int j = 0;
		y = 0;
		while (k >= 0 and j < v.size()) {
			ans[x][y] = v[j][k];
			k--;
			j++;
			y++;
		}
		x++;
	}

	for (int i = 1; i < v.size(); i++) {
		int k = v[0].size() - 1;
		int j = i;
		y = 0;
		while (k >= 0 and j < v.size()) {
			ans[x][y] = v[j][k];
			k--;
			j++;
			y++;
		}
		x++;
	}

	for (auto q : ans) {
		for (auto w : q) {
			cout << w << " ";
		}
		cout << "\n";
	}

	return 0;
}