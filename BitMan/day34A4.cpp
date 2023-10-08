#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() {


	string A = "10101";
	string B = "1011";

	string ans = "";


	int carry = 0;
	int i = A.length() - 1;
	int j = B.length() - 1;

	while (i >= 0 or j >= 0) {

		if (i >= 0) {
			carry += A[i] - '0';
		}

		if (j >= 0) {
			carry += B[j] - '0';
		}

		if (carry == 3) {
			ans += '1';
			carry = 1;
		} else if (carry == 2) {
			ans += '0';
			carry = 1;
		} else if (carry == 1) {
			ans += '1';
			carry = 0;
		} else {
			ans += '0';
			carry = 0;
		}
		i--;
		j--;

	}

	if (carry > 0)
		ans += "1";


	reverse(ans.begin(), ans.end());

	cout << ans << "\n";


	return 0;
}