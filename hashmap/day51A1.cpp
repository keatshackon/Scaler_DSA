#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main() {


	vector<int> A = {100, 4, 400, 1, 3, 2};

	map<int, int> map;

	int n = A.size();

	for (int i = 0; i < n; i++) {
		map[A[i]]++;
	}

	vector<int>v;

	for (auto q : map) {
		v.push_back(q.first);
	}

	sort(v.begin(), v.end());
	int cnt = 1, ans = 0;

	n = map.size() - 1;

	for (int i = 0; i < n; i++) {
		if (v[i + 1] - v[i] <= 1) {
			cnt++;
		} else {
			ans = max(ans, cnt);
			cnt = 1;
		}
	}

	ans = max(ans, cnt);

	//return ans;

	return 0;
}