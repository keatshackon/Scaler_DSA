#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main() {


	map<int, int> map;
	vector<int>ans;

	vector<int> A = {2, 1, 4, 10};
	vector<int> B = {2, 2, 4};

	int n = A.size();
	int m = B.size();


	for (int i = 0; i < n; i++) {
		map[A[i]]++;
	}

	for (int i = 0; i < m; i++) {
		if (map.count(B[i]) != 0 and map[B[i]] > 0) {
			map[B[i]]--;
			ans.push_back(B[i]);
		}
	}

	for (auto q : ans) {
		cout << q << " ";
	}


	return 0;
}