#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main() {

	vector<vector<int>> A = {{97, 18, 55, 1, 50, 17, 16, 0, 22, 14},
		{58, 14, 75, 54, 11, 23, 54, 95, 33, 23},
		{73, 11, 2, 80, 6, 43, 67, 82, 73, 4},
		{61, 22, 23, 68, 23, 73, 85, 91, 25, 7},
		{6, 83, 22, 81, 89, 85, 56, 43, 32, 89},
		{0, 6, 1, 69, 86, 7, 64, 5, 90, 37},
		{10, 3, 11, 33, 71, 86, 6, 56, 78, 31},
		{16, 36, 66, 90, 17, 55, 27, 26, 99, 59},
		{67, 18, 65, 68, 87, 3, 28, 52, 9, 70},
		{41, 19, 73, 5, 52, 96, 91, 10, 52, 21}
	};


	for (int i = 0; i < A.size(); i++) {
		for (int j = 0; j < A[i].size(); j++) {
			if (A[i][j] == 0) {
				int x = i;
				int y = j;
				while (y >= 0) {
					A[x][y] = 0;
					y--;
				}

				x = i;
				y = j;
				while (y < A[i].size()) {
					A[x][y] = 0;
					y++;
				}

				x = i;
				y = j;
				while (x < A.size() and y < A[x].size()) {
					A[x][y] = 0;
					x++;
				}

				// x = i;
				// y = j;
				// while (x > 0 and y < A[x - 1].size() <= A[x].size() ) {
				// 	A[x][y] = 0;
				// 	x--;
				// }
			}
		}
	}


	for (auto q : A) {
		for (auto w : q) {
			cout << w << " ";
		}
		cout << "\n";
	}

	return 0;
}