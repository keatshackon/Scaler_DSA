#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {

	vector<int> A = {7, 1, 3, 4, 1, 7};
	map<int, int> map;

	int n = A.size();

	int ans = INT_MAX;

	for (int i = 1; i < n; i++) {
		if (map.count(A[i]) != 0) {
			int temp = i - map[A[i]];
			ans = min(ans, temp);
			map[A[i]] = i;
		} else {
			map[A[i]] = i;
		}
	}

	if (ans == INT_MAX) {
		cout << -1;
	} else {
		cout << ans;
	}



	return 0;
}