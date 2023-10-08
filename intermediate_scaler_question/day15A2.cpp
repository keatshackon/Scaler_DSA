#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() {

	ll t, n;
	string a = "1010101";
	string b = "1011101";

	int k = a.length() - 1;
	int l = b.length() - 1;

	string ans = "";
	int carry = 0 ;
	int sum = 0;
	while (k >= 0  or l >= 0) {

		sum = carry;

		if (k >= 0 ) {
			int s1 = a[k] - '0';
			sum += s1;
		}
		if (l >= 0 ) {
			int s2 = b[l] - '0';
			sum += s2;
		}
		carry = sum / 2;
		ans += to_string(sum % 2);
		k--;
		l--;
	}

	if (carry != 0) {
		ans += '1';
	}

	reverse(ans.begin(), ans.end());

	cout << ans;



	return 0;
}