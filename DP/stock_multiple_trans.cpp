#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main() {


	vector<int>A = {1, 2, 3};

	int ans = 0;
	int len = A.size();


	for (int i = 1; i < len; i++) {
		if (A[i] > A[i - 1]) {
			ans += (A[i] - A[i - 1]);
		}
	}

	cout << ans;
	return 0;
}