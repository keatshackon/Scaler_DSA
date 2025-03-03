#include<bits/stdc++.h>
using namespace std;
#define ll long long


int main() {

	vector<int> v =  { -2, 1, -3, 4, -1, 2, 1, -5, 4} ;

	int sum = 0;
	int ans = INT_MIN;
	for (int i = 0; i < v.size(); i++) {
		for (int  j = i; j < v.size(); j++) {
			sum = 0;
			for (int k = i; k <= j; k++) {
				sum += v[k];
			}
			if (sum > ans) {
				ans = sum;
			}
		}
	}

	cout << ans;

	return 0;
}