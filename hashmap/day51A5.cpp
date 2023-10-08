#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main() {


	vector<int> A = {1, 2, 1, 3, 4, 3};
	int B = 3;

	map<int, int> m;
	vector<int>ans;

	int n = A.size();

	B--;
	int i = 0;
	int j = 0;
	while (j < n) {

		if (j - i < B) {
			m[A[j]]++;
		} else if (j - i == B) {
			m[A[j]]++;
			ans.push_back(m.size());
			m[A[i]]--;
			if (m[A[i]] == 0) {
				m.erase(A[i]);
			}
			i++;
		}
		j++;
	}


	for (auto q : ans) {
		cout << q << " ";
	}


	return 0;
}