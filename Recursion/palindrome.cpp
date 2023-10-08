#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool check(string s, int l, int k) {

	if (l >= k) {
		return 1;
	}
	if (s[l] == s[k]) {
		return check(s, l + 1, k - 1);
	}
	return 0;
}


int main() {

	string A = "edabde";
	int e = A.length() - 1;
	int t = check(A, 0, e);

	cout << t;

	return 0;

}