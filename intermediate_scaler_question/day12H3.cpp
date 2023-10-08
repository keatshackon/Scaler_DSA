#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {


	vector<int>ans;
	if (B == 0) {
		for (int i = 0; i < A.size(); i++) {
			ans.push_back(i);
		}
		return ans;
	}
	for (int i = 0; i < A.size(); i++) {
		if ((i - 1) >= 0 and A[i] == A[i - 1]) {
			continue;
		} else if ((i + 1) < A.size() and A[i] == A[i + 1]) {
			continue;
		}
		int j = i - 1;
		int k = i + 1;
		int f = 0;
		int flag = A[i];
		while (j >= 0 and k < A.size() and j >= (i - B) and k <= (i + B) ) {
			if (A[j] == A[k] and A[j] != A[j + 1] and A[k] != A[k - 1]) {
				j--;
				k++;
			} else {
				break;
			}
			f = 1;
		}
		j++;
		if (j == (i - B)  and f == 1) {
			ans.push_back(i);
		}
	}


	for (auto q : ans) cout << q << " ";

	return 0;
}