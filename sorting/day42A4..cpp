#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {


	vector<int>A = {927, 707, 374, 394, 279, 799, 878, 937, 431, 112};

	sort(begin(A), end(A));

	int n = A.size();

	for (auto q : A) {
		cout << q << " ";
	}

	int i = A.size() - 1;

	while (i > 0) {
		if (A[i] == A[i - 1]) {
			i--;
		} else {
			break;
		}
	}
	if (i != 0) {
		i--;
	}

	cout << "\n";

	cout << A[i] % A[n - 1];

	return 0;
}