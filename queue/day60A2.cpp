#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main() {


	vector<int>A = {2, 3, 1, 5, 4};
	vector<int>B = {1, 3, 5, 4, 2};

	int len = A.size();

	queue<int>q;

	for (int i = 0; i < len; i++) {
		q.push(A[i]);
	}

	int ans = 0;
	int i = 0;

	while (q.size()) {
		if (q.front() == B[i]) {
			q.pop();
			i++;
		} else {
			int temp = q.front();
			q.pop();
			q.push(temp);
		}
		ans++;
	}

	cout << ans << "\n";

	return 0;
}