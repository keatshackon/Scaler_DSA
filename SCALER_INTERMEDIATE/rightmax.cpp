#include<bits/stdc++.h>
using namespace std;
#define ll long long


int main() {

	vector<int> v = {1, 3, 4, 4, 5, 3, 2, 1};
	vector<int>rm(v.size());

	rm[rm.size() - 1] = v[v.size() - 1];

	j = v.size() - 1;

	for (int i = 0; i < v.size() - 1; i++) {
		if (rm[j - i - 1] > v[i]) {
			rm[i] = rm[i + 1];
		} else {
			rm[i] = v[i];
		}
	}

	for (auto q : rm) {
		cout << q << " ";
	}

	return 0;
}