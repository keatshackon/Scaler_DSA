#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main() {


	vector<int>A = { 0, 0, -1, 0};



	int i = 0;
	int n = A.size();

	int ans = INT_MIN;
	int sum = 0;
	int x = -1, y = -1, a1 = -1, a2 = -1;

	vector<int>res;

	while (i < n) {
		if (A[i] >= 0) {
			if (x == -1) {
				x = i;
				y = i;
				sum += A[i];
				if (sum >= ans) {
					ans = sum;
					a1 = i;
					a2 = i;
				}
				cout << a1 << a2 << "\n";
			} else if (x != -1) {
				y = i;
				sum += A[i];
				if (sum > ans) {
					ans = sum;
					a1 = x;
					a2 = y;
				}
			}
		} else {
			sum = 0;
			x = -1;
			y = -1;
		}
		i++;
	}

	cout << sum << "\n";

	if (sum > ans) {
		cout << "ad";
		a1 = x;
		a2 = y;
	}

	cout << a1 << " " << a2 << "\n";
	cout << ans << "\n";


	while (a1 > -1 and a2 > -1 and a1 <= a2) {
		res.push_back(A[a1]);
		a1++;
	}

	for (auto q : res) {
		cout << q << " ";
	}

	return 0;
}