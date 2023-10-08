#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main() {


	vector<int>A = {3, 4, 1, 9, 56, 7, 9, 12};
	int B = 5;

	if (b == 0) return 0;

	sort(begin(A), end(A));

	int n = A.size();
	int i = 0;
	b--;
	int ans = INT_MAX;

	while (b < n) {
		ans = min(ans, A[b] - A[i]);
		b++;
		i++;
	}

	if (ans == INT_MAX) {
		return 0;
	}

	return ans;
	return 0;
}