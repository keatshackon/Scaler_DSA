#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() {


	vector<int>A = {1, 2, 2, 1, 2, 3, 1};
	int ans = 0;

	int n = A.size();

	for (int i = 0; i < 31; i++) {
		int one = 0;
		for (int j = 0; j < n; j++) {
			if ((A[j] & (1 << i)) != 0) {
				one++;
			}
		}
		if (one % 3 != 0) {
			ans = ans | (1 << i);
		}

	}

	cout << ans << '\n';

	return 0;
}