#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007


int main() {


	vector<int>A = {2, 5, -1, 7, -3, -1, -2};
	int B = 4;


	// For greater element
	deque<int>d1;

	// For Smaller element
	deque<int>d2;


	vector<int>res1;

	int i = 0;
	int j = 0;

	int n = A.size();

	int ans = 0;

	while (j < n) {
		if (j - i < B - 1) {
			if (d1.empty()) {
				d1.push_back(A[j]);
			} else {
				while (!d1.empty() and d1.back() < A[j]) {
					d1.pop_back();
				}
				d1.push_back(A[j]);
			}

			if (d2.empty()) {
				d2.push_back(A[j]);
			} else {
				while (!d2.empty() and d2.back() > A[j]) {
					d2.pop_back();
				}
				d2.push_back(A[j]);
			}
			j++;
		} else {


			while (!d1.empty() and d1.back() < A[j]) {
				d1.pop_back();
			}
			d1.push_back(A[j]);


			while (!d2.empty() and d2.back() > A[j]) {
				d2.pop_back();
			}
			d2.push_back(A[j]);

			res1.push_back(d1.front());


			ans = (ans % MOD +  d1.front() % MOD +
			       d2.front() % MOD ) % MOD;

			if (d1.front() == A[i]) {
				d1.pop_front();
			}

			if (d2.front() == A[i]) {
				d2.pop_front();
			}
			j++;
			i++;
		}
	}
	// for (auto q : res1) {
	// 	cout << q << " ";
	// }


	cout << ans;

	return 0;
}