#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main() {


	string A = "123";

	if (A.length() == 1 and A[0] != '0') {
		return 1;
	}

	int n = A.length();

	vector<int>dp(n);
	dp[0] = 1;
	dp[1] = 1;

	string tt = "";
	tt += A[0];
	tt += A[1];
	int t = stoi(tt);

	if (t >= 1 and t <= 26) {
		dp[1] = 2;
	}

	for (int i = 2; i < n; i++) {
		int temp = dp[i - 1];

		if (A[i] >= '1' and A[i] <= '9' and A[i - 1] <= '2' and A[i - 1] >= '1') {
			temp += dp[i - 2];
		}
		dp[i] =  temp;
	}


	cout << dp[n - 1];

	return 0;
}
