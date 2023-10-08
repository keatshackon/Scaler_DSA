#include<bits/stdc++.h>
using namespace std;
#define ll long long



int main() {


	vector<vector<int>>A = {{5, 9, 11},
		{9, 11, 13},
		{10, 12, 15},
		{13, 14, 16},
		{16, 20, 21}
	};

	int B = 12;


	int k = 0;

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (k < B) {
				pq.push(A[i][j]);
				k++;
			} else {
				if (pq.top() < A[i][j]) {
					pq.pop();
					pq.push(A[i][j]);
				}
			}
		}
	}

	if (!pq.empty())
		cout << pq.top();

	return 0;
}