#include <bits/stdc++.h>
using namespace std;
#define ll long long


bool check(vector<int>v) {

	for (int i = 1; i < v.size(); i++) {
		if (v[i] < v[i - 1]) {
			return false;
		}
	}
	return true;
}

int main() {

	vector<int>B = {2, 3, 1};
	vector<int>A(B.size());
	vector<int>temp(B.size());

	for (int i = 0; i < A.size(); i++) {
		A[i] = i + 1;
	}

	int cnt = 0;
	while (true) {
		for (int i = 0; i < B.size(); i++) {
			temp[B[i] - 1] = A[i];
		}
		for (auto q : temp) {
			cout << q << " ";
		}
		cout << "\n";
		if (check(temp)) {
			break;
		}
		for (int i = 0; i < temp.size(); i++) {
			A[i] = temp[i];
		}

		for (auto q : A) {
			cout << q << " ";
		}
		cout << "\n";
		cnt++;
	}
	cnt++;

	cout << cnt;

	return 0;
}