#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007


int main() {


	int A = 3;
	vector<int>B = {6, 5};

	int n = B.size();

	priority_queue<int>pq;

	for (int i = 0; i < n; i++) {
		pq.push(B[i]);
	}

	int ans = 0;

	while (A) {
		int temp = pq.top();
		ans =  (ans % MOD + temp % MOD) % MOD;
		pq.pop();
		pq.push(temp / 2);
		A--;

	}

	cout << ans << "\n";

	return 0;
}