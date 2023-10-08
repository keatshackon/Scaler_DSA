#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main() {


	int A = 23;

	vector<int> v;


	while (A) {
		v.push_back(A % 10);
		A /= 10;
	}

	int n = v.size();
	reverse(v.begin(), v.end());


	set<int>s;

	for (int i = 0; i < n; i++) {
		int temp = 1;
		for (int j = i; j < n; j++) {
			temp = temp * v[j];
			if (s.find(temp) == s.end()) {
				s.insert(temp);
			} else {
				return 0;
			}
		}
	}

	for (auto q : s) {
		cout << q << " ";
	}

	// return 1;

	return 0;
}