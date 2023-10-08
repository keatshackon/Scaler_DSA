#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main() {


	int A = 3;

	// if (A == 1) {
	// 	return {1};
	// } else if (A == 2) {
	// 	return {1, 2};
	// } else if (A == 3) {
	// 	return {1, 2, 3};
	// }

	vector<int>ans;

	queue<int>q;
	q.push(1);
	q.push(2);
	q.push(3);

	ans.push_back(1);
	ans.push_back(2);
	ans.push_back(3);


	int cnt = 3;

	while (true) {
		int temp = q.front();
		q.pop();
		q.push(temp * 10 + 1);
		cnt++;
		ans.push_back(temp * 10 + 1);
		if (cnt == A) {
			return ans;
		}
		q.push(temp * 10 + 2);
		cnt++;
		ans.push_back(temp * 10 + 2);
		if (cnt == A) {
			return ans;
		}
		q.push(temp * 10 + 3);
		cnt++;
		ans.push_back(temp * 10 + 3);
		if (cnt == A) {
			return ans;
		}
	}


	return 0;
}