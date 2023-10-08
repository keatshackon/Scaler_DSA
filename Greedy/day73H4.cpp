#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main() {

	sort(begin(A), end(A));
	sort(begin(B), end(B));

	int ans = 0;
	int n = A.size();

	for (int i = 0; i < n; i++) {
		int temp = abs(A[i] - B[i]);
		ans = max(ans, temp);
	}

	return ans;
}