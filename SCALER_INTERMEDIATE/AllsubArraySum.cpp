#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() {

	vector<int> A = {13, 16, 16, 15, 9, 16, 2, 7, 6, 17, 3, 9};


	vector<int>prefix(A.size());
	prefix[0] = A[0];
	for (int i = 1; i < A.size(); i++) {
		prefix[i]  = prefix[i - 1] + A[i];
	}
	int cnt = 0;
	int B = 65;
	for (int i = 0; i < A.size(); i++) {
		for (int j = i; j < A.size(); j++) {
			if (i == 0) {
				if (prefix[j] < B and j % 2 == 1 ) {
					cnt++;
				} else if (prefix[j] > B and j % 2 == 0 ) {
					cnt++;
				}
			} else if ((prefix[j] - prefix[i - 1]) < B and (j - i + 1) % 2 == 0) {
				cnt++;
			} else if ((prefix[j] - prefix[i - 1]) > B and (j - i + 1) % 2 == 1) {
				cnt++;
			}
		}
	}

	cout << cnt;

	return 0;
}

/// done
