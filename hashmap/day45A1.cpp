#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main() {


	vector<int> A = {1, 3, 5, 6};
	int B = 5;



	int i = 0;
	int j = A.size() - 1;
	int f = 0;

	while (i <= j) {
		int mid = (i + j) / 2;

		if (A[mid] == B) {
			cout << mid << "\n";
			f = 1;
			break;
		} else if (A[mid] < B) {
			i = mid + 1;
			ans = i;
		} else {
			j = mid - 1;
		}
	}

	if (f == 0) {
		cout << ans + 1 << "\n";
	}



	return 0;
}