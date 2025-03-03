#include<bits/stdc++.h>
using namespace std;
#define ll long long


int solve(vector<int>&A) {

	vector<int>preOdd(A.size());
	vector<int>preEve(A.size());
	preOdd[0] = 0;
	preEve[0] = A[0];
	for (int i = 1; i < A.size(); i++) {
		if (i % 2 == 1) {
			preOdd[i] = preOdd[i - 1] + A[i];
		} else {
			preOdd[i] = preOdd[i - 1];
		}
	}

	for (int i = 1; i < A.size(); i++) {
		if (i % 2 == 0) {
			preEve[i] = preEve[i - 1] + A[i];
		} else {
			preEve[i] = preEve[i - 1];
		}
	}

	for (auto q : preEve) {
		cout << q << " ";
	}
	cout << "\n";
	for (auto q : preOdd) {
		cout << q << " ";
	}
	int cnt = 0;
	if ((preOdd[preOdd.size() - 1] - preOdd[0]) == preEve[preEve.size() - 1] - preEve[0]) {
		cnt++;
	}
	if ((preOdd[preOdd.size() - 2]) == preEve[preEve.size() - 2]) {
		cnt++;
	}
	for (int i = 1; i < A.size() - 1; i++) {
		int eveSum = preEve[i - 1]  + (preOdd[preOdd.size() - 1] - preOdd[i]);
		int oddSum = preOdd[i - 1]  + (preEve[preEve.size() - 1] - preEve[i]);
		if (eveSum == oddSum) {
			cnt++;
		}
	}

	return cnt;
}


int main() {


	vector<int> v{1, 1, 1};

	cout << solve(v);

	return 0;

}