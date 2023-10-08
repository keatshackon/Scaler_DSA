#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main() {


	vector<vector<int>>A = {
		{1, 3, 5, 7},
		{10, 11, 16, 20},
		{23, 30, 34, 50}
	};

	int B = 34;

	int row = A.size();
	int col = A[0].size();

	int i = 0;
	int j = (row * col) - 1;


	while (i <= j) {
		int m = (i + j) / 2;

		int x = m / col ;
		int y = m % col;

		if (A[x][y] == B) {
			cout << "Found";
			return 0;
		} else if (A[x][y] > B) {
			j = m - 1;
		} else {
			i = m + 1;
		}
	}

	cout << "Not Found\n";


	return 0;
}