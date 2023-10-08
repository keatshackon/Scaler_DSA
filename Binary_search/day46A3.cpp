#include <bits/stdc++.h>
using namespace std;
#define ll long long



// O(NlogN) sol.
bool  check(vector<int>&A, int mid, int B) {

	int sum = 0;
	int n = A.size();

	for (int i = 0; i < mid; i++) {
		sum += A[i];
	}

	if (sum > B) {
		return false;
	}

	int j = mid;
	int i = 0;

	while (j < n) {
		sum += A[j];
		sum -= A[i];

		if (sum > B) {
			return false;
		}

		j++;
		i++;
	}
	return true;
}


int main() {


	vector<int>A = {2, 24, 38, 25, 35, 33, 43, 12, 49, 35, 45, 47, 5, 33};
	int B = 249;


	// int l = 1;
	// int r = A.size();

	// int ans = 0;

	// while (l <= r) {

	// 	int mid = (l + r) / 2;

	// 	if (check(A, mid, B)) {
	// 		ans = mid;
	// 		l = mid + 1;
	// 	} else {
	// 		r = mid - 1;
	// 	}
	// }

	// cout << ans << '\n';




	//O(n) appraoches;

	int i = 0;
	int j = 0;

	int n = A.size();

	int ans = -1;
	int sum = 0;

	int res = 0;


	while (j < n) {

		sum += A[j];
		res = j - i + 1;

		while (sum > B) {
			sum -= A[i];
			i++;
			if (ans == -1) {
				ans = res;
			} else {
				ans = min(res, j - i + 1);
			}
		}

		j++;
	}

	cout << ans;


	return 0;
}