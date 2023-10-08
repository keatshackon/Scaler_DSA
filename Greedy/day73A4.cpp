#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 10000003


int main() {


	string A = ".x.x.x..x";

	int len = A.length();

	vector<int>v;

	for (int i = 0; i < len; i++) {
		if (A[i] == 'x') {
			v.push_back(i);
		}
	}

	int n = v.size();

	int mid = n / 2;
	int left = mid - 1;
	int right = mid + 1;
	int k = 1;

	int ans = 0;

	while (left >= 0) {
		ans = (ans % MOD  + (v[mid] - k - v[left]) % MOD ) % MOD;
		k++;
		left--;
	}

	k = 1;

	while (right < n) {
		ans = (ans % MOD +  (v[right]  - k - v[mid]) % MOD ) % MOD;
		k ++;
		right++;
	}

	cout << ans;

	return 0;
}