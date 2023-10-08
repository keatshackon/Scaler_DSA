#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main() {


	vector<int>A = {0, 0, 1967513926, 1540383426, -1303455736, -521595368};


	int n = A.size();
	int i = 0;
	int j = 0;

	int x = -1, y = -1;
	long long sum = 0;
	long long ans = INT_MIN;

	while (i < n) {

		if (A[i] >= 0) {
			j = i;
			sum = 0;
			while (A[j] >= 0 and j < n) {
				sum += A[j];
				j++;
			}

			if (ans < sum) {
				ans = sum;
				x = i;
				y = j - 1;
			}
			j = i - 1;
		}
		if (j == n) {
			break;
		}
		i++;
	}

	if (ans < sum) {
		x = i;
		y = j - 1;
	}

	cout << x << " " << y << "\n";

	vector<int>res;

	for (int i = x; x >= 0 and i <= y; i++) {
		res.push_back(A[i]);
	}

	for (auto q : res) {
		cout << q << " ";
	}
	cout << "\n";

	return 0;
}