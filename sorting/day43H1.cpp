#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main() {

	vector<int>A = {2, 4, 3, 4, 5, 3};


	map<int, int> m;
	int n = A.size();

	for (int i = 0; i < n; i++) {
		m[A[i]]++;
	}

	int cnt = 0;

	for (auto q : m) {
		while (q.second > 1) {
			cnt++;
			int temp = q.first + 1;
			m[temp]++;
			q.second--;
		}
	}

	cout << cnt;

	return 0;
}
