#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main() {

	vector<int>A = {4, 7, 9};
	vector<int>B = {2, 11, 19};

	int n = A.size();
	int m = B.size();

	vector<int>ans(n + m);


	int i = 0;
	int j = 0;
	int k = 0;

	while (i < n and j < m) {
		if (A[i] < B[j]) {
			ans[k] = A[i];
			k++;
			i++;
		} else {
			ans[k] = B[j];
			j++;
			k++;
		}
	}

	while (i < n) {
		ans[k] = A[i];
		i++;
		k++;
	}

	while (j < m) {
		ans[k] = B[j];
		j++;
		k++;
	}


	for (auto q : ans) {
		cout << q << " ";
	}

	return 0;
}