#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {

	vector<int> A = {17, 18, 8, 13, 15, 7, 11, 5, 4, 9, 12, 6, 10, 14, 16, 3};
	map<int, int> m;
	int B = 9;
	int cnt = 0;
	for (int i = 0; A.size(); i++) {
		if (m.count(A[i]) != 0) {
			cnt++;
		} else {
			m[A[i] ^ B] = 1;
		}
	}
	cout << cnt;
	return 0;

}