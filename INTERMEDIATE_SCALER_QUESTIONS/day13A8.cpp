#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main() {

	vector<vector<int>> v = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};



	for (int i = 0; i < v.size(); i++) {
		for (int j = i; j < v.size(); j++) {
			int temp = v[i][j];
			v[i][j] = v[j][i];
			v[j][i] = temp;
		}
	}

	for (int k = 0; k < v.size(); k++) {
		int i = 0;
		int j = v.size() - 1;
		while (i < j) {
			swap(v[k][i], v[k][j]);
			i++;
			j--;
		}
	}

	for (auto q : v) {
		for (auto w : q) {
			cout << w << " ";
		}
		cout << "\n";
	}

	return 0;
}