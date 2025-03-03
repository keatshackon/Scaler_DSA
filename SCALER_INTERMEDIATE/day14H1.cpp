#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() {


	vector<int> v = {8986143, -5026827, 5591744, 4058312, 2210051, 5680315,
	                 -5251946, -607433, 1633303, 2186575
	                };

	vector<int>result;
	int cnt = 0;
	int ans = INT_MIN;
	int res = -1;
	for (int i = 0; i < v.size(); i++) {
		if (v[i] >= 0) {
			cnt++;
		} else {
			if (cnt > ans) {
				res  = (i - cnt);
				ans = cnt;
			}
			cnt = 0;
		}
	}
	if (cnt > ans) {
		res  =  v.size() - cnt;
	}
	cout << res << "\n";
	cout << ans;

	for (int j = res; v[j] >= 0 and j < v.size() ; j++) {
		result.push_back(v[j]);
	}
	cout << "\n";
	for (auto q : result) {
		cout << q << " ";
	}
	return 0;
}