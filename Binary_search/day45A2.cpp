#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {

	vector<int>A = {1, 1000000000, 1000000000};
	int n = A.size();

	if (A.size() == 1) {
		cout << A[0];
		return 0;
	} else if (A[0] > A[1] and A[0] > A[A.size() - 1]) {
		cout << A[0];
		return 0;
	} else if (A[A.size() - 1] > A[A.size() - 2] and A[A.size()] > A[0]) {
		cout << A[A.size() - 1];
		return 0;
	}

	int i = 1;
	int j = A.size() - 2;

	while (i <= j) {

		int mid = (i + j) / 2;

		if (A[mid] > A[mid - 1] and A[mid] > A[mid + 1]) {
			cout << A[mid] << "\n";
			break;
		} else if (A[mid] > A[mid - 1]) {
			i = mid + 1;
		} else {
			j = mid - 1;
		}
	}


	return 0;
}