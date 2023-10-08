#include <bits/stdc++.h>
using namespace std;
#define ll long long


// INCOMPLETE.


int solve(int n) {



	for (int i = 1; i <= 3; i++) {

	}



}


int main() {

	vector<int>	A = {3, 2, 1};
	int B = 1;
	int C = -10;
	int D = 3;


	int len = A.size();

	vector<int>dp;

	int ans = INT_MIN;

	for (int x = 0; x <= len - 3; x++) {
		for (int i = x; i < len; i++) {
			for (int j = i; j < len; j++) {
				for (int k = j; k < len; k++) {
					ans = max(ans, A[i] * B + A[j] * C + A[k] * D);
				}
			}
		}
	}


	cout << ans;



	return 0;
}