#include<bits/stdc++.h>
using namespace std;
#define ll long long


int main() {


	vector<int> A = {1, 2, 2, 1, 1, 0, 0, 1, 1, 1};

	int i = 0;
	int j = i;
	int k = A.size() - 1 ;

	while (j <= k) {
		if (A[j] == 0) {
			swap(A[i], A[j]);
			i++;
			j++;
		} else if (A[j] == 2) {
			swap(A[j], A[k]);
			k--;
		} else {
			j++;
		}
	}

	for (auto q : A) {
		cout << q << " ";
	}

	return 0;
}