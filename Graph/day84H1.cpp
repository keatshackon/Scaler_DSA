#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main() {

	vector<vector<int>> A =  {};
	int n = A.size();


	sort(A.begin(), A.end());


	for (int i = 0; i < n; i++) {
		cout << A[0] << " : " << A[1];
	}



	return 0;
}