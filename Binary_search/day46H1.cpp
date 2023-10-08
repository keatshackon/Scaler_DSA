#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main() {


	vector<int>A = {2 , 1, 4 , 3 , 2};
	int k = 3;


	int minn = INT_MAX;
	int maxx = INT_MIN;

	for (auto q : A) {
		if (q > maxx) {
			maxx = q;
		}

		if (q < minn) {
			minn = q;
		}
	}

	cout << minn << " " << maxx << "\n";


	int n = A.size();


	while (minn <= maxx) {

		int mid = (minn + maxx) / 2;
		int cnt1 = 0;
		int cnt2 = 0;

		for (int i = 0; i < n; i++) {
			if (A[i] < mid) {
				cnt1++;
			} else if (A[i] == mid) {
				cnt2++;
			}
		}


		if (cnt1 >= k) {
			maxx = mid - 1;
		} else if (cnt1 < k and cnt1 + cnt2 <= k) {
			cout << mid << "\n";
			return 0;
		} else if (cnt1 + cnt2 < k) {
			minn = mid + 1;
		}

	}

	return 0;
}