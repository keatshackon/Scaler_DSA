#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {


	vector<int>A = {2, 3, 4, 5, 2};

	int x = 0;

	for (int i = 0; i < A.size(); i++) {
		if (A[i] % 2 == 1) {
			x++;
		}
	}
	if (x % 2  == 0) {
		cout << "YES\n";
	} else {
		cout << "No\n";
	}

	return 0;
}