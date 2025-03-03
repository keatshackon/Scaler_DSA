#include<bits/stdc++.h>
using namespace std;
#define ll long long


int main() {


	string A =  "111011100";
	int cnt = 0;
	int ans = 0;
	int f = 0;

	for (int i = 0; i < A.length(); i++) {
		if (A[i] == '1') {
			cnt++;
		}
	}
	int ones  = cnt;
	cnt = 0;
	for (int i = 0; i < A.length(); i++) {
		if (A[i] == '0') {
			int j = i - 1;
			int k = i + 1;
			cnt = 0;
			while (j >= 0 and A[j] == '1') {
				cnt++;
				j--;
			}
			while (k < A.length() and A[k] == '1') {
				cnt++;
				k++;
			}
			if (cnt == ones) {
				ans = max(ans, cnt);
			} else {
				ans = max(ans, cnt + 1);
			}

		}
	}
	cout << ans;


	return 0;
}

