#include <bits/stdc++.h>
using namespace std;
#define ll long long


bool cmp(pair<int, int> a, pair<int, int>b) {

	if (b.second > a.second) {
		return true;
	}
	return false;
}

int main() {


	vector<int>A = {1, 5, 7, 1};
	vector<int>B = {7, 8, 8, 8};


	vector<pair<int, int>>m;

	int n = A.size();


	for (int i = 0; i < n; i++) {
		m.push_back({A[i], B[i]});
	}
	sort(m.begin(), m.end(), cmp);


	for (auto q : m) {
		cout << q.first << " " << q.second << "\n";
	}

	int ans = 1;
	int res = m[0].second;

	for (int i = 1; i < n; i++) {
		if (res <= m[i].first) {
			ans++;
			res = m[i].second;
		}
	}

	cout << ans << "\n";



	return 0;
}