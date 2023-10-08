#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() {


	vector<int>A = {1, 2, 2, 3, 1};
	int x = 0;

	int n = A.size();

	for (int i = 0; i < n; i++) {
		x ^= A[i];
	}

	cout << x << '\n';

	return 0;
}