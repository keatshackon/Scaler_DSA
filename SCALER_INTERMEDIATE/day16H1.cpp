#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() {

	vector<int> A = {408, 478, 74, 624, 74, 204, 705, 624, 337, 408, 478, 204};

	int x = 0;
	for (int i = 0; i < A.size(); i++) {
		x ^= A[i];
	}
	cout << x << "\n";
	int temp = x;
	int cnt = 0;
	while (temp) {
		if ((temp & 1) == 1) {
			cnt++;
			break;
		} else {
			cnt++;
		}
		temp = temp >> 1;
	}
	cout << cnt << "\n";
	cnt -= 1;
	cout << cnt << "\n";
	int s = 0;

	if (cnt <= 0) {
		s  = 1;
	} else {
		s = 1 << cnt;
	}

	cout << s << "\n";


	int r1 = 0, r2 = 0;

	for (int i = 0; i < A.size(); i++) {
		if ((A[i] & s) >= 1) {
			r1 ^= A[i];
		} else {
			r2 ^= A[i];
		}
	}

	cout << r1 << " " << r2 << "\n";


	int res1  = x ^ r1 ;
	int res2 =  x ^ res1;
	if (res2 > res1) {
		// return {res1, res2};
		cout << res1 << " " << res2;
	} else {
		// return {res2, res1};
		cout << res2 << " " << res1;
	}

	return 0;
}