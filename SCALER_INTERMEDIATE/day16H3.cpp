#include<bits/stdc++.h>
using namespace std;
#define ll long long


int main() {

	vector<int> B = {1, 1, 1, 1};

	int i = 0;
	int cnt = 0;
	int res = 0;
	while (i < B.size()) {

		if (B[i] == 0) {
			cnt++;
		} else {
			res += (cnt * (cnt + 1)) / 2;
			cnt = 0;
		}
		i++;

	}
	// cout << res << "\n";
	// cout << cnt << "\n";
	if (cnt > 0) {
		res += (cnt * (cnt + 1)) / 2;
	}
	int k = B.size();
	cout << (k * (k + 1)) / 2 - res;
	return 0;
}