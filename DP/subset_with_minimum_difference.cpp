#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main() {


	vector<int>A = {8, 4, 5, 7, 6, 2};

	int total = 0;
	int n = A.size();

	for (auto q : A) {
		total += q;
	}

	vector<bool>prev(total + 1, 0), cur(total + 1, 0);


	if (A[0] <= total) prev[A[0]] = 1;
	prev[0] = cur[0] = 1;


	for (int i = 1; i < n; i++) {
		for (int j = 1; j <= total; j++) {

			bool s1 = prev[j];

			bool s2 = false;
			if (A[i] <= j) {
				s2 = prev[j - A[i]];
			}
			cur[j] = s1 or s2;
		}
		prev = cur;
	}

	for (auto q : prev) {
		cout << q << " ";
	}
	cout << "\n";

	int len = total;
	int ans = INT_MAX;
	int res = INT_MAX;
	for (int i = 0; i < len; i++) {
		if (prev[i] == 1 and (i != total - i)) {
			int temp = abs(i - (total - i));
			if (ans > temp) {
				res = i;
				ans = min(ans, temp);
			}
		}
	}

	cout << ans << "\n";

	return 0;
}