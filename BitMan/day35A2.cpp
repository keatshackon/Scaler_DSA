#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {


	vector<int>A = {1, 2, 3, 4, 5};

	long len = A.size();
	long total = (len * (len + 1)) / 2;

	long temp = total;
	int ans = 0;


	for (int i = 0; i < 31; i++) {
		long  x = 0;
		for (int j = 0; j < len; j++) {
			if ((A[j] & (1 << i)) == 0) {
				x++;
			} else {
				total -= (x * (x + 1) / 2);
				x = 0;
			}
		}
		total -= (x * (x + 1) / 2);
		ans = (ans % MOD +  (total * (int)pow(2, i) %  MOD)) % MOD;
		total = temp;
	}
	return 0;
}