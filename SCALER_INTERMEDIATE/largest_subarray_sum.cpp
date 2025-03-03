#include<bits/stdc++.h>
using namespace std;
#define ll long long


int main() {

	vector<int> A =  { -2, 1, -3, 4, -1, 2, 1, -5, 4} ;

	int sum = 0;
	int ans = 0;
	int res = A[0];
	for (int i = 1; i < A.size(); i++) {
		if (res + A[i] > res) {
			ans = res + A[i];
			res +=  A[i];
		} else {
			res  = A[i];
		}
	}

	cout << ans;

	return 0;
}