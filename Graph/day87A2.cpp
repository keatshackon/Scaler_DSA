#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main() {

	vector<vector<int>>B {{0 , 50 , 39},
		{ -1 , 0 , 1},
		{ -1 , 10 , 0}
	};


	int n = B.size();

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (B[i][j] == -1) {
				B[i][j] = 1e9;
			}
		}
	}

	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				B[i][j] = min(B[i][j],
				              B[i][k] + B[k][j]);
			}
		}
	}



	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (B[i][j] == 1e9) {
				B[i][j] = -1;
			}
		}
	}

	for (auto q : B) {
		for (auto w : q) {
			cout << w << " ";
		}
		cout << "\n";
	}

	return 0;
}