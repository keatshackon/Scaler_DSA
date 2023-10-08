#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main() {


	string A = "fnmzxvozgkpkwuuwbnlbajogijoaxipjwwfaqefjnvfbcilerkdaeysamehgdouvspojtuvh";

	int i = 0;
	int n = A.length();
	int cnt = 0;

	while (i < n) {

		if (A[i] == 'a') {
			cnt++;
		}
		i++;
	}
	cout << (cnt * (cnt + 1)) / 2;

	return 0;
}