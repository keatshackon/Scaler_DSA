#include <bits/stdc++.h>
using namespace std;
#define ll long long

// contribution technique O(N) approache
void solve(vector<int>&A) {

	int n = A.size();
	int ans = 0;

	for (int i = 0; i < n; i++) {
		ans += ((n - i) * (i + 1) * A[i]);
	}
	cout << ans;
}

int main() {


	vector<int>A = {2, 3, 4};


	int n = A.size();

	// BRUTE FROCE WAYS O(N^3) approache
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			int sum = 0;
			for (int k = i; k <= j; k++ ) {
				sum  += A[k];
			}
			ans += sum;
		}
	}
	cout << ans << "\n";

	solve(A);


	return 0;
}