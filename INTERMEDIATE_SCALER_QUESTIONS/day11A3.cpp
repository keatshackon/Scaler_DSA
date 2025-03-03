#include<bits/stdc++.h>
using namespace std;
#define ll long long


int main() {

	vector<int>A = { 20, 3, 13, 5, 10, 14, 8, 5, 11, 9, 1, 11 };
	int B = 9;

	vector<int>prefix(A.size());
	prefix[0] = A[0];
	for (int i = 1; i < A.size(); i++) {
		prefix[i] = prefix[i - 1] + A[i];
	}

	float ans = INT_MAX;
	int res = -1;
	for (int i = 0; i < A.size(); i++) {
		if (i + B - 1 < A.size() and i == 0) {
			if ((ans > prefix[i + B - 1] / B)) {
				ans = prefix[i + B - 1] / B;
				cout << ans << "\n";
				res = i;
			}
		} else if (i + B - 1 < A.size()) {
			float temp = ((prefix[i + B - 1] - prefix[i - 1]) / B);
			cout << temp << "\n";
			if (ans > temp) {
				ans = temp;
				cout << ans << "\n";
				res = i;
			}
		}
	}
	cout << res;

	return 0;
}