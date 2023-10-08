#include <bits/stdc++.h>
using namespace std;
#define ll long long


bool static cmp(pair<int, int>a, pair<int, int>b) {

	if (a.second == b.second) {
		return a.first < b.first;
	}
	if (a.second < b.second) {
		return true;
	}
	return false;
}

int main() {


	vector<int> start = {7, 6, 2, 7, 3};
	vector<int>end = {10, 6 , 10, 9, 5};


	int n =  start.size();

	vector<pair<int, int>>C;

	for (int i = 0; i < n; i++) {
		C.push_back({start[i], end[i]});
	}

	sort(C.begin(), C.end(), cmp);

	int ans = 1;
	int res = C[0].second;

	for (int i = 1; i < n; i++) {
		if (C[i].first > res) {
			ans++;
			res = C[i].second;
		}
	}

	cout << ans << "\n";

	return 0;
}